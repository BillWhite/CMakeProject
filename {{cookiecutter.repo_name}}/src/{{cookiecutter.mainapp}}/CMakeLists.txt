include_directories(${CMAKE_SOURCE_DIR}/include ../include include)

add_executable({{cookiecutter.mainapp}} {{cookiecutter.mainapp}}.cpp)

set_property(TARGET {{cookiecutter.mainapp}}
             PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
