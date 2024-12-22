pub fn main() 
{
    // Example 1: Creating Strings
    let mut string1 = String::new(); // Empty String
    let string2 = String::from("Hello, Rust!"); // From a string slice
    let string3 = "This is a string slice.".to_string(); // Using to_string()
    let string4 = format!("{} and {}", "Hello", "World"); // Using format!

    println!("String1: {}", string1);
    println!("String2: {}", string2);
    println!("String3: {}", string3);
    println!("String4: {}", string4);

    // Example 2: Modifying Strings
    string1.push('A'); // Append a single character
    string1.push_str(" String"); // Append a string slice
    println!("Modified String1: {}", string1);

    // Example 3: Concatenation
    let hello = String::from("Hello");
    let world = String::from(", World!");
    let concatenated = hello + &world; // `hello` is moved
    println!("Concatenated String: {}", concatenated);

    // Example 4: String Slicing
    let rust = "Hello, Rust!";
    let hello_part = &rust[0..5]; // Slicing
    let rust_part = &rust[7..];
    println!("Hello Part: {}", hello_part);
    println!("Rust Part: {}", rust_part);

    // Example 5: Iterating Over Strings
    for char in rust.chars() {
        println!("Char: {}", char);
    }
    for byte in rust.bytes() {
        println!("Byte: {}", byte);
    }

    // Example 6: String Length and Capacity
    let length = rust.len(); // Length in bytes
    let mut capacity_example = String::with_capacity(50); // Preallocate capacity
    capacity_example.push_str("Example");
    println!("String Length: {}, Capacity: {}", length, capacity_example.capacity());

    // Example 7: Finding Substrings
    let substring_position = rust.find("Rust");
    match substring_position {
        Some(pos) => println!("Found 'Rust' at position: {}", pos),
        None => println!("Substring not found"),
    }

    // Example 8: Replacing and Removing
    let replaced = rust.replace("Rust", "World");
    let removed = rust.replace("Hello, ", ""); // Remove by replacing with an empty string
    println!("Replaced: {}", replaced);
    println!("Removed: {}", removed);

    // Example 9: Converting Between &str and String
    let slice = "This is a string slice.";
    let converted_to_string: String = slice.to_string();
    let converted_to_str: &str = &converted_to_string;

    println!("Converted to String: {}", converted_to_string);
    println!("Converted to &str: {}", converted_to_str);

    // Example 10: Advanced String Manipulation
    let mut advanced = String::from("Rust is great!");
    let words: Vec<&str> = advanced.split_whitespace().collect(); // Splitting
    println!("Words: {:?}", words);

    let uppercase = advanced.to_uppercase(); // Convert to uppercase
    println!("Uppercase: {}", uppercase);

    advanced.clear(); // Clear the string
    println!("Cleared String: '{}'", advanced);

    // Example 11: Unicode Considerations
    let emoji_string = "😀🎉🚀";
    println!("Emoji String: {}", emoji_string);
    for char in emoji_string.chars() {
        println!("Char: {}", char);
    }
    for byte in emoji_string.bytes() {
        println!("Byte: {}", byte);
    }


    // a slice that always points to a valid UTF-8 sequence
    // a view into a String
    let s: &'static str = "hi there!"; // &'static str -->
                                       // statically allocated (part of the program)

    // s = "bar"; // cannot reassign immutable

    //let a = s[0]; // cannot index

    for c in s.chars().rev()
    // reversed! also as_bytes()
    {
        println!("{}", c);
    }

    if let Some(first_char) = s.chars().nth(0) {
        println!("first letter is {}", first_char)
    }

    // heap allocated construct
    // Vec<u8>, guaranteed to be valid UTF-8

    let mut letters = String::new();
    let mut a = 'a' as u8;
    while a <= ('z' as u8) {
        letters.push(a as char);
        letters.push_str(","); // note the _str
        a = a + 1;
    }

    println!("{}", letters);

    // str from String
    let u: &str = &letters; // deref conversion
                            // there are situations when the coercion does NOT happen

    // concatenation
    // String + str
    // String + &String

    // String from str
    //let mut abc = String::from("hello world");
    let mut abc = "hello world".to_string();
    abc.remove(0);
    abc.push_str("!!!");
    println!("{}, {}", abc, abc.replace("ello", "goodbye"));
}
