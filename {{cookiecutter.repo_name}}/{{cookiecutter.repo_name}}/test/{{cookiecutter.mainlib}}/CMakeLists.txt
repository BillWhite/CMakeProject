########################################################################
#
# These are the sources used by this test.
#
########################################################################
set (TEST_SOURCES {{cookiecutter.mainlib}}_test.cpp)

########################################################################
#
# If your application tests needs to link against some other
# libraries, like maybe the libraries in this project, include them
# here.  The gtest and gmock include paths are already configured.
# The gtest libraries are in ${GTEST_LIBS}.  The gmock libraries
# are in ${GMOCK_LIBS}.  Include the ones you want here.
#
########################################################################
set (TEST_LIBRARIES ${GMOCK_LIBS} {{cookiecutter.mainlib}})

configureTargetForCompilation({{cookiecutter.mainlib}}_test "${TEST_LIBRARIES}" "${TEST_SOURCES}")

set_property(TARGET {{cookiecutter.mainlib}}_test
	     PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/testbin)

add_test(NAME {{cookiecutter.mainlib}}
	 WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/test
	 COMMAND ${PROJECT_BINARY_DIR}/testbin/{{cookiecutter.mainlib}}_test
	 COMMENT Testing {{cookiecutter.mainlib}} with gtest)
