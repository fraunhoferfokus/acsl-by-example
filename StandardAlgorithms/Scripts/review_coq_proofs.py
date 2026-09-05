#!/usr/bin/env python3
"""Grade the interactive Coq proof scripts of the Frama-C/WP session."""

from __future__ import annotations

import argparse
import concurrent.futures
import os
import re
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass, field
from pathlib import Path
from typing import Iterable, Iterator, Sequence

# Only the region between these two sentences is written by hand.  Why3's Coq
# driver regenerates everything else, which is why a long file says nothing
# about the size of its proof and why 'Require Import Psatz.' has to sit
# inside the proof rather than above it.
PROOF_START = re.compile(r"^Proof\.\s*$", re.MULTILINE)
PROOF_END = re.compile(r"^Qed\.\s*$", re.MULTILINE)

ASSERT = re.compile(r"^assert\s*\(\s*([A-Za-z_][A-Za-z_0-9']*)\s*:")
OPAQUE_NAME = re.compile(r"^[A-Z][0-9]?$")
BULLET = re.compile(r"^[-+*]+\s")
BARE_INTROS = re.compile(r"^\s*intros\.\s*$", re.MULTILINE)
GENERATED_NAME = re.compile(r"\bH[0-9]*\b")
AXIOM_NAME = re.compile(r"^(Q_[A-Za-z_0-9']*)\s*:")
CITED_AXIOM = re.compile(r"\bQ_[A-Za-z_0-9']*")

AUTO_ZARITH = "auto with zarith"


class ProofScriptError(Exception):
    """Raised when a proof script or the Coq toolchain cannot be used."""


# --------------------------------------------------------------------
# Reading a script
# --------------------------------------------------------------------


@dataclass
class Script:
    """One generated .v file, split at the hand-written region."""

    path: Path
    text: str
    body_start: int
    body_end: int

    @property
    def name(self) -> str:
        return self.path.stem.removeprefix("lemma_")

    @property
    def body(self) -> str:
        """The proof, from 'Proof.' through 'Qed.'."""
        return self.text[self.body_start:self.body_end]

    def with_body(self, body: str) -> str:
        """The whole file, with the proof replaced."""
        return self.text[:self.body_start] + body + self.text[self.body_end:]


def read_script(path: Path) -> Script:
    try:
        text = path.read_text(encoding="utf-8")
    except OSError as error:
        raise ProofScriptError(f"cannot read proof script {path}: {error}") from error

    start = PROOF_START.search(text)
    if start is None:
        raise ProofScriptError(f"no 'Proof.' in {path}")
    end = PROOF_END.search(text, start.end())
    if end is None:
        raise ProofScriptError(f"no 'Qed.' after 'Proof.' in {path}")
    return Script(path, text, start.start(), end.end())


def collect_scripts(inputs: Iterable[Path]) -> list[Script]:
    paths: set[Path] = set()
    for entry in inputs:
        if entry.is_dir():
            matches = set(entry.glob("*.v"))
            if not matches:
                raise ProofScriptError(f"no .v files under: {entry}")
            paths.update(matches)
        else:
            paths.add(entry)
    return [read_script(path) for path in sorted(paths)]


# --------------------------------------------------------------------
# Splitting a proof into sentences
#
# Coq ends a sentence with a period followed by whitespace.  Splitting on the
# period alone would cut qualified names such as int.ComputerDivision.Div_bound
# in half, and comments nest, so both need a scanner rather than a regexp.
# --------------------------------------------------------------------


def skip_comment(text: str, index: int) -> int:
    """Return the offset just past the comment opening at index."""
    depth, index = 1, index + 2
    while index < len(text) and depth:
        if text.startswith("(*", index):
            depth, index = depth + 1, index + 2
        elif text.startswith("*)", index):
            depth, index = depth - 1, index + 2
        else:
            index += 1
    return index


