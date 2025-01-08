########################################################################
# Copyright {{ current_year }} by the copyright holders
# named in COPYING.md.
#
# Licensed under: {{ cookiecutter.license }}
# See https://spdx.dev or LICENSE.md in this
# project for the license text.
########################################################################

cmake_minimum_required (VERSION 3.9)
project ({{cookiecutter.project_slug}}
         LANGUAGES C CXX
         VERSION 0.0.1)

option(USE_BOOST "Use the boost library." OFF)
option(BUILD_TESTING "Build the tests." ON)
cmake_policy(SET CMP0135 NEW)

########################################################################
#
# definitions.
#
########################################################################
set(PROJECT_SLUG "{{ cookiecutter.project_slug|upper|replace("-","_") }}")
set(PROJECT_RESOURCES_DIR "${PROJECT_SOURCE_DIR}/../resources")

########################################################################
#
# Configuration variables:
#     o for C++ consumption.  Use {{cookiecutter.project_slug}}
#       for file names and @PROJECT_SLUG@ for C++ identifiers in this
#       file.
{%- if cookiecutter.doxygen == "Yes" %}
#     o for Doxygen.
{%- endif %}
{%- if cookiecutter.readthedocs == "Yes" %}
#     o for sphinx.
{%- endif %}
#
########################################################################
#
# C++ configuration include file.
#
configure_file (
  "${PROJECT_SOURCE_DIR}/include/{{cookiecutter.project_slug}}/{{cookiecutter.project_slug}}-config.h.in"
  "${PROJECT_BINARY_DIR}/include/{{cookiecutter.project_slug}}/{{cookiecutter.project_slug}}-config.h"
  )

{%- if cookiecutter.doxygen == "Yes" %}
#
# Doxygen configure file and target.
#
configure_file (
  "${PROJECT_SOURCE_DIR}/doc/doxygen/Doxygen.conf.in"
  "${PROJECT_BINARY_DIR}/doc/doxygen/Doxygen.conf"
  )
add_custom_target( doxygen
                   COMMAND doxygen Doxygen.conf
                   WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/doc/doxygen)
{%- endif %}

{%- if cookiecutter.readthedocs == "Yes" %}
#
# Sphinx configure files and target.
#
configure_file (
  "${PROJECT_RESOURCES_DIR}/sphinx/conf.py.in"
  "${PROJECT_SOURCE_DIR}/doc/sphinx/conf.py"
  )
configure_file (
  "${PROJECT_RESOURCES_DIR}/sphinx/Makefile.in"
  "${PROJECT_SOURCE_DIR}/doc/sphinx/Makefile"
  )
configure_file (
  "${PROJECT_RESOURCES_DIR}/sphinx/make.bat.in"
  "${PROJECT_SOURCE_DIR}/doc/sphinx/make.bat"
  )
configure_file (
  "${PROJECT_RESOURCES_DIR}/sphinx/index.rst.in"
  "${PROJECT_SOURCE_DIR}/doc/sphinx/index.rst"
  )
add_custom_target( sphinx_html
                   COMMAND make html
                   WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/doc/sphinx)
{%- endif %}

########################################################################
#
# Set the include directory. These are the public includes.
#
########################################################################
include_directories(${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR}/include)

########################################################################
#
# Compile the libraries.
#
########################################################################
add_subdirectory(libsrc)
########################################################################
#
# Compile the applications.
#
########################################################################
add_subdirectory(src)

########################################################################
#
# Build the tests.
#
########################################################################
if (BUILD_TESTING)
   enable_testing()
   add_subdirectory(test)
endif()
