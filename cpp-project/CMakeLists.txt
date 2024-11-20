add_executable(cpp-project main.cpp)

target_link_libraries(cpp-project libcpp-project)
target_include_directories(cpp-project PUBLIC ${CMAKE_SOURCE_DIR}/libcpp-project)
target_include_directories(cpp-project PUBLIC ${CMAKE_SOURCE_DIR}/rust-project/bindings)
