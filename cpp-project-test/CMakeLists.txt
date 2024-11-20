cmake_minimum_required(VERSION 3.10)

add_executable(cpp-project-test test.cpp catch_amalgamated.cpp)
target_include_directories(cpp-project-test PUBLIC ${CMAKE_SOURCE_DIR}/libcpp-project)
target_link_libraries(cpp-project-test libcpp-project)