def tokens(text: str) -> Iterator[tuple[int, int, str]]:
    """Yield (start, end, kind) for each sentence and each focusing brace."""
    index, size = 0, len(text)
    while index < size:
        if text.startswith("(*", index):
            index = skip_comment(text, index)
        elif text[index].isspace():
            index += 1
        elif text[index] in "{}":
            yield index, index + 1, text[index]
            index += 1
        else:
            start, index = index, index
            while index < size:
                if text.startswith("(*", index):
                    index = skip_comment(text, index)
                    continue
                if text[index] == "." and (index + 1 >= size
                                           or text[index + 1].isspace()):
                    index += 1
                    break
                index += 1
            yield start, index, "sentence"


def strip_comments(text: str) -> str:
    out, index, size = [], 0, len(text)
    while index < size:
        if text.startswith("(*", index):
            index = skip_comment(text, index)
        else:
            out.append(text[index])
            index += 1
    return "".join(out)


def matching_brace(spans: Sequence[tuple[int, int, str]], opening: int) -> int:
    """Index in spans of the '}' closing the '{' at position opening."""
    depth = 0
    for position in range(opening, len(spans)):
        kind = spans[position][2]
        if kind == "{":
            depth += 1
        elif kind == "}":
            depth -= 1
            if depth == 0:
                return position
    raise ProofScriptError("unbalanced braces in proof body")


# --------------------------------------------------------------------
# What an assert looks like, and where it is established
# --------------------------------------------------------------------


@dataclass
class Assertion:
    """An 'assert' in a proof body, and the offset just past its proof."""

    name: str
    start: int
    established: int | None  # None when the shape was not recognised
    form: str


def assertions(body: str) -> list[Assertion]:
    spans = list(tokens(body))
    found: list[Assertion] = []

    for position, (start, end, kind) in enumerate(spans):
        if kind != "sentence":
            continue
        sentence = strip_comments(body[start:end]).strip()
        match = ASSERT.match(sentence)
        if match is None:
            continue
        name = match.group(1)

        # 'assert(N: ...) by tac.' proves N inside the same sentence.
        if re.search(r"\)\s*by\b", sentence, re.DOTALL):
            found.append(Assertion(name, start, end, "by"))
            continue

        # 'assert(N: ...).' followed by a focused '{ ... }' block.
        if position + 1 < len(spans) and spans[position + 1][2] == "{":
            closing = matching_brace(spans, position + 1)
            found.append(Assertion(name, start, spans[closing][1], "brace"))
            continue

        found.append(Assertion(name, start, None, "other"))

    return found


# --------------------------------------------------------------------
# Static measurements
# --------------------------------------------------------------------


@dataclass
class Findings:
    script: Script
    body_lines: int
    comment_lines: int
    opaque: list[str] = field(default_factory=list)
    cited: list[str] = field(default_factory=list)
    autos: int = 0
    mixed_bullets: list[int] = field(default_factory=list)
    generated_names: bool = False
    asserts: list[Assertion] = field(default_factory=list)
    dead: list[str] = field(default_factory=list)
    unprobed: list[str] = field(default_factory=list)
    narrowable: list[int] = field(default_factory=list)
    used_axioms: list[str] = field(default_factory=list)
    probed: bool = False

    @property
    def hidden(self) -> list[str]:
        """Axioms the proof rests on without naming them."""
        return sorted(set(self.used_axioms) - set(self.cited))


def bullet_depths(body: str) -> list[int]:
    """Line numbers where one nesting depth uses more than one bullet mark."""
    seen: dict[int, set[str]] = {}
    offenders: list[int] = []
    for number, line in enumerate(strip_comments(body).splitlines(), 1):
        stripped = line.lstrip()
        if not BULLET.match(stripped):
            continue
        indent = len(line) - len(stripped)
        mark = stripped[0]
        marks = seen.setdefault(indent, set())
        marks.add(mark)
        if len(marks) > 1:
            offenders.append(number)
    return offenders


def uses_generated_name(body: str) -> bool:
    """True when a bare 'intros.' is followed by a reference to H, H0, ...

    Such a name is chosen by Coq, not by the author, so the step it feeds can
    start referring to a different hypothesis without the script changing.
    """
    text = strip_comments(body)
    if not BARE_INTROS.search(text):
        return False
    referenced = set(GENERATED_NAME.findall(text))
    if not referenced:
        return False
    introduced = set()
    for start, end, kind in tokens(text):
        sentence = text[start:end]
        if re.match(r"^\s*(intros|assert|destruct|rename)\b", sentence):
            if re.search(r"\b(as|into)\b|intros\s+\S", sentence):
                introduced.update(GENERATED_NAME.findall(sentence))
    return bool(referenced - introduced)


