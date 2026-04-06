
import sys
import json

data = sys.stdin.read()
summaries = json.loads(data)

# Data lines
for i, s in enumerate(summaries, 1):
    label = s["name"] if s["name"] else f"Block {i}"
    proved_vs_total = f"{s['proved']}/{s['total']}"
    print(
        f"{label:<25} "
        f"{proved_vs_total:>8} "
        f"{f'{s['percent']}%':>8} "
        f"{s['term']:>5} "
        f"{s['unreach']:>5} "
        f"{s['qed']:>4} "
        f"{s['alt_ergo']:>4} "
        f"{s['cvc5']:>4} "
        f"{s['z3']:>4} "
        f"{s['coq']:>4} "
    )

