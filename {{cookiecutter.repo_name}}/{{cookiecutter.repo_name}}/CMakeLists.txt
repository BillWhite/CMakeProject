cmake_minimum_required (VERSION 2.6)
project ({{cookiecutter.default_project_name}} C CXX)

########################################################################
#
# Third party configurations.
#
# Personally, I put all my 3rd party sources in one directory,
# just to organize them.  This is includes gmock, lib4cxx,
# google protocol buffers, various boost versions, compiler
# version sources and so forth.  We need to know where
# gmock is for this exercise, so we include this name here.
#
########################################################################
if ("${THIRDPARTY_SOURCE_DIR}" STREQUAL "")
  set (THIRDPARTY_SOURCE_DIR "$ENV{HOME}/src/3pty")
endif()
if ("${GMOCK_VERSION}" STREQUAL "")
  set (GMOCK_VERSION 1.7.0)
endif()

#
# Delete this BOOST section if you don't want BOOST.  (Who doesn't
# want to use BOOST?)  I typically install more than one version
# of BOOST, and put them in /usr/local/include/boost/boost_VERSION.
# This can be configured with the pbin/configure_* file.
#
# Your needs may vary.
#
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

########################################################################
#
# Project metadata.
#
########################################################################
set ({{cookiecutter.default_project_name}}_VERSION_MAJOR 0.1)
set ({{cookiecutter.default_project_name}}_VERSION_MINOR 0.1)
set ({{cookiecutter.default_project_name}}_VERSION_PATCH 0.1)

configure_file (
  "${PROJECT_SOURCE_DIR}/include/{{cookiecutter.default_project_name}}Config.h.in"
  "${PROJECT_BINARY_DIR}/include/{{cookiecutter.default_project_name}}Config.h"
  )

########################################################################
#
# Compiler Configuration
#
########################################################################
set (CLANG_DIR {{cookiecutter.clang_dir}})
include("${PROJECT_SOURCE_DIR}/CMakeLib/configureClang.cmake")
configureClang(${CLANG_DIR} ${CLANG_VERSION} c++11 c++ c++abi)

########################################################################
#
# Delete this line if you don't want ctest.  Who doesn't want
# easy testing?
#
########################################################################
enable_testing()
add_subdirectory(libsrc)
add_subdirectory(src)
add_subdirectory(test)

