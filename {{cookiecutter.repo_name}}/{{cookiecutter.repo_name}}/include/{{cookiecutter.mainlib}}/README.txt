########################################################################
# Copyright {{ current_year }} by the copyright holders
# named in COPYING.md.
#
# Licensed under: {{ cookiecutter.license }}
# See https://spdx.dev or LICENSE.md in this
# project for the license text.
########################################################################

This folder contains exported include files.  This folder will be
copied to ${CMAKE_INSTALL_PREFIX}/include at install time.  Programs
can include a file mumble.hpp in this folder by including:

#include "{{cookiecutter.mainlib}}/mumble.hpp"

Programs in the project can include files in the same way, as
this folder is in the include path.

