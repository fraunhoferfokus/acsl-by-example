#!/usr/bin/env python3
import sys
import json


def shquote(value):
    s = str(value)
    # Basic quoting so values are safe in a shell.
    return "'" + s.replace("'", "'\"'\"'") + "'"


def main():
    data = json.load(sys.stdin)

    for item in data:
        print(f"example={shquote(item.get('name', ''))}")
        print(f"goal_count={shquote(item.get('total', ''))}")
        print(f"valid={shquote(item.get('proved', ''))}")
        print(f"valid_qed={shquote(item.get('qed', ''))}")
        print(f"valid_alt_ergo={shquote(item.get('alt_ergo', ''))}")
        print(f"valid_cvc5={shquote(item.get('cvc5', ''))}")
        print(f"valid_z3={shquote(item.get('z3', ''))}")
        print(f"term={shquote(item.get('term', ''))}")
        print(f"unreach={shquote(item.get('unreach', ''))}")
        print(f"percent={shquote(item.get('percent', ''))}")
        print()  # blank line between entries


if __name__ == "__main__":
    main()
