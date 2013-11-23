########################################################################
#
# This folder is for tests.  Test sources are found in subfolders
# of this folder.  
# 1. The test binaries will be put in the build folder in the
#    subfolder named testbin/.
# 2. Tests should be written expecting to be run in a subfolder
#    of the build area called test.
# 3. There will be a target called gtestrunner which will run
#    ctest -v, to run all the tests in a ctest framework.  (The
#    make command "make test" or "ninja test" calls ctest, but
#    it doesn't add -v.  This does not report individual test
#    status.)
# 4. If you want data to be copied into the build area's test
#    folder, but it in the data subfolder of the source area's
#    test folder.
#
########################################################################

