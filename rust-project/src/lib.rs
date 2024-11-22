#[no_mangle]
pub extern "C" fn rust_function() -> u64 {
    123
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

#[no_mangle]
pub extern "C" fn super_structure_new() -> *mut SuperStructure {
    Box::into_raw(Box::new(SuperStructure::new()))
}

#[no_mangle]
pub extern "C" fn super_structure_increment(ptr: *mut SuperStructure) {
    if !ptr.is_null() {
        unsafe {
            (*ptr).increment();
        }
    }
}

#[no_mangle]
pub extern "C" fn super_structure_get_counter(ptr: *const SuperStructure) -> usize {
    if ptr.is_null() {
        0
    } else {
        unsafe { (*ptr).get_counter() }
    }
}

#[no_mangle]
pub extern "C" fn super_structure_free(ptr: *mut SuperStructure) {
    if !ptr.is_null() {
        unsafe {
            drop(Box::from_raw(ptr));
        }
    }
}
