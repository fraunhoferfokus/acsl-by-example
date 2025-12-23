
# Header

def print_report_header() -> None:
    print(
        f"{'':<25} "
        f"{'Proved':>8} "
        f"{'Percent':>8} "
        f"{'Qed':>4} "
        f"{'AE':>4} "
        f"{'C5':>4} "
        f"{'Z3':>4} "
        f"{'Cq':>4} "
        f"{'Terminating':>13} "
        f"{'Unreachable':>13}"
    )

if __name__ == "__main__":
    print_report_header()
