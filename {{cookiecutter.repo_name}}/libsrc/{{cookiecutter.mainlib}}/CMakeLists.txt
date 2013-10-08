#
# Set the include directory.
#
include_directories(${CMAKE_SOURCE_DIR}/include include)

#
# Define the main library.
#
add_library({{cookiecutter.mainlib}} {{cookiecutter.mainlib}}.cpp)

#
# Install the main library in /lib/.
#
set_property(TARGET {{cookiecutter.mainlib}}
             PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
