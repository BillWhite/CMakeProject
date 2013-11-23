#
# This functions job is to set the system include directories,
# add all necessary compiler definitions, and to set the
# variables SYSTEM_LIBS.
# 1. System Include files.
#    These are the files included with "#include <mumble.hpp>".
#    Typically we add three things to the system include directories.
#    1. Where to find the clang compiler includes. These are the
#       include files this program includes explicitly.  These
#       are the files like clang-c/Index.h or clang-c/CXString.h.
#    2. Where to find the operating system includes. This
#       usually includes /usr/include, and need to be system
#       includes.
#    3. Where to find the include files needed by the compiler.
#       This is for floating point and other machine
#       level definitions.  This is usually somewhere in the
#       compiler's installation directory, and needs to be a
#       system include.
#    4. Where to find the standard C++ library include files.
#       This is typically under /usr/include/c++ someplace, though
#       there may be several subdirectories as well.
#    Note that this does not include include paths for things like
#    Google Test or the Boost Libraries.  This is just the include
#    paths for system facilities and the standard C++ library.
# 2. Compiler Definitions.
#    These may be empty.  Typically one would set the C++ stanard
#    here, as well as telling the compiler to not include its
#    built-in include paths.  If we tell the compiler not to use
#    any built-in include paths, we are on the hook to provide
#    all system include paths needed.
#
function (configureClang CLANG_DIR CLANG_VERSION CXXSTD CXXLIB CXXABI)
  # Note that we define local definitions here, and use them.
  # We export some variables into the parent scope below.
  set (L_CPP_CLANG_INCLUDES ${CLANG_DIR}/include)
  set (L_CPP_COMPILER_INCLUDES ${CLANG_DIR}/lib/clang/${CLANG_VERSION}/include)
  set (L_CPP_STDLIB_INCLUDES ${CLANG_DIR}/include/c++/v1)
  set (L_CPP_SYSTEM_INCLUDES "${L_CPP_COMPILER_INCLUDES};${L_CPP_STDLIB_INCLUDES}")

  set (L_CPP_COMPILE_FLAGS "-nostdinc++ -std=${CXXSTD}")
  set (L_CPP_LINK_LIBS "-L${CLANG_DIR}/lib -l${CXXLIB} -l${CXXABI}")
  include_directories(SYSTEM ${L_CPP_SYSTEM_INCLUDES})
  include_directories(${L_CPP_CLANG_INCLUDES})
  add_definitions(${L_CPP_COMPILE_FLAGS})

  set (CPP_COMPILER_INCLUDES ${L_CPP_COMPILER_INCLUDES} PARENT_SCOPE)
  set (CPP_STDLIB_INCLUDES ${L_CPP_STDLIB_INCLUDES} PARENT_SCOPE)
  set (CPP_SYSTEM_INCLUDES ${L_CPP_SYSTEM_INCLUDES} PARENT_SCOPE)
  set (CPP_CLANG_INCLUDES ${L_CPP_CLANG_INCLUDES} PARENT_SCOPE)
  set (CPP_COMPILE_FLAGS "${L_CPP_COMPILE_FLAGS}" PARENT_SCOPE)
  set (CPP_LINK_LIBS "${L_CPP_LINK_LIBS}" PARENT_SCOPE)
endfunction(configureClang)

#
# This function is used to configure executables and libraries
# for linking.  It subsumes add_executable, and is used in the same
# way as add_executable.  That is to say,
#   configureTargetForCompilation(target sources)
# calls "add_executable(target sources)" and then adds some other
# common compilation configuration.
#
function (configureTargetForCompilation target libraries sources)
  message("Configuring clang compiler for executable ${target}")
  add_executable(${target} ${sources})
  set_target_properties(${target}
                        PROPERTIES
                        LINK_FLAGS "${CPP_LINK_LIBS}")
  target_link_libraries(${target} ${libraries})
endfunction(configureTargetForCompilation)

#
# This function is like configureTargetForCompilation, but it
# configures libraries.
#
function (configureLibraryForCompilation target libraries sources)
  message("Configuring clang compiler for library ${target}")
  add_library(${target} ${sources})
  target_link_libraries(${target} ${libraries})
  set_target_properties(${target}
                        PROPERTIES
                        LINK_FLAGS "${CPP_LINK_LIBS}")
endfunction(configureLibraryForCompilation)

