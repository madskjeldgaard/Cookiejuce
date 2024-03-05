#[no_mangle]
pub extern fn my_rust_function(left: usize, right: usize) -> usize {
    left + right
}

#[cxx::bridge(namespace = "{{ cookiecutter.__rust_lib_name }}")]
mod ffi {
    // This lists types and functions defined on the Rust side that should be exposed to C++
    extern "Rust" {
        fn my_rust_function(left: usize, right: usize) -> usize;
    }

    // A unsafe extern "C++" section defines data types and functions available on the C++ side, which should be usable from Rust
    // unsafe extern "C++" {
    //     include!("myrustlib/include/myrustlib.h");

    //     type MyRustLib;

    //     fn create() -> UniquePtr<MyRustLib>;
    //     fn add(this: &MyRustLib, left: usize, right: usize) -> usize;
    // }
}


#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = my_rust_function(2, 2);
        assert_eq!(result, 4);
    }
}
