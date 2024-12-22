fn while_loops() 
{
    let mut x = 1;
    while x < 1000 {
        x *= 2;

        if x == 64 {
            continue;
        }

        println!("x = {}", x);
    }

    // While loop with complex condition
    let mut vec = vec![1, 2, 3, 4, 5];
    while !vec.is_empty() {
        let item = vec.pop().unwrap();
        println!("Popped: {}", item);
    }
}

fn basic_loop() 
{
    let mut y = 1;

    // while true
    loop
    {
        y *= 2;
        println!("y = {}", y);

        // stop at 2^10
        if y == 1 << 10 {
            break;
        }
    }

    // loop_with_return
    let mut counter = 0;
    
    let result = loop {
        counter += 1;
        
        if counter == 10 {
            break counter * 2;  // Returns counter * 2
        }
    };
    
    println!("Loop result: {}", result);


    // Nested Loops with Labels 
    'outer: loop {
        println!("Entered outer loop");
        
        'inner: loop {
            println!("Entered inner loop");
            
            // Break the outer loop
            break 'outer;
        }
        
        // This println! will never be reached
        println!("This point will never be reached");
    }
}

fn for_loops()
{
    
    // 1 to 10; 11..1 won't work
    for x in 1..11
    {
        // skip 3
        if x == 3 {
            continue;
        }

        // stop at 7
        if x == 8 {
            break;
        }

        println!("x = {}", x);
    }

    // Inclusive range
    for i in 0..=3 {
        println!("Count: {}", i);
    }

    // Iterating over array
    let array = [10, 20, 30];
    for element in array.iter() {
        println!("Value: {}", element);
    }

    // Iterating with enumerate
    println!("\nEnumerate:");
    let array = [10, 20, 30];
    for (index, value) in array.iter().enumerate() {
        println!("Index: {}, Value: {}", index, value);
    }

    for (pos, y) in (30..41).enumerate() {
        println!("{}: {}", pos, y);
    }

    // Iterating over vector
    println!("\nVector iteration:");
    let vec = vec!["apple", "banana", "cherry"];
    for fruit in &vec {
        println!("Fruit: {}", fruit);
    }

    // Iterating with step_by
    for i in (0..10).step_by(2) {
        println!("Step: {}", i);
    }
}

// ITERATOR METHODS
fn iterator_methods() 
{    
    let numbers = vec![1, 2, 3, 4, 5];
    
    // map
    println!("Map:");
    let squared: Vec<i32> = numbers.iter().map(|x| x * x).collect();
    println!("Squared: {:?}", squared);
    
    // filter
    println!("\nFilter:");
    let even: Vec<&i32> = numbers.iter().filter(|x| *x % 2 == 0).collect();
    println!("Even numbers: {:?}", even);
    
    // fold
    println!("\nFold:");
    let sum = numbers.iter().fold(0, |acc, x| acc + x);
    println!("Sum: {}", sum);
}

// LOOP CONTROL PATTERNS
fn loop_control_patterns() {
    println!("\n=== Loop Control Patterns ===");
    
    // continue example
    println!("Continue pattern:");
    for i in 0..5 {
        if i % 2 == 0 {
            continue;
        }
        println!("Odd number: {}", i);
    }
    
    // break with condition
    println!("\nBreak pattern:");
    let mut sum = 0;
    for i in 1.. {  // Infinite range
        sum += i;
        if sum > 10 {
            println!("Sum exceeded 10: {}", sum);
            break;
        }
    }
    
    // while let loop
    println!("\nWhile let pattern:");
    let mut optional = Some(0);
    while let Some(i) = optional {
        if i > 3 {
            println!("Stopping at {}", i);
            optional = None;
        } else {
            println!("Current value: {}", i);
            optional = Some(i + 1);
        }
    }
}


pub fn main() 
{
    while_loops();
    basic_loop();
    for_loops();
    iterator_methods();
    loop_control_patterns();
}
