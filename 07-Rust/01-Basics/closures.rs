// 1. Basic closure syntax
fn basic_closure() {
    let add = |x, y| x + y;
    println!("Basic closure: {}", add(2, 3));
}

// 2. Closure capturing environment variables
fn capturing_closure() {
    let multiplier = 3;
    let multiply = |x| x * multiplier;
    println!("Capturing closure: {}", multiply(5));
}

// 3. Closure type annotations
fn typed_closure() {
    let sum: Box<dyn Fn(i32, i32) -> i32> = Box::new(|x, y| x + y);
    println!("Typed closure: {}", sum(4, 5));
}

// 4. Closure with move semantics
fn move_closure() {
    let data = vec![1, 2, 3];
    let print_data = move || {
        println!("Moved data: {:?}", data);
    };
    // data is no longer accessible here
    print_data();
}

// 5. Closure as function parameter
fn apply_operation<F>(x: i32, y: i32, operation: F) -> i32 
where 
    F: Fn(i32, i32) -> i32 
{
    operation(x, y)
}

fn closure_as_parameter() {
    let multiply = |x, y| x * y;
    let result = apply_operation(4, 5, multiply);
    println!("Closure as parameter: {}", result);
}

// 6. Closure with mutable capture
fn mutable_closure() {
    let mut counter = 0;
    let mut increment = || {
        counter += 1;
        println!("Counter: {}", counter);
    };
    
    increment();
    increment();
}

// 7. Advanced: Closure returning closure
fn create_counter() -> Box<dyn Fn() -> i32> {
    let mut count = 0;
    Box::new(move || {
        count += 1;
        count
    })
}

fn closure_returning_closure() {
    let counter = create_counter();
    println!("Count 1: {}", counter());
    println!("Count 2: {}", counter());
}

// 8. Complex: Closure with multiple capture types
fn complex_closure() {
    let mut vec1 = vec![1, 2, 3];
    let vec2 = vec![4, 5, 6];
    
    let mut closure = move || {
        vec1.push(4);  // Mutable borrow
        println!("Vec1: {:?}", vec1);
        println!("Vec2: {:?}", vec2);  // Immutable borrow
    };
    
    closure();
}

fn main() {
    println!("1. Basic Closure:");
    basic_closure();
    
    println!("\n2. Capturing Closure:");
    capturing_closure();
    
    println!("\n3. Typed Closure:");
    typed_closure();
    
    println!("\n4. Move Closure:");
    move_closure();
    
    println!("\n5. Closure as Parameter:");
    closure_as_parameter();
    
    println!("\n6. Mutable Closure:");
    mutable_closure();
    
    println!("\n7. Closure Returning Closure:");
    closure_returning_closure();
    
    println!("\n8. Complex Closure:");
    complex_closure();
}