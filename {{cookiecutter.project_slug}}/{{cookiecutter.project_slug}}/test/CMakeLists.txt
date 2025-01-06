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
# This CMakeLists.txt file exists to list the lib folder and the
# subfolders needed to test the applications and libraries.
#
########################################################################
########################################################################
#
# First, configure Google test.
#
########################################################################
include(CTest)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

#########################################################################
#
# Next we configure this lib folder, which includes common
# testing libraries.
#
########################################################################
add_subdirectory(lib)

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
		  COMMAND ctest --output-on-failure)

add_custom_command(OUTPUT "${PROJECT_BUILD_DIR}/test/data"
                   COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_BINARY_DIR}/test"
		   COMMAND ${CMAKE_COMMAND} -E make_directory "${PROJECT_BINARY_DIR}/test/data"
		   COMMAND ${CMAKE_COMMAND} 
		   	   -E copy_directory
			      "${PROJECT_SOURCE_DIR}/test/data"
		   	      "${PROJECT_BINARY_DIR}/test/data"
		   COMMAND ${CMAKE_COMMAND} 
		   	   -E remove_directory 
			      "${PROJECT_BINARY_DIR}/test/data/simple/Debug"
		   COMMAND ${CMAKE_COMMAND} 
		   	   -E make_directory 
			      "${PROJECT_BINARY_DIR}/test/data/simple/Debug"
		   COMMAND ${CMAKE_COMMAND} 
		   	   -E chdir "${PROJECT_BINARY_DIR}/test/data/simple/Debug" 
			      ${CMAKE_COMMAND} 
			        -DCMAKE_BUILD_TYPE=Debug 
				-DCMAKE_EXPORT_COMPILE_COMMANDS=ON 
				"${PROJECT_BINARY_DIR}/test/data/simple/simple")
