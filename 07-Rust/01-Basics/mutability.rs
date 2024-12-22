// BASIC VARIABLE MUTABILITY
fn basic_mutability() {
    // Immutable by default
    let x = 5;
    // x = 6;  // This would cause a compilation error
    
    // Mutable variables
    let mut y = 5;
    y = 6;    // This is fine
    println!("Mutable value changed: {}", y);
    
    // Shadowing (creating a new variable with same name)
    let z = 5;          // immutable
    let z = z + 1;      // creates new immutable variable
    let z = z * 2;      // creates another new variable
    println!("Shadowed value: {}", z);
}

// REFERENCES AND MUTABILITY
fn reference_mutability() {
    // Mutable reference to mutable variable
    let mut value = 10;
    let ref_mut = &mut value;
    *ref_mut += 1;
    println!("Value after mutable reference modification: {}", value);
    
    // Multiple immutable references are allowed
    let value2 = 20;
    let ref1 = &value2;
    let ref2 = &value2;
    println!("Multiple immutable references: {} {}", ref1, ref2);
    
    // But only one mutable reference at a time
    let mut value3 = 30;
    let ref_mut1 = &mut value3;
    // let ref_mut2 = &mut value3;  // This would cause an error
    *ref_mut1 += 1;
    println!("Value after single mutable reference: {}", value3);
}

// STRUCT MUTABILITY
#[derive(Debug)]
struct Point {
    x: i32,
    y: i32,
}

fn struct_mutability() {
    // Immutable struct instance
    let point = Point { x: 0, y: 0 };
    // point.x = 5;  // This would cause an error
    
    // Mutable struct instance
    let mut point2 = Point { x: 0, y: 0 };
    point2.x = 5;  // This is fine
    println!("Mutable struct modified: {:?}", point2);
    
    // Partial mutability with interior mutability patterns
    struct PointWithCell {
        x: std::cell::Cell<i32>,
        y: i32,
    }
    
    let point3 = PointWithCell {
        x: std::cell::Cell::new(0),
        y: 0,
    };
    point3.x.set(5);  // Modifying interior even though point3 is immutable
    println!("Cell value: {}", point3.x.get());
}

// ARRAY AND SLICE MUTABILITY
fn array_mutability() {
    // Immutable array
    let arr = [1, 2, 3, 4, 5];
    // arr[0] = 10;  // This would cause an error
    
    // Mutable array
    let mut arr2 = [1, 2, 3, 4, 5];
    arr2[0] = 10;
    println!("Modified array: {:?}", arr2);
    
    // Mutable slice
    let mut v = vec![1, 2, 3, 4, 5];
    let slice = &mut v[..];
    slice[0] = 10;
    println!("Modified slice: {:?}", slice);
}

// CONST AND STATIC VARIABLES
const MAX_POINTS: u32 = 100_000;  // Always immutable
static mut COUNTER: u32 = 0;      // Mutable static - unsafe to modify

fn const_and_static() {
    println!("Constant value: {}", MAX_POINTS);
    
    // Modifying static mut is unsafe
    unsafe {
        COUNTER += 1;
        println!("Static counter: {}", COUNTER);
    }
}

// INTERIOR MUTABILITY PATTERNS
use std::cell::RefCell;
use std::rc::Rc;

fn interior_mutability() {
    // RefCell for runtime-checked borrowing
    let data = RefCell::new(5);
    
    // We can modify the contents even though data is immutable
    *data.borrow_mut() = 6;
    println!("RefCell value: {}", data.borrow());
    
    // Combining Rc and RefCell for shared mutable state
    let shared_data = Rc::new(RefCell::new(5));
    let cloned_data = Rc::clone(&shared_data);
    
    *shared_data.borrow_mut() += 1;
    println!("Shared data: {}", cloned_data.borrow());
}

fn main() {
    println!("=== Basic Mutability ===");
    basic_mutability();
    
    println!("\n=== Reference Mutability ===");
    reference_mutability();
    
    println!("\n=== Struct Mutability ===");
    struct_mutability();
    
    println!("\n=== Array Mutability ===");
    array_mutability();
    
    println!("\n=== Const and Static ===");
    const_and_static();
    
    println!("\n=== Interior Mutability ===");
    interior_mutability();
}