########################################################################
#
# These are the sources used by this test.
#
########################################################################
set (TEST_SOURCES {{cookiecutter.mainapp}}_test.cpp)

########################################################################
#
# If your application tests needs to link against some other
# libraries, like maybe the libraries in this project, include them
# here.
#
########################################################################
set (TEST_LIBRARIES {{cookiecutter.mainlib}})

########################################################################
#
# Compile the tests.
#
########################################################################
add_executable({{cookiecutter.mainapp}}_test ${TEST_SOURCES})
target_link_libraries({{cookiecutter.mainapp}}_test ${TEST_LIBRARIES})

########################################################################
#
# Move the tests into testbin.
#
########################################################################
set_property(TARGET {{cookiecutter.mainapp}}_test
	     PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/testbin)

add_test(NAME {{cookiecutter.mainapp}}
	 WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/test
	 COMMAND ${PROJECT_BINARY_DIR}/testbin/{{cookiecutter.mainapp}}_test
	 COMMENT Testing {{cookiecutter.mainapp}} with gtest)


