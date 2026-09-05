#!/usr/bin/env python3
"""Record the toolchain that actually proved the results.

Results/*.json states how many goals each prover discharged, but not which
version of it did so, and the WP reports that do say are build artifacts:
*.wp/ and Session/cache/ are both gitignored. So a release could -- and once
did -- ship a prover table naming a version that ran nothing.

This script reads the prover version strings out of every WP report and writes
Results/toolchain.json, which is committed. GitHub/Scripts/render.py checks the
prover table of the newest history file against it.
"""

from __future__ import annotations

import argparse
import json
from pathlib import Path
import re
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent

# WP names a prover "Name:version" in a report, and "qed" for the goals it
# discharged itself, which belongs to no external tool.
QED = 'qed'

VERSION = re.compile(r'\d+(?:\.\d+)+')
FRAMA_C_VERSION = re.compile(r'^(\S+)\s*(?:\((.*)\))?\s*$')


class Failure(Exception):
    """Something the caller must fix, reported without a traceback."""


def read_stamp(path: Path) -> dict:
    if not path.is_file():
        raise Failure(
            "{} does not exist.\n"
            "It is a product of the proof runs: run 'make results' here."
            .format(path))

    stamp = json.loads(path.read_text(encoding='utf-8'))
    missing = [key for key in ('frama_c', 'why3', 'prover_executables')
               if key not in stamp]
    if missing:
        raise Failure(
            "{} names no {}.\n"
            "It was written by an older wp_toolchain_stamp.py; "
            "run 'make results' here to refresh it."
            .format(path, ' and no '.join(missing)))
    return stamp


def reports(root: Path) -> list[Path]:
    """Every ordinary WP report under `root`, smoke runs excluded.

    Smoke reports invert the meaning of success and are never published, so
    they say nothing about the numbers the report prints.
    """
    found = sorted(path for path in root.glob('**/*.wp/proof-results.json')
                   if not any(part.endswith('.smoke.wp')
                              for part in path.parts))
    if not found:
        raise Failure(
            "no WP reports under {}.\n"
            "They are products of the proof runs: run 'make results' here."
            .format(root))
    return found


def observed_provers(paths: list[Path]) -> dict[str, dict]:
    """Prover name -> {versions seen, goals discharged}.

    Every attempt is read, not only the successful ones: a prover that was
    asked and failed still names its version, and a version that appears
    nowhere at all is the very thing worth noticing.
    """
    seen: dict[str, dict] = {}
    for path in paths:
        for goal in json.loads(path.read_text(encoding='utf-8')):
            for attempt in goal.get('provers', []):
                name = attempt.get('prover', '')
                if name == QED or ':' not in name:
                    continue
                name, _, version = name.partition(':')
                entry = seen.setdefault(name, {'versions': {}, 'goals': 0})
                entry['versions'].setdefault(version, []).append(path)
                if attempt.get('success'):
                    entry['goals'] += 1
    return seen


def one_version(name: str, versions: dict[str, list[Path]]) -> str:
    """The single version of `name` the reports agree on."""
    if len(versions) == 1:
        return next(iter(versions))

    lines = ["{} appears with more than one version:".format(name)]
    for version, paths in sorted(versions.items()):
        lines.append("  {:10} in {} report(s), e.g. {}".format(
            version or '(none)', len(paths), paths[0]))
    lines.append("The results were not all produced by the same toolchain; "
                 "re-run 'make results'.")
    raise Failure('\n'.join(lines))


def probe(executable: str) -> str:
    """The version `executable --version` reports, for a prover WP cannot name.

    Why3 leaves the version empty when it cannot parse a prover's banner --
    cvc5 prints 'cvc5 1.3.4 [git ... ]', which it does not recognise.
    """
    completed = subprocess.run(
        [executable, '--version'],
        stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    match = VERSION.search(completed.stdout)
    if completed.returncode != 0 or not match:
        raise Failure(
            "WP recorded no version for this prover, and '{} --version' does "
            "not state one either:\n{}".format(executable, completed.stdout))
    return match.group(0)


def executable_of(stamp: dict, name: str) -> str:
    """The path the stamp resolved for prover `name`, if it resolved one."""
    for entry in stamp.get('prover_executables', []):
        command = entry.get('command') or ['']
        if command[0].lower() == name.lower() and entry.get('resolved'):
            return entry['resolved']
    raise Failure(
        "WP recorded no version for {}, and the toolchain stamp resolved no "
        "executable of that name to ask.".format(name))


def collect(root: Path, stamp_path: Path) -> dict:
    stamp = read_stamp(stamp_path)

    match = FRAMA_C_VERSION.match(stamp['frama_c']['version'])
    if not match:
        raise Failure("cannot read a version from Frama-C's {!r}".format(
            stamp['frama_c']['version']))
    frama_c = {'version': match.group(1), 'codename': match.group(2) or ''}

    why3 = VERSION.search(stamp['why3']['version'])
    if not why3:
        raise Failure("cannot read a version from Why3's {!r}".format(
            stamp['why3']['version']))

    paths = reports(root)
    provers = {}
    for name, entry in sorted(observed_provers(paths).items()):
        version = one_version(name, entry['versions'])
        record = {'version': version, 'goals': entry['goals']}
        if not version:
            # Recorded as reported, so that a reader of the check's output can
            # see that the version rests on the binary rather than on WP.
            executable = executable_of(stamp, name)
            record['version'] = probe(executable)
            record['wp_version'] = ''
            record['source'] = '{} --version'.format(executable)
        provers[name] = record

    return {
        'schema': 1,
        'frama_c': frama_c,
        'why3': why3.group(0),
        'provers': provers,
        'reports': len(paths),
    }


def write_if_changed(output: Path, record: dict) -> bool:
    data = json.dumps(record, indent=2, sort_keys=True) + '\n'
    if output.is_file() and output.read_text(encoding='utf-8') == data:
        return False
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(data, encoding='utf-8')
    return True


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output', type=Path,
                        default=ROOT / 'Results' / 'toolchain.json')
    parser.add_argument('--root', type=Path, default=ROOT,
                        help="directory to search for WP reports")
    parser.add_argument('--stamp', type=Path,
                        default=ROOT / 'Session' / 'cache'
                        / 'wp-toolchain.stamp')
    args = parser.parse_args()

    try:
        record = collect(args.root, args.stamp)
    except Failure as failure:
        print("collect_toolchain: {}".format(failure), file=sys.stderr)
        return 1

    if write_if_changed(args.output, record):
        print("wrote {}".format(args.output))
    return 0


if __name__ == '__main__':
    sys.exit(main())
