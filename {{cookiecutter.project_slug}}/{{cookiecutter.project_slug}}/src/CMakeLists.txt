########################################################################
# Copyright {{ current_year }} by the copyright holders
# named in COPYING.md.
#
# Licensed under: {{ cookiecutter.license }}
# See https://spdx.dev or LICENSE.md in this
# project for the license text.
########################################################################

########################################################################
#
# This CMakeLists.txt file exists mostly to list the set of
# application folders.  Each application is in a subfolder of this
# folder.
#
########################################################################
add_subdirectory({{cookiecutter.mainapp}})
