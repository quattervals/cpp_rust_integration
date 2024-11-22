cmake_minimum_required(VERSION 3.10)

add_library(libcpp-project cpp_project.cpp)

include(FetchContent)


target_include_directories(libcpp-project PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

