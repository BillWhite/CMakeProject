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
    std::cout
        << {{ cookiecutter.project_slug|upper|replace("-","_") }}_VERSION_MAJOR 
        << "."
        << {{ cookiecutter.project_slug|upper|replace("-","_") }}_VERSION_MINOR
        << "."
        << {{ cookiecutter.project_slug|upper|replace("-","_") }}_VERSION_PATCH
        << std::endl;
    std::cout << {{cookiecutter.mainapp|upper}}_PUBLIC_STRING << std::endl;
    std::cout << {{cookiecutter.mainapp|upper}}_PRIVATE_STRING<< std::endl;;
    std::cout << {{ cookiecutter.mainlib }}(100) << std::endl;
}
