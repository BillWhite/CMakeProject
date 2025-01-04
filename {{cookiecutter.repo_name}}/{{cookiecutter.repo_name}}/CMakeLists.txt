########################################################################
# Copyright {{ current_year }} by the copyright holders
# named in COPYING.md.
#
# Licensed under: {{ cookiecutter.license }}
# See https://spdx.dev or LICENSE.md in this
# project for the license text.
########################################################################

cmake_minimum_required (VERSION 3.9)
project ({{cookiecutter.repo_name}} C CXX)

option(USE_BOOST "Use the boost library." OFF)
option(BUILD_TESTING "Build the tests." ON)
cmake_policy(SET CMP0135 NEW)

########################################################################
#
# definitions.
#
########################################################################
string(REPLACE "-" "_" PROJECT_SLUG "{{ cookiecutter.repo_name|upper }}")

########################################################################
#
# Delete this BOOST section if you don't want BOOST.  (Who doesn't
# want to use BOOST?)  I typically install more than one version
# of BOOST, and put them in /usr/local/include/boost/boost_VERSION.
# This can be configured with the pbin/configure_* file.
#
# Your needs may vary.
#
########################################################################
if (${USE_BOOST}) 
   set(BOOST_MINIMUM_VERSION 1.54.0)
   set(Boost_USE_STATIC_LIBS OFF)
   set(Boost_USE_MULTITHREADED OFF)
   set(Boost_USE_STATIC_RUNTIME OFF)
   if ("${BOOST_ROOT}" STREQUAL "")
     set (BOOST_ROOT "/usr/local/include/boost/boost_1_54_0")
   endif()
   if ("${BOOST_VERSION}" STREQUAL "")
     set (BOOST_VERSION 1.54.0)
   endif()
   find_package(Boost ${BOOST_VERSION} REQUIRED)

   include_directories(${Boost_INCLUDE_DIRS}) 
endif()

########################################################################
#
# Project metadata.
#
########################################################################
set (PROJECT_VERSION_MAJOR 0.1)
set (PROJECT_VERSION_MINOR 0.1)
set (PROJECT_VERSION_PATCH 0.1)

########################################################################
#
# Configuration variables:
#     1. for C++ consumption.  Use @PROJECT_SLUG@ in this file.
#     2. for Doxygen.
#
########################################################################
configure_file (
  "${PROJECT_SOURCE_DIR}/include/{{cookiecutter.repo_name}}-config.h.in"
  "${PROJECT_BINARY_DIR}/include/{{cookiecutter.repo_name}}/{{cookiecutter.repo_name}}-config.h"
  )

configure_file (
  "${PROJECT_SOURCE_DIR}/doc/doxygen/Doxygen.conf.in"
  "${PROJECT_BINARY_DIR}/doc/doxygen/Doxygen.conf"
  )

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
