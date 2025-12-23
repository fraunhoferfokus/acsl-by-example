#!/usr/bin/env python3
import re
import sys
import json
import os.path


def get_example_name(log: str):
    """Extract example name from a [kernel] Parsing ... line."""
    m_file = re.search(
        r'^\[kernel\]\s+Parsing\s+(\S+?\.c)\s*\(with preprocessing\)',
        log,
        re.MULTILINE,
    )
    if not m_file:
        return None

    path = m_file.group(1)          # e.g. "equal_range.c" or "dir/equal_range.c"
    base = os.path.basename(path)   # -> "equal_range.c"
    name, _ = os.path.splitext(base)
    return name                     # -> "equal_range"


def parse_block(b: str, name: str | None):
    # Single "Proved goals" line in this block
    m_pg = re.search(
        r'\[wp\]\s+Proved goals:\s*(\d+)\s*/\s*(\d+)',
        b,
    )
    if not m_pg:
        return None
    proved, total = map(int, m_pg.groups())

    def get_count(pattern, flags=0):
        m = re.search(pattern, b, flags)
        return int(m.group(1)) if m else 0

    term = get_count(r'^\s*Terminating:\s*(\d+)', re.MULTILINE)
    unreach = get_count(r'^\s*Unreachable:\s*(\d+)', re.MULTILINE)
    qed = get_count(r'^\s*Qed:\s*(\d+)', re.MULTILINE)
    alt_ergo = get_count(r'^\s*Alt-Ergo [^:]*:\s*(\d+)', re.MULTILINE)
    cvc5 = get_count(r'^\s*CVC5 [^:]*:\s*(\d+)', re.MULTILINE)
    z3 = get_count(r'^\s*Z3 [^:]*:\s*(\d+)', re.MULTILINE)
    coq = get_count(r'^\s*Coq\b[^:]*:\s*(\d+)', re.MULTILINE)

    return {
        "name": name,
        "proved": proved,
        "total": total,
        "percent": int(100 * (proved / total)),
        "qed": qed,
        "alt_ergo": alt_ergo,
        "cvc5": cvc5,
        "z3": z3,
        "coq": coq,
        "term": term,
        "unreach": unreach,
    }


def parse_log(log: str):
    """Return a list of summaries parsed from the given log text."""
    example_name = get_example_name(log)

    blocks = re.split(
        r'(?=\[rte:annot\]\s+annotating function )',
        log,
    )
    summaries = []
    for b in blocks:
        res = parse_block(b, example_name)
        if res:
            summaries.append(res)
    return summaries


if __name__ == "__main__":
    log = sys.stdin.read()
    summaries = parse_log(log)
    print(json.dumps(summaries, indent=2))
