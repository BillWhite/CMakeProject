#include "{{cookiecutter.project_slug}}/{{cookiecutter.project_slug}}-config.h"
#include "{{cookiecutter.mainlib}}/{{cookiecutter.mainlib}}.hpp"
#include "{{cookiecutter.mainapp}}/{{cookiecutter.mainapp}}.hpp"
#include "{{cookiecutter.mainapp}}_private.hpp"
#include <iostream>
/************************************************************************
 *  Copyright {{ current_year }} by the copyright holders
 *  named in COPYING.md.
 *
 * Licensed under: {{ cookiecutter.license }}
 * See https://spdx.dev or LICENSE.md in this
 * project for the license text.
 ************************************************************************/
/**
 * @file {{cookiecutter.mainapp}}.cpp
 *
 * This demonstrates the implementation of a main function.
 */

/**
 * The main function.
 */
int
main(int argc, char **argv)
{
  std::cout << {{cookiecutter.mainapp|upper}}_PUBLIC_STRING << "\n";
  std::cout << {{cookiecutter.mainapp|upper}}_PRIVATE_STRING<< "\n";
  std::cout << cmutil(100) << "\n";
}
