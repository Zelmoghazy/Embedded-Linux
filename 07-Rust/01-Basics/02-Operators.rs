// ARITHMETIC OPERATORS
fn arithmetic_operators() 
{
    // Basic arithmetic
    let a = 10;
    let b = 3;
    
    println!("Addition: {} + {} = {}", a, b, a + b);        // 13
    println!("Subtraction: {} - {} = {}", a, b, a - b);     // 7
    println!("Multiplication: {} * {} = {}", a, b, a * b);  // 30
    println!("Division: {} / {} = {}", a, b, a / b);        // 3
    println!("Remainder: {} % {} = {}", a, b, a % b);       // 1
    
    // Float arithmetic
    let x = 10.0;
    let y = 3.0;
    println!("Float division: {} / {} = {}", x, y, x / y);  // 3.3333...
    
    // Compound assignment operators
    let mut c = 5;
    c += 1;  // c = c + 1
    c -= 2;  // c = c - 2
    c *= 3;  // c = c * 3
    c /= 2;  // c = c / 2
    c %= 3;  // c = c % 3
}

// COMPARISON OPERATORS
fn comparison_operators() 
{
    let a = 5;
    let b = 10;
    
    println!("Equal: {} == {} is {}", a, b, a == b);              // false
    println!("Not Equal: {} != {} is {}", a, b, a != b);          // true
    println!("Greater than: {} > {} is {}", a, b, a > b);         // false
    println!("Less than: {} < {} is {}", a, b, a < b);            // true
    println!("Greater or equal: {} >= {} is {}", a, b, a >= b);   // false
    println!("Less or equal: {} <= {} is {}", a, b, a <= b);      // true
}

// LOGICAL OPERATORS
fn logical_operators() 
{
    let a = true;
    let b = false;
    
    println!("AND: {} && {} = {}", a, b, a && b);        // false
    println!("OR: {} || {} = {}", a, b, a || b);         // true
    println!("NOT: !{} = {}", a, !a);                    // false
    
    // Short-circuit evaluation
    let x = false;
    let lazy_eval = x && panic!("This won't execute");   // Won't panic
}

// BITWISE OPERATORS
fn bitwise_operators() 
{
    let a = 0b1010;  // 10 in binary
    let b = 0b1100;  // 12 in binary
    
    println!("Bitwise AND: {:04b} & {:04b} = {:04b}", a, b, a & b);     // 0b1000
    println!("Bitwise OR: {:04b} | {:04b} = {:04b}", a, b, a | b);      // 0b1110
    println!("Bitwise XOR: {:04b} ^ {:04b} = {:04b}", a, b, a ^ b);     // 0b0110
    println!("Bitwise NOT: !{:04b} = {:04b}", a, !a);                   // inverts all bits
    
    // Shift operators
    println!("Left shift: {:04b} << 1 = {:04b}", a, a << 1);           // 0b10100
    println!("Right shift: {:04b} >> 1 = {:04b}", a, a >> 1);          // 0b0101
    
    // Compound bitwise operators
    let mut c = 0b1010;
    c &= 0b1100;  // c = c & 0b1100
    c |= 0b0001;  // c = c | 0b0001
    c ^= 0b0011;  // c = c ^ 0b0011
    c <<= 1;      // c = c << 1
    c >>= 1;      // c = c >> 1
}

// RANGE OPERATORS
fn range_operators() 
{
    // Inclusive range: includes both start and end
    for i in 1..=5 {
        print!("{} ", i);  // Prints: 1 2 3 4 5
    }
    println!();
    
    // Exclusive range: includes start but not end
    for i in 1..5 {
        print!("{} ", i);  // Prints: 1 2 3 4
    }
    println!();
    
    // Ranges can be used in match expressions
    let number = 7;
    match number {
        1..=5 => println!("one through five"),
        6..=10 => println!("six through ten"),
        _ => println!("something else"),
    }
}

// TYPE CASTING OPERATOR
fn type_casting() 
{
    let float_num = 3.14f64;
    let int_num = float_num as i32;  // 3
    
    let char_num = 65u8 as char;     // 'A'
    let num_char = 'B' as u8;        // 66
}


fn reference_operators() 
{
    let mut x = 10;
    
    // Example 1: Immutable reference
    let ref_x = &x;       // Immutable reference to x
    println!("Immutable reference value: {}", ref_x);
    
    // Example 2: Mutable reference
    let ref_mut_x = &mut x; // Mutable reference to x
    *ref_mut_x += 1;        // Dereference and modify
    println!("After modification: {}", ref_mut_x);
    
    // Example 3: Creating new references after previous ones are dropped
    println!("Direct value: {}", x);  // OK - previous mutable borrow is dropped
    
    // Example 4: Multiple immutable references are allowed
    let ref1 = &x;
    let ref2 = &x;
    println!("Multiple references: {} {}", ref1, ref2);
    
    // Example 5: New mutable reference after immutable references are dropped
    let ref_mut_x2 = &mut x;
    *ref_mut_x2 += 1;
    println!("Final value: {}", ref_mut_x2);
}

// FUNCTION POINTER OPERATOR
fn function_pointers() 
{
    fn add_one(x: i32) -> i32 {
        x + 1
    }
    
    let fn_pointer: fn(i32) -> i32 = add_one;
    println!("Function pointer result: {}", fn_pointer(5));  // 6
}

pub fn main() 
{
    println!("=== Arithmetic Operators ===");
    arithmetic_operators();
    println!("=== Comparison Operators ===");
    comparison_operators();
    println!("=== Logical Operators ===");
    logical_operators();
    println!("=== Bitwise Operators ===");
    bitwise_operators();
    println!("=== Range Operators ===");
    range_operators();
    println!("=== Type Casting ===");
    type_casting();
    println!("=== Reference Operators ===");
    reference_operators();
    println!("=== Function Operators ===");
    function_pointers();
}