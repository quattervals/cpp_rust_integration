#[cxx::bridge]
mod ffi {
    extern "Rust" {
        type SuperStructure;
        fn increment(&mut self);

        fn rust_function(x: i32) -> i32;
    }
}

pub fn rust_function(x: i32) -> i32 {
    x * 2
}

#[repr(C)]
pub struct SuperStructure {
    counter: usize,
}

impl SuperStructure {
    pub fn new() -> SuperStructure {
        println!("New SuperStructure created.");
        SuperStructure { counter: 0 }
    }

    pub fn increment(&mut self) {
        self.counter += 1;
    }

    pub fn get_counter(&self) -> usize {
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
