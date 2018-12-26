// Build a static library by
// $ rustc --crate-type=staticlib demo.rs

#[no_mangle]
pub extern "C" fn cubic(x: u32) -> u32 {
    x * x * x
}