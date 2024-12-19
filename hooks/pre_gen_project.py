#
# Note: This script was stolen shamelessly from
#           https://github.com/ssciwr/cookiecutter-cpp-project
#       That cookiecutter project is much more sophisticated than
#       this one. You really should look into it.
#
# This script executes before the project is generated from your cookiecutter.
# Details about hooks can be found in the cookiecutter documentation:
# https://cookiecutter.readthedocs.io/en/latest/advanced/hooks.html
#
# An example of a pre-hook would be to validate the provided input for a
# user configuration value and exit with an error upon failure.

import cookiecutter
import sys


# Ensure that the version of cookiecutter is >= 2.1. Unfortunately, we cannot
# use the packaging library here, because we cannot install additional dependencies
# and cookiecutter did not depend on it pre-v2
parts = cookiecutter.__version__.split(".")
if int(parts[0]) < 2 or (int(parts[0]) == 2  and int(parts[1]) < 1):
    sys.stderr.write("This template requires cookiecutter >= 2.1")
    sys.exit(1)


def fail_if(condition, message):
    if condition:
        sys.stderr.write(message + "\n")
        sys.exit(1)

