#include <sstream>

std::string
{{cookiecutter.mainlib}}(int idx)
{
  std::ostringstream str;
  str << "{{cookiecutter.mainlib}}: " << idx;
  return str.str();
}
