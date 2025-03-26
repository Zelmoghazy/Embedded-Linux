fn main() {
    // 1. Basic Slicing
    let arr = [1, 2, 3, 4, 5];
    
    let slice = &arr[1..4]; // Slice from index 1 to 3 (exclusive)
    println!("Basic Slice: {:?}", slice); // Output: [2, 3, 4]

    // 2. Slicing with Open Range
    let slice_from_start = &arr[..3]; // Slice from start to index 2
    println!("Slice from start: {:?}", slice_from_start); // Output: [1, 2, 3]

    let slice_to_end = &arr[2..]; // Slice from index 2 to end
    println!("Slice to end: {:?}", slice_to_end); // Output: [3, 4, 5]

    let full_slice = &arr[..]; // Slice the entire array
    println!("Full slice: {:?}", full_slice); // Output: [1, 2, 3, 4, 5]

    // 3. Mutable Slices
    let mut arr_mut = [10, 20, 30, 40, 50];
    let slice_mut = &mut arr_mut[1..4]; // Mutable slice
    slice_mut[0] = 200; // Modify the slice
    println!("Modified array: {:?}", arr_mut); // Output: [10, 200, 30, 40, 50]

    // 4. String Slices
    let s = String::from("Hello, Rust!");
    let hello = &s[0..5]; // Slice the string
    let rust = &s[7..11]; // Slice the string
    println!("String slices: '{}' and '{}'", hello, rust); // Output: 'Hello' and 'Rust'

    // 5. Slicing a Vector
    let vec = vec![1, 2, 3, 4, 5];
    let vec_slice = &vec[1..4]; // Slice a vector
    println!("Vector slice: {:?}", vec_slice); // Output: [2, 3, 4]

    // 6. Slicing with Negative Indices (using `len()`)
    let len = arr.len();
    let slice_from_end = &arr[len - 3..]; // Slice last 3 elements
    println!("Slice from end: {:?}", slice_from_end); // Output: [3, 4, 5]

    // 7. Slicing with Steps (using `chunks` or `windows`)
    let chunked = arr.chunks(2); // Split into chunks of size 2
    println!("Chunks of 2:");
    for chunk in chunked {
        println!("{:?}", chunk); // Output: [1, 2], [3, 4], [5]
    }

    let windowed = arr.windows(3); // Create overlapping windows of size 3
    println!("Windows of 3:");
    for window in windowed {
        println!("{:?}", window); // Output: [1, 2, 3], [2, 3, 4], [3, 4, 5]
    }

    // 8. Slicing with Pattern Matching
    match slice {
        [2, 3, 4] => println!("Slice matches [2, 3, 4]"),
        _ => println!("Slice does not match [2, 3, 4]"),
    }

    // 9. Slicing and Iteration
    for element in slice {
        println!("Element in slice: {}", element); // Output: 2, 3, 4
    }

    // 10. Slicing and Functions
    let sum = sum_slice(slice);
    println!("Sum of slice: {}", sum); // Output: 9

    // 11. Slicing with `split_at`
    let (left, right) = arr.split_at(3); // Split array at index 3
    println!("Left: {:?}, Right: {:?}", left, right); // Output: Left: [1, 2, 3], Right: [4, 5]

    // 12. Slicing with `split_first` and `split_last`
    if let Some((first, rest)) = arr.split_first() {
        println!("First: {}, Rest: {:?}", first, rest); // Output: First: 1, Rest: [2, 3, 4, 5]
    }

    if let Some((last, rest)) = arr.split_last() {
        println!("Last: {}, Rest: {:?}", last, rest); // Output: Last: 5, Rest: [1, 2, 3, 4]
    }

    // 13. Slicing with `get` (Safe Indexing)
    if let Some(element) = arr.get(2) {
        println!("Element at index 2: {}", element); // Output: 3
    }

    if let Some(element) = arr.get(10) {
        println!("Element at index 10: {}", element); // This won't run
    } else {
        println!("Index 10 is out of bounds");
    }

    // 14. Slicing with `split` (String)
    let words: Vec<&str> = s.split(' ').collect(); // Split string by space
    println!("Words: {:?}", words); // Output: ["Hello,", "Rust!"]

    // 15. Slicing with `rsplit` (Reverse Split)
    let reversed_words: Vec<&str> = s.rsplit(' ').collect(); // Reverse split
    println!("Reversed words: {:?}", reversed_words); // Output: ["Rust!", "Hello,"]
}

// Helper function to sum a slice
fn sum_slice(slice: &[i32]) -> i32 {
    slice.iter().sum()
}