#include <iostream>
#include "{{cookiecutter.mainlib}}/public.hpp"
#include "{{cookiecutter.mainapp}}/public.hpp"
#include "{{cookiecutter.mainapp}}_private.hpp"

int
main(int argc, char **argv)
{
  std::cout << {{cookiecutter.mainapp|upper}}_PUBLIC_STRING << "\n";
  std::cout << {{cookiecutter.mainapp|upper}}_PRIVATE_STRING<< "\n";
  std::cout << cmutil(100) << "\n";
}
