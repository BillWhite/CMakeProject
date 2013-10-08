include_directories("${gmock_SOURCE_DIR}/include"
                    "${gmock_SOURCE_DIR}"
                    "${gtest_SOURCE_DIR}/include"
                    # This directory is needed to build directly from Google
                    # Test sources.
                    "${gtest_SOURCE_DIR}")

add_executable({{cookiecutter.mainapp}}_test {{cookiecutter.mainapp}}_test.cpp)

set_property(TARGET {{cookiecutter.mainapp}}_test
	     PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/testbin)

target_link_libraries({{cookiecutter.mainapp}}_test gmock gmock_main)
