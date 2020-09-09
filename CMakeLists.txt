cmake_minimum_required(VERSION 2.8)
project(cppwebserver)
add_executable(cppwebserver src/example.cpp)
install(TARGETS cppwebserver DESTINATION build)