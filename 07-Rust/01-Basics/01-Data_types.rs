#![allow(dead_code)]
#![allow(unused_imports)]
#![allow(unused_assignments)]
#![allow(unused_variables)]

use std::mem::{size_of, align_of};

fn print_type_info<T>() 
{
    println!("Type size: {} bytes", size_of::<T>());
    println!("Type alignment: {} bytes", align_of::<T>());
}

// Usage example
pub fn main() 
{
    /*--------------------------INTEGER TYPES--------------------------*/ 

    // Signed integers 
    let i8_var:   i8   = -128;                                        // 8 bits, range: -128 to 127
    let i16_var:  i16  = 32767;                                       // 16 bits, range: -32,768 to 32,767
    let i32_var:  i32  = 2147483647;                                  // 32 bits, range: -2^31 to 2^31-1
    let i64_var:  i64  = 9223372036854775807;                         // 64 bits, range: -2^63 to 2^63-1
    let i128_var: i128 = 170141183460469231731687303715884105727;     // 128 bits

    // Unsigned integers
    let u8_var:   u8   = 255;                                         // 8 bits, range: 0 to 255
    let u16_var:  u16  = 65535;                                       // 16 bits, range: 0 to 65,535
    let u32_var:  u32  = 4294967295;                                  // 32 bits, range: 0 to 2^32-1
    let u64_var:  u64  = 18446744073709551615;                        // 64 bits, range: 0 to 2^64-1
    let u128_var: u128 = 340282366920938463463374607431768211455;     // 128 bits

    // Architecture-dependent integer types
    let isize_var: isize = 0;                                         // Size depends on system architecture (32 or 64 bits)
    let usize_var: usize = 0;                                         // Size depends on system architecture (32 or 64 bits)

    // FLOATING-POINT TYPES
    let f32_var: f32 = 3.14159;                                       // 32 bits, single precision
    let f64_var: f64 = 3.14159265359;                                 // 64 bits, double precision (default)

    // BOOLEAN TYPE
    let bool_var: bool = true;                                        // 1 byte (8 bits)

    // CHARACTER TYPE - represents a full Unicode Scalar Value
    let char_var: char = 'A';                                          // 4 bytes (32 bits), Unicode scalar value
    let emoji: char = '🚀';                                           // Unicode U+1F680 (Rocket Emoji)
    let arabic: char = 'ش';                                          // Unicode U+0634 (Arabic letter 'sheen')

    
    println!("=== Integer Types ===");
    println!("i8 size:     {} bytes",      size_of::<i8>());
    println!("i16 size:    {} bytes",      size_of::<i16>());
    println!("i32 size:    {} bytes",      size_of::<i32>());
    println!("i64 size:    {} bytes",      size_of::<i64>());
    println!("i128 size:   {} bytes",      size_of::<i128>());

    println!("\n=== Float Types ===");
    println!("f32 size:    {} bytes",      size_of::<f32>());
    println!("f64 size:    {} bytes",      size_of::<f64>());

    println!("\n=== Other Types ===");
    println!("bool size:   {} bytes",     size_of::<bool>());
    println!("char size:   {} bytes",     size_of::<char>());
    println!("String size: {} bytes",     size_of::<String>());
    println!("&str size:   {} bytes",     size_of::<&str>());

    /*--------------------------COMPOUND TYPES--------------------------*/

    // Tuple
    let tuple_var: (i32, f64, char) = (42, 3.14, 'A');  // Size = sum of component sizes

    let int_value   = tuple_var.0;    // Access first element (i32)
    let float_value = tuple_var.1;  // Access second element (f64)
    let char_value  = tuple_var.2;   // Access third element (char)

    // Array (fixed length)
    let array_var: [i32; 5] = [1, 2, 3, 4, 5];          // Size = element_type_size * length

    // String types
    let string_literal = "Hello";                       // &str - string slice (fat pointer: 2 * usize)
    let string_owned = String::from("Hello");           // Heap allocated, size varies

    // Unit type
    // Zero bytes, used for functions that return nothing : fn func() -> () {}  == fn func() {}
    let unit_var: () = (); 
}
