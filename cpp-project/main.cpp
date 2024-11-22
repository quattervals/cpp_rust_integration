#include <cstdlib>
#include <iostream>

#include "cpp_project.h"
extern "C" {
#include "rust_c_bindings.h"
}

int main(int argc, char** argv) {
    std::cout << "cpp_project::getValue() => " << cpp_project::getValue() << std::endl;
    std::cout << "[extern] rust_function() => " << rust_function() << std::endl;

    SuperStructure* ss = super_structure_new();
    super_structure_increment(ss);
    size_t counter = super_structure_get_counter(ss);
    super_structure_free(ss);

    std::cout << "Worked with SuperStructure: counter: " << counter << std::endl;

    return EXIT_SUCCESS;
}
