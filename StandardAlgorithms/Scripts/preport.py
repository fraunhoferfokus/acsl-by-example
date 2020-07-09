#!/usr/bin/env python3

from sys import argv, exit
from script_functions import report_add_line, count_pattern, create_report, get_valid_pattern
import os
import subprocess
import re
##########################################################################

if len(argv) < 5:
    exit("Atleast one prover is needed as argument")

example = argv[1]
cmd = argv[2]
sec = argv[3]

prover_list = argv[4:]
# replace native:coq with coq in the prover_list
prover_list = [
    'coq' if prover == 'native:coq' else prover for prover in prover_list
]
report_list = ['qed', 'alt-ergo', 'cvc4', 'coq', 'cvc3', 'z3']

########################################################################


def preport_set(example, prover, already_verified, data):
    """ Keeps track of the already proven goals to get the correct overall valid count

    Parameters
    ----------
    already_verified: set of already verified goals
    data:             string containing the verification results
    pattern:          pattern string that specifies the goals
    
    Return Values:
    -------------

    len(new_verified): Number of valid goals that were not verified before
    all_verified:      Set of all verified goals taking the new data into consideration
    len(valid_global): Number of all valid goals in the data string

    """
    valid_pattern = get_valid_pattern(prover)
    new_verified = set(valid_pattern.findall(data))
    valid_global = new_verified.difference(global_set)

    all_verified = global_set.union(new_verified)
    if prover == 'coq':
        all_file = set(
            re.findall(r'(?i)^.*' + prover + '.*native.*Goal ([\w]*) \: Valid',
                       raw_data,
                       flags=re.MULTILINE))
    else:
        all_file = set(
            re.findall(r'(?i)^.*' + prover + '.*Goal ([\w]*) \: Valid',
                       raw_data,
                       flags=re.MULTILINE))
    for goal in sorted(all_file):
        report_add_line(example + '.all', prover + ' : ' + goal)

    return len(new_verified), all_verified, len(valid_global)


if __name__ == '__main__':

    goal_count = 0
    valid = 0
    valid_list = {}
    for element in report_list:
        valid_list[element] = 0
    invalid = 0
    percent = 0
    global_set = set()
    valid_global = 0

    ############### Prover Part ##########################
    old_obligations = set()
    for prover in prover_list:
        raw_data = subprocess.check_output(['make ' + example + '.' + prover],
                                           shell=True)
        raw_data = raw_data.decode("utf-8")
        # qed handling
        if valid == 0:
            valid_list['qed'], global_set, valid_global = preport_set(
                example, 'qed', global_set, raw_data)
            valid = valid + valid_global

        valid_list[prover], global_set, valid_global = preport_set(
            example, prover, global_set, raw_data)
        valid = valid + valid_global
        # ensure that the goal count is only calculated once
        if valid > goal_count:
            goal_count = count_pattern(raw_data, r'^.* Goal .*')

######### Output for bugfixing #######################################
        split_data = sorted(raw_data.split("\n"))
        with open(example + ".wp/" + example + ".plog", "a+") as log_file:
            log_file.write("######### Start " + prover + " #########\n")
            for line in split_data:
                log_file.write(line + "\n")
            log_file.write("\n" + str(valid_list) + "\n")
            log_file.write("Goals: " + str(goal_count) + "\n")
            log_file.write("Valid Goals: " + str(valid) + "\n")
            log_file.write("######### End " + prover + " #########\n\n")
        log_file.close()

##################### Report Part ##########################
    create_report(example, 'preport', valid_list, report_list, goal_count,
                  valid, cmd, sec)
