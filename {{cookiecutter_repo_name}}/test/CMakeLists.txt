add_subdirectory(lib)

include_directories("${gmock_SOURCE_DIR}/include"
                    "${gmock_SOURCE_DIR}"
                    "${gtest_SOURCE_DIR}/include"
                    # This directory is needed to build directly from Google
                    # Test sources.
                    "${gtest_SOURCE_DIR}")

add_executable(cmproject_test maintest.cpp)

set_property(TARGET cmproject_test
	     PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/testbin)

target_link_libraries(cmproject_test gmock gmock_main)
