#!/bin/sh
set -x
rm -rf default_project
cookiecutter .
cd default_project
/bin/sh default_project/pbin/configure-default_project --host-configuration default_project
cd Debug
ninja
ninja ctestverbose
