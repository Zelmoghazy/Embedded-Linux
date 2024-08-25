#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    // Create an unordered_map where the key is a string and the value is an integer
    std::unordered_map<std::string, int> ageMap;

    // Insert elements into the unordered_map
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;

    // Access and print elements using keys
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;
    std::cout << "Bob's age: " << ageMap["Bob"] << std::endl;

    // Check if a key exists
    std::string name = "David";
    auto it = ageMap.find(name);
    if (it == ageMap.end()) {
        std::cout << name << " is not in the unordered_map." << std::endl;
    } else {
        std::cout << name << "'s age: " << it->second << std::endl;
    }

    // Iterate over the unordered_map and print all key-value pairs
    std::cout << "All entries in the unordered_map:" << std::endl;
    for (const auto& pair : ageMap) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    // Erase an element
    ageMap.erase("Bob");

    // Print unordered_map contents after deletion
    std::cout << "Entries in the unordered_map after deleting Bob:" << std::endl;
    for (const auto& pair : ageMap) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    return 0;
}
