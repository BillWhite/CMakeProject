CMakeProject
============

A cookiecutter template for C++ projects with CMake and gmock

How to use
==========
1.  Run the command:
      % cookiecutter git@github.com:BillWhite/CMakeProject.git
    You will be asked some questions.  The result will be a
    directory with some source code.  The name of the directory
    is the answer to one of the questions, but let's imagine it's
    'default_project'.
2.  cd default_project
3.  Run "default_project/pbin/configure-default-project" %%%

The Directory Structore
=======================

Projects created with from this template build three different
kinds of things.
1. Libraries
2. Applications
3. Unit tests

The directory structure reflects this pretty transparently.  The
folders are:

  project/                         This is the "repo_name" setting
                                   when the project is created.  The
                                   CMake source folder will be inside
                                   this folder.  This is a useful
                                   place to put CMake build folders as
                                   well.
    .projectroot                   An empty file used by the proot
                                   navigation script (cf. below).                                   
    project/                       This has the same name as the one
                                   above.  This is the CMake source
                                   folder.  All sources and
                                   CMakeList.txt files will go here.
      .sourceroot                  An empty file used by the proot
                                   navigation script (cf. below).
      include/                     Public include files will go here.
                                   All files placed here will be
                                   installed.  I typically make a
                                   subfolder for each library.
      libsrc/                      This is the source folder for
                                   libraries.  The CMakeList.txt file
                                   for this folder has mostly
                                   add_subdirectory commands, one for
                                   each library.
        somelib/                   All sources and CMakeFile.txt files
                                   for the library somelib go here.
          include/                 All include files private to
                                   somelib will go here.
      src/                         This is the source folder for
                                   application sources.  All
                                   application sources and
                                   CMakeList.txt files go here.
        someapp/                   Source for the application someapp
                                   goes here.
          include/                 Include file files private to
                                   someapp go here.
      test/                        All tests go here.  Tests will be
                                   run in the test folder of the CMake
                                   binary directory.
        data/                      This will be copied to the test
                                   binary directory.
      lib/                         3rd party libraries go here.  In
                                   particular, gmock goes here.
        gmock/                     A copy of google mock.  (Of course,
                                   Google, Inc. does not endorse this
                                   project template.)
      pbin/                        Configuration scripts go here.
                                   These may not be executable.  You
                                   may need to run 
				     "/bin/sh pbin/scriptNAME".
        configure-project          This creates a CMake build
                                   directory, and runs CMake in that
                                   directory.  It configures the
                                   compiler.  Run 
				     configure-project --help
				   for help.  This is overengineered.
        proot                      A script for navigating the source
                                   and build trees.  Run
				     proot --help
 				   for help.

