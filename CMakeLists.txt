cmake_minimum_required(VERSION 3.10)
project(CppWebserver)

set(CMAKE_CXX_STANDARD 14)

# so test dir can find header files
include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)