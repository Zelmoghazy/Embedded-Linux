// BASIC MATCH WITH NUMBERS
fn basic_number_match() 
{
    let country_code = 999;
    
    let country = match country_code {
        44 => "UK",
        46 => "Sweden",
        7  => "Russia",
        1..=1000 => "unknown", // inclusive range ... is deprecated
        _ => "invalid",        // try commenting this out - must cover all cases!
    };
    println!("the country with code {} is {}", country_code, country);

    let x = false;
    
    let s = match x {
        true => "yes",
        false => "no",
    };
    println!("{}", s);


    let number = 13;
    
    match number {
        // Single value
        0 => println!("Zero"),
        // Multiple values
        1 | 2 => println!("One or Two"),
        // Range
        3..=10 => println!("Between 3 and 10"),
        // Catch-all pattern
        _ => println!("Greater than 10"),
    }
}

// MATCH WITH VARIABLES AND BINDING
fn variable_binding_match() 
{
    let x = 5;
    
    match x {
        n @ 1..=5 => println!("Matched number {} in range 1-5", n),
        n @ 6..=10 => println!("Matched number {} in range 6-10", n),
        _ => println!("Number out of ranges"),
    }
}

// MATCH WITH OPTIONS
fn option_matching() 
{
    let some_number = Some(42);
    let none_number: Option<i32> = None;
    
    match some_number {
        Some(42) => println!("Found forty-two!"),
        Some(n) => println!("Found another number: {}", n),
        None => println!("No number found"),
    }
    
    // Match with if-guard
    match some_number {
        Some(n) if n > 50 => println!("Large number"),
        Some(n) if n < 0 => println!("Negative number"),
        Some(n) => println!("Number in range: {}", n),
        None => println!("No number"),
    }
}

// MATCH WITH ENUMS
#[derive(Debug)]
enum Color {
    Red,
    Green,
    Blue,
    RGB(u8, u8, u8),
    HSV{h: u16, s: u8, v: u8},
}

fn enum_matching() 
{
    let color = Color::RGB(255, 0, 0);
    
    match color {
        Color::Red   => println!("Basic red"),
        Color::Green => println!("Basic green"),
        Color::Blue  => println!("Basic blue"),
        Color::RGB(r, g, b) => println!("RGB: ({}, {}, {})", r, g, b),
        Color::HSV{h, s, v} => println!("HSV: ({}, {}, {})", h, s, v),
    }
}

// MATCH WITH REFERENCES
fn reference_matching() 
{
    let reference = &4;
    
    match reference {
        &val => println!("Got value: {}", val),
    }
    
    // Alternative way using ref
    let value = 5;
    match value {
        ref r => println!("Got reference to {}", r),
    }
    
    // Mutable references
    let mut mut_value = 6;
    match mut_value {
        ref mut m => {
            *m += 10;
            println!("Added 10: {}", m);
        },
    }
}

// MATCH WITH STRUCTS
#[derive(Debug)]
struct Point {
    x: i32,
    y: i32,
}

fn struct_matching() 
{
    let point = Point { x: 0, y: 7 };
    
    match point {
        Point { x, y: 0 } => println!("On x axis at {}", x),
        Point { x: 0, y } => println!("On y axis at {}", y),
        Point { x, y } => println!("At coordinates: ({}, {})", x, y),
    }
}

// MATCH WITH TUPLES
fn tuple_matching() 
{
    let tuple = (1, String::from("hello"), true);
    
    match tuple {
        (1, _, _) => println!("First element is 1"),
        (_, s, _) if s == "hello" => println!("Second element is 'hello'"),
        (_, _, true) => println!("Third element is true"),
        _ => println!("No match"),
    }
}

// MATCH WITH WILDCARD PATTERNS
fn wildcard_patterns() 
{
    let numbers = (2, 4, 8, 16, 32);
    
    match numbers {
        (first, .., last) => {
            println!("First: {}, Last: {}", first, last);
        }
    }
}

// MATCH WITH GUARDS
fn match_guards() 
{
    let pair = (2, -2);
    
    match pair {
        (x, y) if x == y => println!("Equal"),
        (x, y) if x + y == 0 => println!("Sum to zero"),
        (x, y) if x % 2 == 0 && y % 2 == 0 => println!("Both even"),
        _ => println!("No match"),
    }
}

// MATCH IN FUNCTION RETURN
fn get_age_category(age: u32) -> &'static str 
{
    match age {
        0..=12 => "Child",
        13..=19 => "Teenager",
        20..=59 => "Adult",
        60.. => "Senior",
    }
}

fn main() 
{
    println!("=== Basic Number Match ===");
    basic_number_match();
    
    println!("\n=== Variable Binding Match ===");
    variable_binding_match();
    
    println!("\n=== Option Matching ===");
    option_matching();
    
    println!("\n=== Enum Matching ===");
    enum_matching();
    
    println!("\n=== Reference Matching ===");
    reference_matching();
    
    println!("\n=== Struct Matching ===");
    struct_matching();
    
    println!("\n=== Tuple Matching ===");
    tuple_matching();
    
    println!("\n=== Wildcard Patterns ===");
    wildcard_patterns();
    
    println!("\n=== Match Guards ===");
    match_guards();
    
    println!("\n=== Age Categories ===");
    println!("Age 10: {}", get_age_category(10));
    println!("Age 15: {}", get_age_category(15));
    println!("Age 30: {}", get_age_category(30));
    println!("Age 70: {}", get_age_category(70));
}


