#include <iostream>
#include <unordered_set>
#include <string>

// Custom hash function for a user-defined type
struct Person {
    std::string name;
    int age;

    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Hash function for the Person struct
struct PersonHash {
    std::size_t operator()(const Person& p) const {
        std::size_t h1 = std::hash<std::string>()(p.name);
        std::size_t h2 = std::hash<int>()(p.age);
        return h1 ^ (h2 << 1); // Combine the hashes
    }
};

int main() {
    // Creating an unordered_set of integers
    std::unordered_set<int> numbers = {1, 2, 3, 4, 5};

    // Inserting an element
    numbers.insert(6);

    // Finding an element
    if (numbers.find(3) != numbers.end()) {
        std::cout << "3 is in the set." << std::endl;
    }

    // Removing an element
    numbers.erase(4);

    // Iterating over the unordered_set
    std::cout << "Elements in the set: ";
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Checking size
    std::cout << "Size of the set: " << numbers.size() << std::endl;

    // Creating an unordered_set of custom objects with a custom hash function
    std::unordered_set<Person, PersonHash> people;
    people.insert({"Alice", 30});
    people.insert({"Bob", 25});

    // Iterating over the unordered_set of custom objects
    for (const auto& person : people) {
        std::cout << "Person: " << person.name << ", Age: " << person.age << std::endl;
    }

    // Checking the bucket count and load factor
    std::cout << "Bucket count: " << people.bucket_count() << std::endl;
    std::cout << "Load factor: " << people.load_factor() << std::endl;

    // Rehashing the unordered_set to a new bucket count
    people.rehash(10);
    std::cout << "New bucket count after rehashing: " << people.bucket_count() << std::endl;

    // Reserving space for future elements
    people.reserve(20);
    std::cout << "Bucket count after reserving space: " << people.bucket_count() << std::endl;

    return 0;
}
