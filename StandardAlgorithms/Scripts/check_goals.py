#!/usr/bin/env python3

"""
Assert the expected outcome of a WP run.

Most sources are expected to prove completely, and `make results` already
shows when one does not.  A *counterexample* is the opposite case: it exists
in order to fail, and nothing in the build notices when it stops failing.

Tutorial/MutatingAndNumeric/Mutating/unchanged.tex rests on exactly that.  It
shows two contracts for the same body, differing only in

    assigns \\nothing;      against      assigns a[0..n-1];

and says of the first: "However, this specification is incorrect."  If a later
Frama-C proved that assigns clause, the section's argument would be wrong and
the build would stay green.

    Usage:  check_goals.py --complete <proof-results.json>
            check_goals.py --unproved <goal> <proof-results.json>

--complete  every goal carries a "valid" verdict
--unproved  every goal is valid except <goal>, which must not be
"""

from pathlib import Path
from sys import argv, exit, stderr
from typing import Dict, List
import json


def goals(path: Path) -> List[Dict]:
    if not path.is_file():
        exit(f"{path}: no such file -- run the corresponding .wp target first")
    return json.loads(path.read_text(encoding="utf-8"))


def unproved(entries: List[Dict]) -> List[str]:
    return [g.get("property", g.get("goal", "?"))
            for g in entries if g.get("verdict") != "valid"]


def main() -> None:
    if len(argv) == 3 and argv[1] == "--complete":
        path = Path(argv[2])
        failed = unproved(goals(path))
        if failed:
            for name in failed:
                print(f"{path}: {name} is not proved", file=stderr)
            exit(f"{path}: expected every goal to be proved")

    elif len(argv) == 4 and argv[1] == "--unproved":
        expected, path = argv[2], Path(argv[3])
        failed = unproved(goals(path))

        if expected not in failed:
            exit(f"{path}: {expected} is proved, but is expected NOT to be.\n"
                 "This is a counterexample; if the prover has caught up with "
                 "it, the surrounding prose needs revisiting.")

        others = [name for name in failed if name != expected]
        if others:
            for name in others:
                print(f"{path}: {name} is not proved", file=stderr)
            exit(f"{path}: only {expected} was expected to be unproved")

    else:
        exit("Usage:  check_goals.py --complete <proof-results.json>\n"
             "        check_goals.py --unproved <goal> <proof-results.json>")


if __name__ == "__main__":
    main()
