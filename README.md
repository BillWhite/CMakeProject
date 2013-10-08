CMakeProject
============

I wanted to understand how to use CMake and Google Mock together.
So, I made this cookiecutter template to record the result of my
researches.

This work depends on these tools:

1. cookiecutter version 0.6.4, though perhaps 0.7.0 will work.
1. Google Mock.  I am using version 1.7.0, but I don't think the
   version is all that important.  Try whatever you want.  You
   might as well try the newest version.  I don't distribute
   Google Mock, so you're on your own.  If you use a different
   version, check that the include files in `src/CMakeLists.txt`
   and `libsrc/CMakeLists.txt` are sensible.
1. A suitable license.  The project resulting from this cookiecutter
   will have an empty license file.  Fill it in with the Apache License,
   or the BSD License, or whatever you want.  Knock yourself out.
1. I don't do anything with source file formats.  If you want source
   files to have a particular shape, you are on your own.

Installation.

1. Install cookiecutter.  See https://github.com/audreyr/cookiecutter or
   else http://cookiecutter.readthedocs.org/en/latest.  No python required.
1. Install gmock somewhere, maybe in $HOME/src/gmock-1.7.0.  Remember where
   you installed it.
1. Run the command:
       cookiecutter git@github.com:BillWhite/CMakeProject.git
   and answer the questions.  The questions are pretty obvious.
   1. 	`full_name`: Your full name (optional).
   1.   `email`: Your email address for this project (optional).
   1.   `github_username`: Your github name (optional)
   1.   `default_project_name`: The default name of projects made with this template.
        Unless you specify something special here, all projects made with this
        template will have this name.  The value of this string is denoted
	`$PROJECT_NAME` in this documentation.
   1.   `mainapp`: The default name of the main applications.
   1.   `mainlib`: The default name of the main library.
   1.   `project_short_description`: A short description of your project.
   1.   `third_party_location`: The folder in which the Google Mock source will be found.
        The default will almost certainly be unusable for you.
   1.   `google_mock_version`: The version of Google Mock you are using.
   1.   `c_compiler`: Your C compiler.  The default is Clang.
   1.   `cpp_compiler`: Your C++ compiler.  The default is Clang++.
   1.   `cmake_generator`: The way CMake will generate build directives.  See the
        CMake documentation.  The default is to generate both Ninja build files
        and Eclipse projects.
   1.   `install_prefix`: The installation prefix.  The default is /usr/local.
1. Your project will be created.  You probably want to build and test before
   you add any code.  You need to configure a binary directory for this, as
   is usual with CMake projects.
   1. From outside the project folder, say `$PROJECT_ROOT/..`, run a command
      to configure the project.  There is a command started in `$PROJECT_ROOT/pbin`
      called `configure-$PROJECT_NAME`.
            `/bin/sh $PROJECT_ROOT/pbin/configure-$PROJECT_NAME --help`
      This should list the command line parameters.  It's not currently
      possible to avoid setting the C and C++ compilers, though editing the
      configure script should work for you.  For example, the command:
      	    `/bin/sh $PROJECT_ROOT/pbin/configure-PROJECT_NAME \\
	        -DCMAKE_BUILD_TYPE=Release \
		-G 'Eclipse CDT4 - Makefile' \
		$PROJECT_ROOT Release`
      will configure the project in $PROJECT_ROOT with build area in
      the directory `./Release`.
   1. The newly created project will have one appication and one library. It
      will have a single test for the application and a single test for the
      library.  
      1. The application will be in $BUILD_DIR/bin.
      2. The library will be in $BUILD_DIR/lib.  This is currently a static
         library (.a) but I will soon make dynamic libraries configurable.
      1. All tests will be in testbin.  They will all fail by design.  
      1. You can delete either the application or the library, or use them as
         patterns to make new applications or libraries, as you choose.

