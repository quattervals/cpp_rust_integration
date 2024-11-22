cmake_minimum_required(VERSION 3.10)

project(rust-cpp CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(libcpp-project)
target_link_libraries(${PROJECT_NAME} PUBLIC libcpp-project)



FetchContent_Declare(
    Corrosion
    GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
    GIT_TAG v0.5 # Optionally specify a commit hash, version tag or branch here
)
FetchContent_MakeAvailable(Corrosion)
# Import targets defined in a package or workspace manifest `Cargo.toml` file
corrosion_import_crate(MANIFEST_PATH ${CMAKE_SOURCE_DIR}/rust-project/Cargo.toml)

target_link_libraries(${PROJECT_NAME} PUBLIC rust_foos)
target_include_directories(${PROJECT_NAME} PUBLIC  ${CMAKE_SOURCE_DIR}/rust-project/target/cxxbridge/rust-project/src)



