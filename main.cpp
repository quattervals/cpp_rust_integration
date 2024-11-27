#include <cstdlib>
#include <iostream>
#include <memory>

#include "cpp_project.h"
#include "lib.rs.h"

int main(int argc, char** argv) {
    std::cout << "cpp_project::getValue() => " << cpp_project::getValue() << std::endl;
    std::cout << "[extern] rust_function() => " << rust_function(3) << std::endl;
    {
        rust::Box<SuperStructure> bla = new_super_structure();
        bla->increment();
    }
    // SuperStructure* ss = super_structure_new();
    // super_structure_increment(ss);
    // size_t counter = super_structure_get_counter(ss);
    // super_structure_free(ss);

    // std::cout << "Worked with SuperStructure: counter: " << counter << std::endl;

    return EXIT_SUCCESS;
}
