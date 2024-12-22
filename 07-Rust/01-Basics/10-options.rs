pub fn main() 
{
    let x = 3.0;
    let y = 0.0;

    let result: Option<f64> = if y != 0.0 { Some(x / y) } else { None };

    match result {
        Some(z) => println!("{}/{}={}", x, y, z),
        None => println!("cannot divide {} by {}", x, y),
    }

    if let Some(z) = result {
        println!("result = {}", z);
    }

    // Example 1: Basic usage of Option
    let some_number = Some(5);
    let no_number: Option<i32> = None;

    // Pattern matching
    match some_number {
        Some(n) => println!("Found a number: {}", n),
        None => println!("No number found."),
    }

    match no_number {
        Some(n) => println!("Found a number: {}", n),
        None => println!("No number found."),
    }

    // Example 2: Using unwrap_or and unwrap_or_else
    let default_number = some_number.unwrap_or(10); // Use 10 if None
    let computed_number = no_number.unwrap_or_else(|| {
        println!("Value is None, computing a default value...");
        20
    });

    println!("Default number: {}", default_number);
    println!("Computed number: {}", computed_number);

    // Example 3: Map and and_then for transformation
    let incremented_number = some_number.map(|n| n + 1); // Adds 1 if Some
    let squared_number = some_number.and_then(|n| {
        if n > 0 {
            Some(n * n)
        } else {
            None
        }
    });

    println!("Incremented number: {:?}", incremented_number);
    println!("Squared number: {:?}", squared_number);

    // Example 4: Chaining with Option
    fn parse_number(s: &str) -> Option<i32> {
        s.parse::<i32>().ok()
    }

    let result = parse_number("42").and_then(|n| {
        if n % 2 == 0 {
            Some(n / 2)
        } else {
            None
        }
    });

    println!("Result of chaining Option: {:?}", result);

    // Example 5: Unwrapping safely
    let maybe_value = Some("Hello, Rust!");
    if let Some(value) = maybe_value {
        println!("Value is: {}", value);
    } else {
        println!("No value found.");
    }

    // Example 6: Combining Options
    let option1 = Some(10);
    let option2 = Some(20);
    let sum = option1.zip(option2).map(|(a, b)| a + b);

    println!("Sum of two options: {:?}", sum);

    // Example 7: Default values with Option
    let custom_value = some_number.unwrap_or_else(|| {
        // This code only runs if some_number is None
        println!("some_number is None, computing default...");
        100
    });

    println!("Custom value: {}", custom_value);
}
