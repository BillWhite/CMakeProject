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
