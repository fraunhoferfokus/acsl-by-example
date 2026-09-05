#!/usr/bin/env python3

"""Validate Frama-C/WP contradiction-smoke JSON reports.

WP deliberately inverts the pass convention for smoke goals: a valid verdict
means that ``false`` was proved from the specification and is therefore a
failure. This script also rejects reports that provide no evidence that an
external prover was attempted; Qed-only simplification is not a useful smoke
sweep on its own.
"""

from collections import Counter
from pathlib import Path
from sys import argv, stderr
from typing import Dict, Iterable, List, Tuple
import json


class SmokeReportError(ValueError):
    """A smoke report is missing, malformed, or demonstrates a contradiction."""


def _goal_name(entry: Dict) -> str:
    return str(entry.get("property", entry.get("goal", "<unnamed>")))


def _load(path: Path) -> List[Dict]:
    if not path.is_file():
        raise SmokeReportError(f"{path}: no such smoke report")

    try:
        entries = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, UnicodeError, json.JSONDecodeError) as error:
        raise SmokeReportError(f"{path}: invalid JSON: {error}") from error

    if not isinstance(entries, list) or not all(isinstance(e, dict)
                                                for e in entries):
        raise SmokeReportError(f"{path}: expected a JSON array of goal objects")
    return entries


def check_report(path: Path) -> Tuple[int, Counter]:
    """Return smoke-goal count and verdict counts, or raise on a bad report."""

    entries = _load(path)
    if not entries:
        raise SmokeReportError(f"{path}: report contains no WP goals")
    smoke = [entry for entry in entries if entry.get("smoke") is True]

    problems: List[str] = []
    for entry in smoke:
        name = _goal_name(entry)
        verdict = entry.get("verdict")

        if entry.get("passed") is not True or verdict == "valid":
            problems.append(
                f"{path}: {name}: contradiction proved (verdict={verdict!r})")
            continue

        provers = entry.get("provers")
        if not isinstance(provers, list):
            problems.append(f"{path}: {name}: missing prover results")
            continue

        external = [
            prover for prover in provers
            if isinstance(prover, dict) and str(prover.get("prover", "")).split(
                ":", 1)[0].lower() != "qed"
        ]
        if not external:
            problems.append(f"{path}: {name}: no external prover was attempted")

    if problems:
        raise SmokeReportError("\n".join(problems))

    verdicts = Counter(str(entry.get("verdict", "missing")) for entry in smoke)
    return len(smoke), verdicts


def _format_counts(counts: Counter) -> str:
    return ", ".join(f"{name}={counts[name]}" for name in sorted(counts))


def main(paths: Iterable[str]) -> int:
    reports = [Path(name) for name in paths]
    if not reports:
        print("Usage: check_smoke.py <proof-results.json> [...]", file=stderr)
        return 2

    total = 0
    totals: Counter = Counter()
    try:
        for path in reports:
            count, verdicts = check_report(path)
            total += count
            totals.update(verdicts)
            if count:
                print(f"{path}: {count} smoke goals, {_format_counts(verdicts)}")
            else:
                print(f"{path}: no applicable smoke goals")
    except SmokeReportError as error:
        print(error, file=stderr)
        return 1

    if total:
        print(f"No contradiction found in {total} smoke goals "
              f"({_format_counts(totals)}).")
    else:
        print("No applicable smoke goals; no contradiction found.")
    return 0


if __name__ == "__main__":
    raise SystemExit(main(argv[1:]))
