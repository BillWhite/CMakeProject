cmake_minimum_required (VERSION 2.6)
project ({{cookiecutter.default_project_name}} C CXX)

set (THIRDPARTY_SOURCE_DIR "{{cookiecutter.third_party_location}}")
set (GMOCK_VERSION {{cookiecutter.google_mock_version}})
set ({{cookiecutter.default_project_name}}_VERSION_MAJOR 0.1)
set ({{cookiecutter.default_project_name}}_VERSION_MINOR 0.1)
set ({{cookiecutter.default_project_name}}_VERSION_PATCH 0.1)

configure_file (
  "${PROJECT_SOURCE_DIR}/include/{{cookiecutter.default_project_name}}Config.h.in"
  "${PROJECT_BINARY_DIR}/include/{{cookiecutter.default_project_name}}Config.h"
  )

add_subdirectory(libsrc)
add_subdirectory(src)
add_subdirectory(test)

