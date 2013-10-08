#
# Set the include directories.
#
include_directories(${CMAKE_SOURCE_DIR}/include include)

#
# Define the main executable.
#
add_executable({{cookiecutter.mainapp}} {{cookiecutter.mainapp}}.cpp)

#
# Make the main executable link with the main library.
#
target_link_libraries({{cookiecutter.mainapp}} {{cookiecutter.mainlib}})

#
# Install executables in a /bin/ directory.
#
set_property(TARGET {{cookiecutter.mainapp}}
             PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
