CMakeProject
============

A cookiecutter template for C++ projects with CMake, using
Catch2 for testing.

How to use
==========
1.  Run the command:

      % cookiecutter git@github.com:BillWhite/CMakeProject.git

    You will be asked some questions.  The result will be a
    directory with some source code.  The name of the directory
    is the answer to one of the questions, but let's imagine it's
    '{{ cookiecutter.project-slug }}'.
2.  cd {{ cookiecutter.project-slug }}
3.  Run "{{ cookiecutter.project-slug }}/pbin/{{ cookiecutter.project-slug }}"

The Directory Structore
=======================

Projects created with from this template build three different
kinds of things.

1. Libraries
2. Applications
3. Unit tests

The directory structure reflects this pretty transparently, but
there is a peculiarity. The source directory is not at the top
but it a level below the top. The top level holds the source
directory, and is a good place to put build directories as well.
You might want to put build directories someplace far away from
the source directory. For example, since the build directories
can be regenerated you might want to put them on some storage
area which is not backed up. Since I always back up source
directories using git and remote repositories I don't worry about
this so much any more.

The theory behind this setup is that most of the code goes into
libraries, and only the UI code goes in the application area.

The directories are:

    project/                         This is the "project_slug" setting
                                     when the project is created.  The
                                     CMake source directory will be inside
                                     this directory.  This is a useful
                                     place to put CMake build directories as
                                     well.
      .projectroot                   An empty file used by the proot
                                     navigation script (cf. below).                                   
      project/                       This has the same name as the one
                                     above.  This is the CMake source
                                     directory.  All sources and
                                     CMakeList.txt files will go here.
        .sourceroot                  An empty file used by the proot
                                     navigation script (cf. below).
        include/                     Public include files will go here.
                                     All files placed here will be
                                     installed.  I typically make a
                                     subdirectory for each library.
        libsrc/                      This is the source directory for
                                     libraries.  The CMakeList.txt file
                                     for this directory has mostly configuration
                                     and add_subdirectory commands, one for
                                     each library.
          somelib/                   All sources and CMakeFile.txt files
                                     for the library somelib go here.
            include/                 All include files private to
                                     somelib will go here.
        src/                         This is the source directory for
                                     application sources.  All
                                     application sources and
                                     CMakeList.txt files go here.
                                     As with libsrc, this mostly contains
                                     add_directory commands.
          someapp/                   Source for the application someapp
                                     goes here.
            include/                 Include file files private to
                                     someapp go here.
        test/                        All tests go here.  Tests will be
                                     run in the test directory of the CMake
                                     binary directory.
          data/                      This will be copied to the test
                                     binary directory.
        lib/                         3rd party libraries go here.
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
                                     Note that this does not build the
                                     project, it just runs CMake for you.
        proot                        A script for navigating the source
                                     and build trees.  Run
				     proot --help
 				     for help.

