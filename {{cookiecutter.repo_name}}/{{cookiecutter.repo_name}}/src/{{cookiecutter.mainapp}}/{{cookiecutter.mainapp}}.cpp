#include "{{cookiecutter.mainlib}}/{{cookiecutter.mainlib}}.hpp"
#include "{{cookiecutter.mainapp}}/{{cookiecutter.mainapp}}.hpp"
#include "{{cookiecutter.mainapp}}_private.hpp"
#include <iostream>

int
main(int argc, char **argv)
{
  std::cout << {{cookiecutter.mainapp|upper}}_PUBLIC_STRING << "\n";
  std::cout << {{cookiecutter.mainapp|upper}}_PRIVATE_STRING<< "\n";
  std::cout << cmutil(100) << "\n";
}
