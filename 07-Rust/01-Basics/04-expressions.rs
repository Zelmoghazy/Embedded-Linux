fn main() {
    let result = {
        let a = 10;
        let b = 20;
        a + b  // No semicolon → this is an expression (evaluates to `30`)
    };

    println!("Result: {}", result);

    let x = {
        let y = 10;
        y * 2  // Last expression in block
    };

    // if as an Expression
    
    let num = 5;
    let is_even = if num % 2 == 0 { "Even" } else { "Odd" }; 

    println!("The number is: {}", is_even);


    // Loop Expressions

    let mut counter = 0;

    let result = loop {
        counter += 1;
        if counter == 5 {
            break counter * 2; // `break` returns a value
        }
    };

    println!("Result: {}", result);
}
