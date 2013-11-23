########################################################################
#
# This CMakeLists.txt file exists to list the lib folder and the
# subfolders needed to test the applications and libraries.
#
# First we configure this lib folder, which includes the binaries
# and includes for gmock and gtest.  You need this.
#
########################################################################
add_subdirectory(lib)

include_directories("${gmock_SOURCE_DIR}/include"
                    "${gmock_SOURCE_DIR}"
                    "${gtest_SOURCE_DIR}/include"
                    # This directory is needed to build directly from Google
                    # Test sources.
                    "${gtest_SOURCE_DIR}")
set (GTEST_LIBS gtest gtest_main)
set (GMOCK_LIBS gmock gmock_main)

########################################################################
#
# Include a subfolder for the main library and the main application.
# Be sure the name all the test targets here.
#
########################################################################
add_subdirectory({{cookiecutter.mainlib}})
add_subdirectory({{cookiecutter.mainapp}})

add_custom_target(ctestverbose
		  WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/test
		  COMMAND ctest --output-on-failure
		  COMMENT "Testing with gtest")

add_custom_command(OUTPUT "${PROJECT_BUILD_DIR}/test/data"
                   COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_BINARY_DIR}/test"
		   COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_BINARY_DIR}/test/data"
		   COMMAND ${CMAKE_COMMAND} 
		   	   -E copy_directory
			      "${PROJECT_SOURCE_DIR}/test/data"
		   	      "${PROJECT_BINARY_DIR}/test/data")
