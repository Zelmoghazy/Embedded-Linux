// BASIC CONSTANT DECLARATION
// Constants must have type annotations
const MAX_POINTS: u32 = 100_000;
const PI: f64 = 3.141_592_653_589_793;

// Constants can be used in constant expressions
const SECONDS_IN_HOUR: u32 = 60 * 60;  // 3600
const SECONDS_IN_DAY: u32 = SECONDS_IN_HOUR * 24;  // 86400

// String literals in constants
const GREETING: &str = "Hello, World!";
const ERROR_MESSAGE: &str = "An error occurred";

// Using const in expressions
const RECTANGLE_WIDTH: u32 = 30;
const RECTANGLE_HEIGHT: u32 = 20;
const RECTANGLE_AREA: u32 = RECTANGLE_WIDTH * RECTANGLE_HEIGHT;

// STATIC VARIABLES
// Static variables have a fixed memory location
static PROGRAM_NAME: &str = "My Rust Program";
// Mutable static variables are unsafe
static mut COUNTER: u32 = 0;

// Example of constants in a struct
struct Configuration {
    max_connections: u32,
    timeout: u32,
}

impl Configuration {
    // Constants in implementation blocks
    const DEFAULT_MAX_CONNECTIONS: u32 = 100;
    const DEFAULT_TIMEOUT: u32 = 30;
    
    fn new() -> Self {
        Configuration {
            max_connections: Self::DEFAULT_MAX_CONNECTIONS,
            timeout: Self::DEFAULT_TIMEOUT,
        }
    }
    
    fn with_custom_timeout(timeout: u32) -> Self {
        Configuration {
            max_connections: Self::DEFAULT_MAX_CONNECTIONS,
            timeout,
        }
    }
}

// Constants in enums
enum HttpStatus {
    Ok = 200,
    NotFound = 404,
    InternalServerError = 500,
}

// Example of using constants in functions
fn is_valid_score(score: u32) -> bool {
    const MIN_SCORE: u32 = 0;
    const MAX_SCORE: u32 = 100;
    
    score >= MIN_SCORE && score <= MAX_SCORE
}

// Constants with different integer types
const BYTE_MASK: u8      = 0xFF;
const PORT_NUMBER: u16   = 8080;
const MAX_FILE_SIZE: u64 = 10_000_000;

// Constants with different number formats
const BINARY: u8 = 0b1111_0000;  // Binary
const OCTAL: u16 = 0o744;        // Octal
const HEX: u32 = 0xDEAD_BEEF;    // Hexadecimal

// Array with constant size
const ARRAY_SIZE: usize = 4;
const FIXED_ARRAY: [i32; ARRAY_SIZE] = [1, 2, 3, 4];

fn main() 
{
    // Using basic constants
    println!("Maximum points: {}", MAX_POINTS);
    println!("Pi: {}", PI);
    println!("Seconds in a day: {}", SECONDS_IN_DAY);
    println!("Greeting: {}", GREETING);
    
    // Using constants in calculations
    let circle_area = PI * 10.0 * 10.0;
    println!("Circle area: {}", circle_area);
    
    // Using struct constants
    let config = Configuration::new();
    println!("Default max connections: {}", Configuration::DEFAULT_MAX_CONNECTIONS);
    println!("Config timeout: {}", config.timeout);
    
    // Using enum values
    println!("HTTP OK status: {}", HttpStatus::Ok as i32);
    
    // Using constants in arrays
    let array: [i32; ARRAY_SIZE] = [0; ARRAY_SIZE];
    println!("Array with constant size: {:?}", array);
    println!("Fixed array: {:?}", FIXED_ARRAY);
    
    // Using constants in matching
    let port = PORT_NUMBER;
    match port {
        8080 => println!("Standard development port"),
        _ => println!("Other port"),
    }
    
    // Using constants in bit operations
    let value = 0xAB;
    let masked = value & BYTE_MASK;
    println!("Masked value: 0x{:X}", masked);
    
    // Using static variables (mutable static requires unsafe)
    println!("Program name: {}", PROGRAM_NAME);
    unsafe {
        COUNTER += 1;
        println!("Counter: {}", COUNTER);
    }
    
    // Using constants in function calls
    println!("Is 50 a valid score? {}", is_valid_score(50));
    println!("Is 150 a valid score? {}", is_valid_score(150));
}