def measure(script: Script) -> Findings:
    body = script.body
    clean = strip_comments(body)
    found = assertions(body)
    return Findings(
        script=script,
        body_lines=len(body.splitlines()),
        comment_lines=body.count("(*"),
        opaque=[a.name for a in found if OPAQUE_NAME.match(a.name)],
        cited=sorted(set(CITED_AXIOM.findall(clean))),
        autos=clean.count(AUTO_ZARITH),
        mixed_bullets=bullet_depths(body),
        generated_names=uses_generated_name(body),
        asserts=found,
    )


# --------------------------------------------------------------------
# Probes: they recompile a modified copy and ask whether it still proves
# --------------------------------------------------------------------


def coq_include() -> list[str]:
    why3 = shutil.which("why3")
    if why3 is None:
        raise ProofScriptError("why3 is not on PATH, so -R for Why3 cannot be derived")
    library = Path(why3).resolve().parent.parent / "lib" / "why3" / "coq"
    if not library.is_dir():
        raise ProofScriptError(f"no Why3 Coq library at {library}")
    if shutil.which("coqtop") is None:
        raise ProofScriptError("coqtop is not on PATH")
    return ["-R", str(library), "Why3"]


def proves(text: str, include: Sequence[str], workdir: Path) -> bool:
    """True when this file still closes its goal."""
    with tempfile.NamedTemporaryFile(mode="w", suffix=".v", dir=workdir,
                                     delete=False, encoding="utf-8") as stream:
        stream.write(text)
        candidate = Path(stream.name)
    try:
        done = subprocess.run(["coqtop", "-batch", *include, "-l", str(candidate)],
                              cwd=workdir, capture_output=True, text=True)
        return done.returncode == 0
    finally:
        candidate.unlink(missing_ok=True)


def probe_dead(script: Script, found: Findings, include: Sequence[str],
               workdir: Path) -> None:
    """An assert nothing uses survives being cleared the moment it is proved."""
    body = script.body
    for assertion in found.asserts:
        if assertion.established is None:
            found.unprobed.append(assertion.name)
            continue
        cut = assertion.established
        probe = body[:cut] + f"\n clear {assertion.name}.\n" + body[cut:]
        if proves(script.with_body(probe), include, workdir):
            found.dead.append(assertion.name)


def probe_auto(script: Script, found: Findings, include: Sequence[str],
               workdir: Path) -> None:
    """Report each 'auto with zarith' that lia alone would close."""
    body = script.body
    offset, occurrence = 0, 0
    while True:
        at = body.find(AUTO_ZARITH, offset)
        if at < 0:
            break
        occurrence += 1
        probe = body[:at] + "lia" + body[at + len(AUTO_ZARITH):]
        if proves(script.with_body(probe), include, workdir):
            found.narrowable.append(occurrence)
        offset = at + len(AUTO_ZARITH)


def probe_axioms(script: Script, found: Findings, include: Sequence[str],
                 workdir: Path) -> None:
    """Record the sibling lemmas the finished proof term actually rests on."""
    with tempfile.NamedTemporaryFile(mode="w", suffix=".v", dir=workdir,
                                     delete=False, encoding="utf-8") as stream:
        stream.write(script.text + "\nPrint Assumptions wp_goal.\n")
        candidate = Path(stream.name)
    try:
        done = subprocess.run(["coqtop", "-batch", *include, "-l", str(candidate)],
                              cwd=workdir, capture_output=True, text=True)
        for line in (done.stdout + done.stderr).splitlines():
            match = AXIOM_NAME.match(line)
            if match:
                found.used_axioms.append(match.group(1))
    finally:
        candidate.unlink(missing_ok=True)


