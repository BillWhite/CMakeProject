include_directories(include)

add_executable(cmproject cmproject.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

set_property(TARGET cmproject 
             PROPERTY RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
