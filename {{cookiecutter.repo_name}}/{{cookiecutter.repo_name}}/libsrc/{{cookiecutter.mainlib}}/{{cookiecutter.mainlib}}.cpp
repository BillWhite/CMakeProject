/************************************************************************
 *  Copyright {{ current_year }} by the copyright holders
 *  named in COPYING.md.
 *
 * Licensed under: {{ cookiecutter.license }}
 * See https://spdx.dev or LICENSE.md in this
 * project for the license text.
 ************************************************************************/
/**
 * @file {{cookiecutter.mainlib}}.cpp
 *
 * This demonstrates the implementation of a library function.
 */
#include <string>
#include <sstream>
#include "{{cookiecutter.repo_name}}/default-project-config.h"
#include "{{cookiecutter.mainlib}}/{{cookiecutter.mainlib}}.hpp"
#include "{{cookiecutter.mainlib}}_private.hpp"

std::string
{{cookiecutter.mainlib}}(int idx)
{
  std::ostringstream str;
  str << "{{cookiecutter.mainlib}}: " << idx;
  return str.str();
}
