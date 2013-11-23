This folder contains exported include files.  This folder will be
copied to ${CMAKE_INSTALL_PREFIX}/include at install time.  Programs
can include a file mumble.hpp in this folder by including:

#include "{{cookiecutter.mainapp}}/mumble.hpp"

Programs in the project can include files in the same way, as
this folder is in the include path.

This is probabably not that useful.  If you want to export something,
you should probably put it in the main library, {{cookiecutter.mainlib}}.
It's just a thought.