def run_probes(script: Script, found: Findings, probes: set[str],
               include: Sequence[str]) -> Findings:
    with tempfile.TemporaryDirectory(prefix="review-coq-") as directory:
        workdir = Path(directory)
        if not proves(script.text, include, workdir):
            raise ProofScriptError(
                f"{script.path.name} does not replay as it stands; "
                "probe results would be meaningless")
        if "dead" in probes:
            probe_dead(script, found, include, workdir)
        if "auto" in probes:
            probe_auto(script, found, include, workdir)
        if "axioms" in probes:
            probe_axioms(script, found, include, workdir)
    found.probed = True
    return found


# --------------------------------------------------------------------
# Reporting
# --------------------------------------------------------------------


def concerns(found: Findings) -> list[str]:
    notes: list[str] = []
    if found.dead:
        notes.append("dead step: " + ", ".join(found.dead))
    if found.generated_names:
        notes.append("leans on a Coq-generated name")
    if found.hidden:
        notes.append("unnamed axiom: " + ", ".join(found.hidden))
    if found.opaque:
        notes.append("opaque name: " + ", ".join(sorted(set(found.opaque))))
    if found.mixed_bullets:
        notes.append(f"mixed bullets at line {found.mixed_bullets[0]}")
    if found.narrowable:
        notes.append(f"{len(found.narrowable)} of {found.autos} "
                     "'auto with zarith' would close with lia")
    return notes


def weight(found: Findings) -> tuple:
    return (len(found.dead), found.generated_names, len(found.hidden),
            len(set(found.opaque)), len(found.narrowable),
            bool(found.mixed_bullets))


def report(results: Sequence[Findings], probes: set[str]) -> None:
    print(f"{len(results)} interactive proof scripts\n")
    print(f"{'script':<42}{'body':>5}{'cmt':>5}{'asrt':>5}{'axiom':>6}{'auto':>5}")
    for found in sorted(results, key=weight, reverse=True):
        print(f"{found.script.name:<42}{found.body_lines:>5}"
              f"{found.comment_lines:>5}{len(found.asserts):>5}"
              f"{len(found.cited):>6}{found.autos:>5}")

    print("\nfindings, worst first:")
    flagged = 0
    for found in sorted(results, key=weight, reverse=True):
        notes = concerns(found)
        if not notes:
            continue
        flagged += 1
        print(f"  {found.script.name}")
        for note in notes:
            print(f"      {note}")
    if not flagged:
        print("  (none)")

    unprobed = sorted(name for found in results for name in found.unprobed)
    if unprobed:
        print(f"\n{len(unprobed)} assert(s) in an unrecognised shape, not probed: "
              + ", ".join(unprobed))

    if "axioms" in probes:
        gaps = sum(len(found.hidden) for found in results)
        print(f"\nsibling lemmas used but never named in the proof text: {gaps}")
        print("  (a proof that names what it uses stays valid when lemma scope "
              "changes;\n   one that does not can break with no edit to either file)")


def parse_args() -> argparse.Namespace:
    default = Path(__file__).resolve().parent.parent / "Session" / "interactive"
    parser = argparse.ArgumentParser(
        description=("Measure the hand-written region of Frama-C/WP's Coq proof "
                     "scripts: dead steps, over-broad automation, reliance on "
                     "Coq-chosen names, and the sibling lemmas each proof uses."))
    parser.add_argument("inputs", metavar="PATH", type=Path, nargs="*",
                        default=[default],
                        help="a .v script or a directory of them "
                        f"(default: {default})")
    parser.add_argument("--probe", choices=["dead", "auto", "axioms", "all"],
                        action="append", default=[],
                        help="run a probe; each recompiles the script once per "
                        "candidate, so this is minutes rather than seconds")
    parser.add_argument("--jobs", type=int, default=os.cpu_count() or 1,
                        help="scripts to probe in parallel (default: all cores)")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    probes = set(args.probe)
    if "all" in probes:
        probes = {"dead", "auto", "axioms"}

    try:
        scripts = collect_scripts(args.inputs)
        results = [measure(script) for script in scripts]
        if probes:
            include = coq_include()
            with concurrent.futures.ThreadPoolExecutor(args.jobs) as pool:
                results = list(
                    pool.map(lambda pair: run_probes(pair[0], pair[1], probes, include),
                             zip(scripts, results)))
    except ProofScriptError as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    report(results, probes)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
