########################################################################
#
# Enumerate the source files.
#
########################################################################
set (SOURCES {{cookiecutter.mainapp}}.cpp)

########################################################################
#
# If you need to link against any 3rd party libraries, list
# them here.
#
########################################################################
set (LIBRARIES "{{cookiecutter.mainlib}}")

########################################################################
#
# Set the include directories.  By default we include in main
# include directory, the system directories set by the compiler
# configuration (which are not listed here) and the include
# directory in this folder.  Files in this latter folder are
# private to this application.
#
########################################################################
include_directories(${CMAKE_SOURCE_DIR}/include include)

########################################################################
#
# Configure it for compilation
#
########################################################################
configureTargetForCompilation({{cookiecutter.mainapp}} "${LIBRARIES}" "${SOURCES}")

########################################################################
#
# Make the main executable link with the main library.
#
########################################################################

########################################################################
#
# Install executables in a /bin/ directory.
#
########################################################################
set_property(TARGET {{cookiecutter.mainapp}}
             PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
