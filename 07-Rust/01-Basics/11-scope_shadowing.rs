// BASIC SCOPE EXAMPLES
fn basic_scope() 
{
    let x = 5;
    
    {   // New scope begins
        let y = 10;
        println!("Inner scope - x: {}, y: {}", x, y);
        // y is only valid in this scope
    }   // y goes out of scope here
    
    // println!("y: {}", y);                // This would fail - y is not in scope
    println!("Outer scope - x: {}", x);
    
    // Variables are dropped (memory is freed) in reverse order of declaration
    let first  = String::from("first");
    let second = String::from("second");
    println!("Variables will be dropped in reverse order: {}, {}", second, first);
}

// SHADOWING EXAMPLES
fn shadowing_basics() 
{
    let x = 5;
    println!("Original x: {}", x);
    
    let x = x + 1;  // Shadows previous x
    println!("Shadowed x: {}", x);
    
    {
        let x = x * 2;  // Shadows x in this scope
        println!("Shadowed x in inner scope: {}", x);
    }
    
    println!("x in outer scope remains: {}", x);
    
    // Shadowing allows type change
    let spaces = "   ";         // string type
    let spaces = spaces.len();  // number type
    println!("Spaces length: {}", spaces);
}

// SCOPE WITH FUNCTIONS
fn outer_function() 
{
    let x = 5;
    
    fn inner_function() 
    {
        // Cannot access x here
        let x = 10;  // This is a different x
        println!("x in inner_function: {}", x);
    }
    
    inner_function();
    println!("x in outer_function: {}", x);
}

// SHADOWING VS MUTABILITY
fn shadowing_vs_mut() 
{
    // Shadowing
    let shadow_num = 5;
    let shadow_num = shadow_num + 1;  // Creates new variable
    
    // Mutability
    let mut mut_num = 5;
    mut_num += 1;  // Modifies existing variable
    
    println!("Shadowed: {}, Mutated: {}", shadow_num, mut_num);
    
    // Shadowing allows type change, mutability doesn't
    let shadow_var = "hello";
    let shadow_var = shadow_var.len();
    
    let mut mut_var = "hello";
    // mut_var = mut_var.len();  // This would fail - type mismatch
}

// SCOPE AND OWNERSHIP
fn scope_and_ownership() 
{
    let s1 = String::from("hello");
    
    {
        let s2 = String::from("world");
        println!("Inside scope: {} {}", s1, s2);
    }   // s2 is dropped here
    
    // println!("s2: {}", s2);  // This would fail - s2 is out of scope
    println!("s1 still valid: {}", s1);
}

// SHADOWING IN LOOPS
fn shadowing_in_loops() 
{
    let mut count = 0;
    
    for i in 0..3 {
        let count = i + 1;  // Shadows outer count
        println!("Loop count (shadowed): {}", count);
    }
    
    println!("Final count (original): {}", count);
}

// LEXICAL SCOPING
fn lexical_scoping() 
{
    let x = 5;
    
    {
        let y = 10;
        {
            let z = 15;
            println!("Innermost scope - x: {}, y: {}, z: {}", x, y, z);
        }   // z goes out of scope
        println!("Middle scope - x: {}, y: {}", x, y);
    }   // y goes out of scope
    println!("Outer scope - x: {}", x);
}

// SHADOWING IN MATCH EXPRESSIONS
fn shadowing_in_match()
{
    let x = Some(5);
    
    match x {
        Some(x) => println!("Matched x: {}", x),  // x shadows outer x
        None => println!("No value"),
    }
    
    println!("Original x: {:?}", x);
}

pub fn main() 
{
    println!("=== Basic Scope ===");
    basic_scope();
    
    println!("\n=== Shadowing Basics ===");
    shadowing_basics();
    
    println!("\n=== Scope with Functions ===");
    outer_function();
    
    println!("\n=== Shadowing vs Mutability ===");
    shadowing_vs_mut();
    
    println!("\n=== Scope and Ownership ===");
    scope_and_ownership();
    
    println!("\n=== Shadowing in Loops ===");
    shadowing_in_loops();
    
    println!("\n=== Lexical Scoping ===");
    lexical_scoping();
    
    println!("\n=== Shadowing in Match ===");
    shadowing_in_match();
}