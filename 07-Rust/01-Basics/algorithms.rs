// Sorting
let mut numbers = vec![3, 1, 4, 1, 5, 9];
numbers.sort();                    // Simple sort
numbers.sort_by(|a, b| b.cmp(a));  // Custom comparator
numbers.sort_unstable();           // Faster but not stable sort

// Binary Search
let numbers = vec![1, 2, 3, 4, 5];
if let Ok(index) = numbers.binary_search(&3) {
    println!("Found at index: {}", index);
}

// Searching and Finding
let numbers = vec![1, 2, 3, 4, 5];
let found = numbers.iter().find(|&&x| x == 3);
let all_greater_than = numbers.iter().all(|&x| x > 0);
let any_greater_than = numbers.iter().any(|&x| x > 4);

// Filtering and Mapping
let numbers = vec![1, 2, 3, 4, 5];
let evens: Vec<i32> = numbers.iter()
    .filter(|&&x| x % 2 == 0)
    .cloned()
    .collect();
let doubled: Vec<i32> = numbers.iter()
    .map(|&x| x * 2)
    .collect();

// Fold and Reduce
let numbers = vec![1, 2, 3, 4, 5];
let sum = numbers.iter().fold(0, |acc, &x| acc + x);
let product = numbers.iter().product::<i32>();

// Min/Max
let numbers = vec![1, 2, 3, 4, 5];
let min = numbers.iter().min();
let max = numbers.iter().max();
let min_by_key = numbers.iter().min_by_key(|&&x| x % 3);

// Partition
let numbers = vec![1, 2, 3, 4, 5];
let (evens, odds): (Vec<i32>, Vec<i32>) = 
    numbers.into_iter().partition(|&x| x % 2 == 0);

// Zip and Enumerate
let a = vec![1, 2, 3];
let b = vec![4, 5, 6];
let zipped: Vec<_> = a.iter().zip(b.iter()).collect();
let enumerated: Vec<_> = a.iter().enumerate().collect();

// Dedup and Unique
let mut numbers = vec![1, 1, 2, 2, 3, 3];
numbers.dedup();  // Removes consecutive duplicates
let unique: Vec<_> = numbers.iter().collect::<std::collections::HashSet<_>>()
    .into_iter().collect();

// Chunks and Windows
let numbers = vec![1, 2, 3, 4, 5];
for chunk in numbers.chunks(2) {
    println!("Chunk: {:?}", chunk);
}
for window in numbers.windows(3) {
    println!("Window: {:?}", window);
}

// Reverse
let mut numbers = vec![1, 2, 3, 4, 5];
numbers.reverse();
let reversed: Vec<_> = numbers.iter().rev().collect();

// Chain and Flatten
let a = vec![1, 2];
let b = vec![3, 4];
let chained: Vec<_> = a.iter().chain(b.iter()).collect();
let nested = vec![vec![1, 2], vec![3, 4]];
let flattened: Vec<_> = nested.iter().flatten().collect();

// Cycle and Repeat
let numbers = vec![1, 2, 3];
let repeated: Vec<_> = numbers.iter().cycle().take(6).collect();
let constant: Vec<i32> = std::iter::repeat(1).take(3).collect();

// Map Variants
let numbers = vec![1, 2, 3, 4, 5];

// Basic map
let doubled: Vec<i32> = numbers.iter().map(|&x| x * 2).collect();

// map_while - stops at first None
let limited: Vec<i32> = numbers.iter()
    .map_while(|&x| if x < 4 { Some(x * 2) } else { None })
    .collect();

// filter_map - combines filter and map
let evens_doubled: Vec<i32> = numbers.iter()
    .filter_map(|&x| if x % 2 == 0 { Some(x * 2) } else { None })
    .collect();

// flat_map - maps and flattens results
let nested: Vec<Vec<i32>> = vec![vec![1, 2], vec![3, 4]];
let flattened: Vec<i32> = nested.iter()
    .flat_map(|x| x.iter().map(|&y| y * 2))
    .collect();

// map with enumerate
let indexed: Vec<(usize, i32)> = numbers.iter()
    .enumerate()
    .map(|(i, &x)| (i, x * 2))
    .collect();

// map with into_iter for ownership
let owned: Vec<String> = vec!["hello", "world"]
    .into_iter()
    .map(String::from)
    .collect();

// Parallel map using rayon
use rayon::prelude::*;
let parallel_doubled: Vec<i32> = numbers.par_iter()
    .map(|&x| x * 2)
    .collect();

// Mapping with mutable state
let mut sum = 0;
let cumulative: Vec<i32> = numbers.iter()
    .map(|&x| {
        sum += x;
        sum
    })
    .collect();

// Map with Result handling
let strings = vec!["1", "2", "three", "4"];
let parsed: Vec<Result<i32, _>> = strings.iter()
    .map(|s| s.parse::<i32>())
    .collect();

// Map with multiple iterators using zip
let a = vec![1, 2, 3];
let b = vec![4, 5, 6];
let combined: Vec<i32> = a.iter()
    .zip(b.iter())
    .map(|(&x, &y)| x + y)
    .collect();