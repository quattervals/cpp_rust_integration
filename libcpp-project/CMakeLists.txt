cmake_minimum_required(VERSION 3.10)

add_library(libcpp-project cpp_project.cpp)

include(FetchContent)
FetchContent_Declare(
    Corrosion
    GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
    GIT_TAG v0.5 # Optionally specify a commit hash, version tag or branch here
)
FetchContent_MakeAvailable(Corrosion)
# Import targets defined in a package or workspace manifest `Cargo.toml` file
corrosion_import_crate(MANIFEST_PATH ${CMAKE_SOURCE_DIR}/rust-project/Cargo.toml)
target_link_libraries(libcpp-project PUBLIC rust_c)

target_include_directories(libcpp-project PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(libcpp-project PUBLIC ${CMAKE_SOURCE_DIR}/rust-project/bindings)



# For manual linking:
#add_custom_target() to build first!
#target_include_directories(libcpp-project PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/rust-project/bindings)
#target_link_libraries(libcpp-project PUBLIC ${CMAKE_SOURCE_DIR}/rust-project/target/release/librust_c.a)
