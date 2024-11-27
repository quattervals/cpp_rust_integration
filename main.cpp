#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <memory>

#include "cpp_project.h"
#include "rust-project/includes/cpp_includes.h"
#include "lib.rs.h"

namespace cpp_project {

class ConcreteStructure : public IStructure
{
  public:
    ~ConcreteStructure() override = default;

    void increment(int32_t value) override {
        counter += value;
    }

    int32_t get_counter() const override {
        return counter;
    }

  private:
    int32_t counter{ 0 };
};

}

class ConcreteRustStructureWrapper : public IStructure
{
  public:
    ConcreteRustStructureWrapper() : m_rust_structure(new_super_structure()){};

    void increment(int32_t value) override {
        m_rust_structure->increment(value);
    }

    int32_t get_counter() const override {
        return m_rust_structure->get_counter();
    }

  private:
    rust::Box<SuperStructure> m_rust_structure;
};

std::unique_ptr<IStructure> factory(bool make_rust) {
    if (make_rust) {

        return std::make_unique<ConcreteRustStructureWrapper>();
    }
    else {
        return std::make_unique<cpp_project::ConcreteStructure>();
    }
}

int main(int argc, char** argv) {
    std::cout << "cpp_project::getValue() => " << cpp_project::getValue() << std::endl;
    std::cout << "[extern] rust_function() => " << free_rust_function(3) << std::endl;
    {
        rust::Box<SuperStructure> bla = new_super_structure();
        bla->increment(99);
    }

    {
        auto cpp_strucure = cpp_project::ConcreteStructure();
        cpp_strucure.increment(3);
        cpp_strucure.get_counter();
        std::cout << "Cpp Structure: counter: " << cpp_strucure.get_counter() << std::endl;
    }
    {

        auto structure = factory(true);
        structure->increment(16);
        std::cout << "Factoried Structure: counter: " << structure->get_counter() << std::endl;
    }

    return EXIT_SUCCESS;
}
