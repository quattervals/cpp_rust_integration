// build.rs
fn main() {
    cxx_build::bridge("src/lib.rs").compile("rust_c");

    println!("cargo:rerun-if-changed=src/lib.rs");
}
