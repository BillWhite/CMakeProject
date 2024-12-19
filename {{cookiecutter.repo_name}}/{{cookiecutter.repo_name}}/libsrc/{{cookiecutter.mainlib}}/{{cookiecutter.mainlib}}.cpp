#include <string>
#include <sstream>

#include "{{cookiecutter.mainlib}}/{{cookiecutter.mainlib}}.hpp"
#include "{{cookiecutter.mainlib}}_private.hpp"

std::string
{{cookiecutter.mainlib}}(int idx)
{
  std::ostringstream str;
  str << "{{cookiecutter.mainlib}}: " << idx;
  return str.str();
}
