#!/usr/bin/env python3

from sys import argv, exit
from script_functions import report_add_line, count_pattern, create_report, get_valid_pattern
import os
import subprocess
import re
##########################################################################

if len(argv) < 5:
    exit('Atleast one prover is needed as argument')

example = argv[1]

prover_list = argv[2:]
prover_list = [
    'coq' if prover == 'native:coq' else prover for prover in prover_list
]
report_list = ['qed', 'alt-ergo', 'cvc4', 'coq', 'cvc3', 'z3']

########################################################################


# Creates options based on the last and
def create_options(old_obligations_set, new_obligations_set):
    #print("Old:")
    #print(old_obligations_set)
    #print("New:")
    #print(new_obligations_set)
    option = ''
    if bool(old_obligations_set):
        set_of_properties = old_obligations_set.intersection(
            new_obligations_set)
    else:
        set_of_properties = new_obligations_set
    for properties in set_of_properties:
        option += '-wp-prop=' + properties + ' '
    return option


def split_tupled_set(tupled_set):
    new_set = set()
    for item in tupled_set:
        new_set.add(item[1])
    return new_set


# Uses the data_string and one of the
# propery classes (invariant, assert, lemma, ensures, requires)
def get_failed_obligations(data_string, property_class):

    failed = ''

    if property_class == 'invariant':
        failed = re.findall(
            r'.*invariant\_([\w]*\_*[a-zA-Z]+)\_*[0-9]*\_*(preserved|established).* \: (Timeout|Unknown).*',
            data_string,
            flags=re.MULTILINE)
        failed = [(t[1], t[0]) for t in failed]

    elif property_class in ['assert', 'lemma', 'ensures', 'requires']:
        failed = re.findall(
            r'.*(' + property_class +
            ')\_(rte|[a-zA-Z0-9]+\_?[a-zA-Z]+)(|\_[0-9]*_part[0-9]*|\_part[0-9]*).* \: (Timeout|Unknown).*',
            data_string,
            flags=re.MULTILINE)
    else:
        pass
    return set(failed)


def collect_failed_obligations(data):
    invariants = get_failed_obligations(data, 'invariant')
    lemmas = get_failed_obligations(data, 'lemma')
    ensures = get_failed_obligations(data, 'ensures')
    requires = get_failed_obligations(data, 'requires')
    assertion = get_failed_obligations(data, 'assert')

    all_failed = invariants.union(lemmas, ensures, requires, assertion)
    all_failed = split_tupled_set(all_failed)

    #print(all_failed_obligations)
    return all_failed


def qreport_set(already_verified, data, pattern):
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
    """

    new_verified = set(pattern.findall(data))
    new_verified = new_verified.difference(already_verified)
    all_verified = global_set.union(new_verified)

    return len(new_verified), all_verified


################# Main ###################################################################

if __name__ == '__main__':

    goal_count = 0
    valid = 0
    valid_list = {}
    for element in report_list:
        valid_list[element] = 0
    invalid = 0
    percent = 0
    global_set = set()

    ################### Prover Part ##########################
    wp_options = ''
    old_obligations = set()
    d = dict(os.environ)
    for prover in prover_list:
        # We need to change the environment variable for the additional wp options
        d['EXTRA_PROP'] = wp_options
        raw_data = subprocess.check_output(['make ' + example + '.' + prover],
                                           shell=True,
                                           env=d)
        raw_data = raw_data.decode('utf-8')

        if valid == 0:
            valid_pattern = get_valid_pattern('qed')
            valid_list['qed'], global_set = qreport_set(
                global_set, raw_data, valid_pattern)
            valid = valid + valid_list['qed']

        valid_pattern = get_valid_pattern(prover)
        valid_list[prover], global_set = qreport_set(global_set, raw_data,
                                                     valid_pattern)
        valid = valid + valid_list[prover]
        if wp_options == '':
            goal_count = count_pattern(raw_data, r'^.* Goal .*')

        new_obligations = collect_failed_obligations(raw_data)

        wp_options = create_options(old_obligations, new_obligations)

        old_obligations = new_obligations

        ######### Logging ##########################
        split_data = sorted(raw_data.split("\n"))
        with open(example + ".wp/" + example + ".qlog", "a+") as log_file:
            log_file.write("######### Start " + prover + " #########\n")
            for line in split_data:
                log_file.write(line + "\n")
            log_file.write("\n" + str(new_obligations) + "\n\n")
            log_file.write("Options:" + "\n")
            log_file.write(str(wp_options) + "\n")
            log_file.write(str(valid_list) + "\n")
            log_file.write("Goals: " + str(goal_count) + "\n")
            log_file.write("Valid Goals: " + str(valid) + "\n")
            log_file.write("######### End " + prover + " #########\n\n")
        log_file.close()
        # break if no options are left
        if wp_options == '':
            break
################# Report Part ##########################
    create_report(example, 'qreport', valid_list, report_list, goal_count,
                  valid)
