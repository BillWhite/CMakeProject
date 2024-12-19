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
# This CMakeLists.txt file is for configuring a single library.
# 
# First, enumerate the source files.
#
########################################################################
set (SOURCES {{cookiecutter.mainapp}}.cpp)

########################################################################
#
# If you need to link against any 3rd party libraries, list
# them here.
#
########################################################################
set (LIBRARIES {{cookiecutter.mainlib}})

########################################################################
#
# Set the include directory. The public include directory is
# already added, so just include the private include directory
# right here.
#
########################################################################
include_directories(include)

########################################################################
#
# Make the main executable link with the main library.
#
########################################################################
add_executable({{cookiecutter.mainapp}} ${SOURCES})
target_link_libraries({{cookiecutter.mainapp}} ${LIBRARIES})

########################################################################
#
# Install executables in a /bin/ directory.
#
########################################################################
set_property(TARGET {{cookiecutter.mainapp}}
             PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
