########################################################################
# Copyright 2025 by the copyright holders
# named in COPYING.md.
#
# Licensed under: GPL-3.0-or-later
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
    URL https://github.com/google/googletest/archive/52eb8108c5bdec04579160ae17225d66034bd723.zip
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
add_subdirectory(cmutil)
add_subdirectory(cmapp1)
