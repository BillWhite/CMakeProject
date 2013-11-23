This folder contains exported include files.  This folder will be
copied to ${CMAKE_INSTALL_PREFIX}/include at install time.  Programs
can include a file mumble.hpp in this folder by including:

#include "{{cookiecutter.mainlib}}/mumble.hpp"

Programs in the project can include files in the same way, as
this folder is in the include path.

