########################################################################
#
# This CMakeLists.txt file is for configuring a single library.
#
########################################################################
set (SOURCES
     {{cookiecutter.mainlib}}.cpp)
#
# If your library needs to link against some other library,
# then include that here.
#
set (LIBRARIES "")
#
# Set the include directory.  The include path for this project
# are the inherited ones, and private includes for this library.
#
include_directories(${PROJECT_SOURCE_DIR}/include include)

#
# Define the main library.
#
configureLibraryForCompilation({{cookiecutter.mainlib}} "${LIBRARIES}" "${SOURCES}")

#
# Install the main library in /lib/.
#
set_property(TARGET {{cookiecutter.mainlib}}
             PROPERTY ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
