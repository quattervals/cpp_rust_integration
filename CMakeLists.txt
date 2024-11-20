cmake_minimum_required(VERSION 3.10)

project(rust-c CXX)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(libcpp-project)
add_subdirectory(cpp-project)
add_subdirectory(cpp-project-test)
