#!/usr/bin/env python3

"""Merge the JSON arrays from independent WP smoke-prover runs."""

from pathlib import Path
from sys import argv, stderr
from typing import Dict, Iterable, List
import json


class MergeError(ValueError):
    """An input report cannot be merged."""


def merge_reports(paths: Iterable[Path]) -> List[Dict]:
    reports = list(paths)
    if not reports:
        raise MergeError("no prover reports to merge")

    merged: List[Dict] = []
    for path in reports:
        try:
            entries = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, UnicodeError, json.JSONDecodeError) as error:
            raise MergeError(f"{path}: invalid JSON: {error}") from error
        if not isinstance(entries, list) or not all(
                isinstance(entry, dict) for entry in entries):
            raise MergeError(f"{path}: expected a JSON array of goal objects")
        merged.extend(entries)
    return merged


def main(arguments: List[str]) -> int:
    if len(arguments) < 2:
        print("Usage: merge_smoke_reports.py <output.json> <input.json> [...]",
              file=stderr)
        return 2

    output = Path(arguments[0])
    try:
        entries = merge_reports(Path(name) for name in arguments[1:])
        output.write_text(json.dumps(entries, separators=(",", ":")),
                          encoding="utf-8")
    except (MergeError, OSError) as error:
        print(error, file=stderr)
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main(argv[1:]))
