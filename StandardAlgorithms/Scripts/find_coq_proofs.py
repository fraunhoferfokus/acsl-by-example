#!/usr/bin/env python3
"""List proof obligations discharged by Coq in Frama-C/WP JSON reports."""

from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path
from typing import Any, Iterable


class ProofReportError(Exception):
    """Raised when a WP proof report is missing or malformed."""


def algorithm_name(report_path: Path) -> str:
    directory = report_path.parent.name
    if not directory.endswith(".wp"):
        raise ProofReportError(
            f"report is not inside a .wp directory: {report_path}"
        )
    return directory.removesuffix(".wp")


def load_report(report_path: Path) -> list[Any]:
    try:
        with report_path.open(encoding="utf-8") as stream:
            report = json.load(stream)
    except FileNotFoundError as error:
        raise ProofReportError(f"missing proof report: {report_path}") from error
    except json.JSONDecodeError as error:
        raise ProofReportError(
            f"invalid JSON in proof report {report_path}: {error}"
        ) from error
    except OSError as error:
        raise ProofReportError(f"cannot read proof report {report_path}: {error}") from error

    if not isinstance(report, list):
        raise ProofReportError(
            f"expected a JSON array in proof report: {report_path}"
        )
    return report


def coq_obligations(report_path: Path) -> set[tuple[str, str]]:
    algorithm = algorithm_name(report_path)
    obligations: set[tuple[str, str]] = set()

    for entry in load_report(report_path):
        if not isinstance(entry, dict):
            raise ProofReportError(
                f"expected goal objects in proof report: {report_path}"
            )

        provers = entry.get("provers", [])
        if not isinstance(provers, list):
            raise ProofReportError(
                f"expected a prover array in proof report: {report_path}"
            )

        for prover in provers:
            if not isinstance(prover, dict):
                raise ProofReportError(
                    f"expected prover objects in proof report: {report_path}"
                )

            name = prover.get("prover", "")
            success = prover.get("success", 0)
            is_success = (
                isinstance(name, str)
                and name.casefold().startswith("coq")
                and isinstance(success, (int, float))
                and success > 0
            )
            if not is_success:
                continue

            goal = entry.get("goal")
            if not isinstance(goal, str) or not goal:
                raise ProofReportError(
                    f"Coq success has no goal name in proof report: {report_path}"
                )
            obligations.add((algorithm, goal))

    return obligations


def collect_obligations(report_paths: Iterable[Path]) -> list[tuple[str, str]]:
    obligations: set[tuple[str, str]] = set()
    for report_path in report_paths:
        obligations.update(coq_obligations(report_path))
    return sorted(obligations)


def expand_report_paths(inputs: Iterable[Path]) -> list[Path]:
    report_paths: set[Path] = set()
    for input_path in inputs:
        if input_path.is_dir():
            matches = {
                path
                for path in input_path.rglob("proof-results.json")
                if path.parent.name.endswith(".wp")
            }
            if not matches:
                raise ProofReportError(
                    f"no .wp/proof-results.json files found under: {input_path}"
                )
            report_paths.update(matches)
        else:
            report_paths.add(input_path)
    return sorted(report_paths)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "List algorithm/proof-obligation pairs successfully discharged by "
            "Coq in Frama-C/WP JSON reports."
        )
    )
    parser.add_argument(
        "inputs",
        metavar="PATH",
        type=Path,
        nargs="*",
        default=[Path(".")],
        help=(
            "a .wp/proof-results.json file or a directory to search recursively "
            "(default: current directory)"
        ),
    )
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    try:
        report_paths = expand_report_paths(args.inputs)
        obligations = collect_obligations(report_paths)
    except ProofReportError as error:
        print(f"error: {error}", file=sys.stderr)
        return 1

    print("Coq-discharged proof obligations:")
    if obligations:
        for algorithm, goal in obligations:
            print(f"  {algorithm}: {goal}")
    else:
        print("  (none)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
