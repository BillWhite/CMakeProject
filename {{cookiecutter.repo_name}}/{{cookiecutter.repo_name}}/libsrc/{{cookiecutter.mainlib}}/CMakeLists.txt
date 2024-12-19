########################################################################
#
# This CMakeLists.txt file is for configuring a single library.
#
########################################################################
set (SOURCES
     {{cookiecutter.mainlib}}.cpp)

########################################################################
#
# If your library needs to link against some other library,
# then include that here.
#
########################################################################
set (LIBRARIES "")

########################################################################
#
# Set the include directory. The public include directory is
# already added, so just include the private include directory
# right here.
#
########################################################################
include_directories(include)

########################################################################
#
# Define the main library.
#
########################################################################
add_library({{cookiecutter.mainlib}} ${SOURCES})
target_link_libraries({{cookiecutter.mainlib}} ${LIBRARIES})

#
# Install the main library in /lib/.
#
set_property(TARGET {{cookiecutter.mainlib}}
             PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
