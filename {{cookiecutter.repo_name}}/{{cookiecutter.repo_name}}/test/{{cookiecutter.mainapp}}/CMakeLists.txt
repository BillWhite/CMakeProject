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
# Define the test execuables.
#
# First, define the sources.
#
########################################################################
set (TEST_SOURCES {{cookiecutter.mainapp}}_test.cpp)

########################################################################
#
# Then, define the executables.
#
########################################################################
add_executable({{cookiecutter.mainapp}}_test
               {{cookiecutter.mainapp}}_test.cpp)
target_link_libraries({{cookiecutter.mainapp}}_test
                      {{cookiecutter.mainlib}}
                       GTest::gtest_main)

gtest_discover_tests({{cookiecutter.mainapp}}_test)

########################################################################
#
# Move the tests into testbin.
#
########################################################################
set_property(TARGET {{cookiecutter.mainapp}}_test
	     PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/testbin)
add_test(NAME    {{cookiecutter.mainapp}}_ctest
         COMMAND ${CMAKE_BINARY_DIR}/testbin/{{cookiecutter.mainapp}}_test)



