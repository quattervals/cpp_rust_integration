#[cxx::bridge]
mod ffi {
    extern "Rust" {
        // passing rust to C++
        type SuperStructure;
        fn new_super_structure() -> Box<SuperStructure>;
        fn increment(&mut self, value: i32);
        fn get_counter(&self) -> i32;

        fn free_rust_function(x: i32) -> i32;

    }
}

pub fn free_rust_function(x: i32) -> i32 {
    x * 2
}
pub fn new_super_structure() -> Box<SuperStructure> {
    Box::new(SuperStructure::new())
}

#[repr(C)]
pub struct SuperStructure {
    counter: i32,
}

impl SuperStructure {
    pub fn new() -> SuperStructure {
        println!("New SuperStructure created.");
        SuperStructure { counter: 0 }
    }

    pub fn increment(&mut self, value: i32) {
        self.counter += value;
    }

    pub fn get_counter(&self) -> i32 {
        self.counter
    }
}

impl Drop for SuperStructure {
    fn drop(&mut self) {
        println!(
            "SuperStructure with counter {} is being dropped.",
            self.counter
        );
    }
}
