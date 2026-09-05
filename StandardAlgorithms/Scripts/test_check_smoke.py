#!/usr/bin/env python3

"""Unit tests for check_smoke.py."""

from pathlib import Path
from tempfile import TemporaryDirectory
import json
import unittest

from check_smoke import SmokeReportError, check_report
from merge_smoke_reports import MergeError, merge_reports


def goal(*, smoke=True, passed=True, verdict="unknown", external=True):
    provers = [{"prover": "qed", "success": 1}]
    if external:
        provers.append({"prover": "Alt-Ergo:2.6.3", "success": 0})
    return {
        "goal": "typed_f_wp_smoke_default_requires",
        "property": "f_wp_smoke_default_requires",
        "smoke": smoke,
        "passed": passed,
        "verdict": verdict,
        "provers": provers,
    }


class CheckSmokeTest(unittest.TestCase):
    def setUp(self):
        self.temporary = TemporaryDirectory()
        self.path = Path(self.temporary.name) / "report.json"

    def tearDown(self):
        self.temporary.cleanup()

    def write(self, entries):
        self.path.write_text(json.dumps(entries), encoding="utf-8")

    def test_accepts_unproved_smoke_goal(self):
        self.write([goal()])
        count, verdicts = check_report(self.path)
        self.assertEqual(count, 1)
        self.assertEqual(verdicts["unknown"], 1)

    def test_rejects_proved_contradiction(self):
        self.write([goal(passed=False, verdict="valid")])
        with self.assertRaisesRegex(SmokeReportError, "contradiction proved"):
            check_report(self.path)

    def test_accepts_report_without_applicable_smoke_goals(self):
        self.write([goal(smoke=False)])
        count, verdicts = check_report(self.path)
        self.assertEqual(count, 0)
        self.assertFalse(verdicts)

    def test_rejects_empty_report(self):
        self.write([])
        with self.assertRaisesRegex(SmokeReportError, "no WP goals"):
            check_report(self.path)

    def test_rejects_qed_only_report(self):
        self.write([goal(external=False)])
        with self.assertRaisesRegex(SmokeReportError, "no external prover"):
            check_report(self.path)

    def test_rejects_malformed_json(self):
        self.path.write_text("{", encoding="utf-8")
        with self.assertRaisesRegex(SmokeReportError, "invalid JSON"):
            check_report(self.path)


class MergeSmokeReportsTest(unittest.TestCase):
    def test_merges_independent_prover_reports(self):
        with TemporaryDirectory() as temporary:
            root = Path(temporary)
            alt_ergo = root / "alt-ergo.json"
            z3 = root / "z3.json"
            alt_ergo.write_text(json.dumps([goal()]), encoding="utf-8")
            z3.write_text(json.dumps([goal(verdict="timeout")]),
                          encoding="utf-8")
            merged = merge_reports([alt_ergo, z3])
            self.assertEqual(len(merged), 2)

    def test_rejects_empty_input_list(self):
        with self.assertRaisesRegex(MergeError, "no prover reports"):
            merge_reports([])


if __name__ == "__main__":
    unittest.main()
