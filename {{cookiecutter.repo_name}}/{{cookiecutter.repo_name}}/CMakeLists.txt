cmake_minimum_required (VERSION 3.10)
project ({{cookiecutter.repo_name}} C CXX)

option(USE_BOOST "Use the boost library" OFF)
set(BOOST_MINIMUM_VERSION 1.54.0)

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
set ({{cookiecutter.repo_name}}_VERSION_MAJOR 0.1)
set ({{cookiecutter.repo_name}}_VERSION_MINOR 0.1)
set ({{cookiecutter.repo_name}}_VERSION_PATCH 0.1)

configure_file (
  "${PROJECT_SOURCE_DIR}/include/{{cookiecutter.repo_name}}Config.h.in"
  "${PROJECT_BINARY_DIR}/include/{{cookiecutter.repo_name}}Config.h"
  )

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

