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
#include "{{cookiecutter.project_slug}}/{{cookiecutter.project_slug}}-config.h"
#include "{{cookiecutter.mainlib}}/{{cookiecutter.mainlib}}.hpp"
#include "{{cookiecutter.mainlib}}_private.hpp"
#include <sstream>
#include <string>

/**
 * A utility function.
 */
std::string
{{cookiecutter.mainlib}}(int idx)
{
  std::ostringstream str;
  str << "Version: "
      << {{ cookiecutter.project_slug|upper|replace("-","_") }}_VERSION_MAJOR
      << "."
      << {{ cookiecutter.project_slug|upper|replace("-","_") }}_VERSION_MINOR
      << "."
      << {{ cookiecutter.project_slug|upper|replace("-","_") }}_VERSION_PATCH
      << std::endl;
  str << "{{cookiecutter.mainlib}}: " << idx << std::endl;
  return str.str();
}
