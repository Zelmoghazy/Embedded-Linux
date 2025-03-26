// COMPREHENSIVE RUST OWNERSHIP EXAMPLES

// 1. BASIC OWNERSHIP
fn basic_ownership() 
{
    println!("\n--- BASIC OWNERSHIP ---");
    
    // Variable binding creates ownership
    let s1 = String::from("hello");
    println!("s1: {}", s1);
    
    // Ownership moves when assigning to another variable
    let s2 = s1;
    
    // This would cause an error - s1's ownership moved to s2
    // println!("{}", s1);  // ERROR: value used after move
    
    // This works fine - s2 now owns the string
    println!("s2: {}", s2);
    
    // Primitives are copied, not moved
    let x = 5;
    let y = x;
    println!("x: {}, y: {}", x, y);  // Both are accessible
}

// 2. OWNERSHIP TRANSFER TO FUNCTIONS
fn ownership_transfer() 
{
    println!("\n--- OWNERSHIP TRANSFER ---");
    
    let s = String::from("hello");
    println!("Before calling function: {}", s);
    
    // Ownership of s is moved to the take_ownership function
    take_ownership(s);
    
    // Can't use s anymore
    // println!("{}", s);  // ERROR: value used after move
    
    let x = 5;
    println!("Before calling function: {}", x);
    
    // Copy types like integers don't transfer ownership
    makes_copy(x);
    
    // We can still use x
    println!("After calling function: {}", x);
}

fn take_ownership(some_string: String) 
{
    println!("In take_ownership: {}", some_string);
    // some_string goes out of scope and `drop` is called,
    // memory is freed
}

fn makes_copy(some_integer: i32) 
{
    println!("In makes_copy: {}", some_integer);
    // some_integer goes out of scope, nothing special happens
}

// 3. RETURNING OWNERSHIP
fn returning_ownership() {
    println!("\n--- RETURNING OWNERSHIP ---");
    
    let s1 = gives_ownership();  // gives_ownership moves its return value into s1
    println!("From gives_ownership: {}", s1);
    
    let s2 = String::from("hello");
    println!("Before takes_and_gives_back: {}", s2);
    
    let s3 = takes_and_gives_back(s2);  // s2 is moved into the function
                                        // and the return value is moved into s3
    
    // println!("{}", s2);  // ERROR: s2 was moved
    println!("After takes_and_gives_back: {}", s3);
}

fn gives_ownership() -> String {
    let some_string = String::from("yours");
    some_string  // Returns ownership to the calling function
}

fn takes_and_gives_back(a_string: String) -> String {
    println!("In takes_and_gives_back: {}", a_string);
    a_string  // Returns ownership of the same string back to the caller
}

// 4. BORROWING WITH REFERENCES
fn borrowing_with_references() 
{
    println!("\n--- BORROWING WITH REFERENCES ---");
    
    let s1 = String::from("hello");
    
    // Pass a reference to s1 - borrowing rather than taking ownership
    let len = calculate_length(&s1);
    
    // s1 is still valid here
    println!("The length of '{}' is {}.", s1, len);
    
    // Mutable references
    let mut s = String::from("hello");
    println!("Before change: {}", s);
    
    change(&mut s);
    
    println!("After change: {}", s);
    
    // Demonstrating reference rules
    let mut s = String::from("reference rules");
    
    {
        let r1 = &mut s;
        println!("Mutable reference r1: {}", r1);
        // r1 goes out of scope here
    }
    
    // This is OK because r1 is no longer in scope
    let r2 = &mut s;
    println!("Mutable reference r2: {}", r2);
    
    // Multiple immutable references are allowed
    let s = String::from("hello");
    let r1 = &s;
    let r2 = &s;
    println!("r1: {}, r2: {}", r1, r2);
    
    // But can't have a mutable reference with immutable ones
    // let r3 = &mut s;  // ERROR
    // println!("{}, {}, {}", r1, r2, r3);
}

fn calculate_length(s: &String) -> usize {
    s.len()
    // s goes out of scope, but because it's just a reference,
    // the String it refers to is not dropped
}

fn change(some_string: &mut String) {
    some_string.push_str(", world");
}

// 5. OWNERSHIP IN STRUCTS
fn ownership_in_structs() 
{
    println!("\n--- OWNERSHIP IN STRUCTS ---");
    
    #[derive(Debug)]
    struct Person {
        name: String,
        age: u32,
    }
    
    // Person owns its fields
    let person = Person {
        name: String::from("Alice"),
        age: 30,
    };
    
    println!("Person: {:?}", person);
    
    // We can borrow fields
    let name_ref = &person.name;
    println!("Borrowed name: {}", name_ref);
    
    // Destructuring moves fields out
    let Person { name, age } = person;
    
    // Can't use person anymore, ownership moved
    // println!("{:?}", person);  // ERROR
    
    println!("Destructured - Name: {}, Age: {}", name, age);
}

// 6. SLICE TYPE EXAMPLE
fn slice_type_example() 
{
    println!("\n--- SLICE TYPES ---");
    
    let s = String::from("hello world");
    
    // String slices are references to parts of a string
    let hello = &s[0..5];
    let world = &s[6..11];
    
    println!("Slices: '{}' and '{}'", hello, world);
    
    // Function that works with slices
    let first = first_word(&s);
    println!("First word: {}", first);
    
    // String literals are slices
    let literal = "Hello, world!";  // Type is &str
    println!("String literal (slice): {}", literal);
}

fn first_word(s: &str) -> &str 
{
    let bytes = s.as_bytes();
    
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[0..i];
        }
    }
    
    &s[..]
}

// 7. OWNERSHIP IN COLLECTIONS
fn ownership_in_collections() 
{
    println!("\n--- OWNERSHIP IN COLLECTIONS ---");
    
    // Vector owns its elements
    let mut v = Vec::new();
    v.push(String::from("hello"));
    v.push(String::from("world"));
    
    // Accessing elements by reference preserves ownership
    let first = &v[0];
    println!("First element: {}", first);
    
    // Removing an element takes ownership
    let removed = v.remove(1);
    println!("Removed element: {}", removed);
    
    // Using an iterator consumes the vector if not borrowed
    for word in &v {
        println!("Borrowed word from vector: {}", word);
    }
    
    // v is still valid here because we used a reference in the for loop
    println!("Vector after iteration: {:?}", v);
    
    // Moving elements out with into_iter()
    for word in v.into_iter() {
        println!("Owned word from vector: {}", word);
    }
    
    // v is no longer valid here
    // println!("{:?}", v);  // ERROR: value used after move
}

fn main() 
{
    basic_ownership();
    ownership_transfer();
    returning_ownership();
    borrowing_with_references();
    ownership_in_structs();
    slice_type_example();
    ownership_in_collections();
}
