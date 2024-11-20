#include <cstdlib>
#include <iostream>

#include "cpp_project.h"
extern "C" {
#include "rust_c_bindings.h"
}

int main(int argc, char** argv)
{
    std::cout << "cpp_project::getValue() => " << cpp_project::getValue() << std::endl;
    std::cout << "[extern] rust_function() => " << rust_function() << std::endl;

    return EXIT_SUCCESS;
}
