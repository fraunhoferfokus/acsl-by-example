import re


# Appends a line to a file
def report_add_line(fname, line):
    with open("../../Results/" + fname, "a") as report:
        report.write(line + "\n")
    report.close()


def count_pattern(string, pattern):
    result = re.findall(pattern, string, flags=re.MULTILINE)
    return len(result)


def get_valid_pattern(prover):
    if prover == 'coq':
        pattern = re.compile(r'(?i)^.*' + prover +
                             '.*native.* (Goal .*\: Valid)',
                             flags=re.MULTILINE)
    else:
        pattern = re.compile(r'(?i)^.*' + prover + '.* (Goal .*\: Valid)',
                             flags=re.MULTILINE)
    return pattern


#Create Reportfile
def create_report(example, report_type, valid_list, report_list, goal_count,
                  valid):
    invalid = goal_count - valid
    percent = 100 * (valid / goal_count)

    report_add_line(example + '.' + report_type, "example='" + example + "'")
    report_add_line(example + '.' + report_type,
                    "goal_count='" + str(goal_count) + "'")
    report_add_line(example + '.' + report_type, "valid='" + str(valid) + "'")
    for prover in report_list:
        if prover == 'alt-ergo':
            report_add_line(
                example + '.' + report_type,
                "valid_alt_ergo" + "='" + str(valid_list[prover]) + "'")
        else:
            report_add_line(
                example + '.' + report_type,
                "valid_" + prover + "='" + str(valid_list[prover]) + "'")
    report_add_line(example + '.' + report_type,
                    "invalid='" + str(invalid) + "'")
    report_add_line(example + '.' + report_type,
                    "percent='" + str(int(percent)) + "'")
