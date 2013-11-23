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
# here.  The gtest and gmock include paths are already configured.
# The gtest libraries are in ${GTEST_LIBS}.  The gmock libraries
# are in ${GMOCK_LIBS}.  Include the ones you want here.
#
########################################################################
set (TEST_LIBRARIES    ${GMOCK_LIBS} {{cookiecutter.mainlib}})

########################################################################
#
# Configure the tests.
#
########################################################################
configureTargetForCompilation({{cookiecutter.mainapp}}_test "${TEST_LIBRARIES}" "${TEST_SOURCES}")

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


