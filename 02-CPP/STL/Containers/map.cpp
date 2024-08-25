#include <iostream>
#include <map>
#include <string>

int main() {
    // Create a map where the key is a string and the value is an integer
    std::map<std::string, int> ageMap;

    // Insert elements into the map
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;

    // Access and print elements using keys
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;
    std::cout << "Bob's age: " << ageMap["Bob"] << std::endl;

    // Check if a key exists
    std::string name = "David";
    if (ageMap.find(name) == ageMap.end()) {
        std::cout << name << " is not in the map." << std::endl;
    } else {
        std::cout << name << "'s age: " << ageMap[name] << std::endl;
    }

    // Iterate over the map and print all key-value pairs
    std::cout << "All entries in the map:" << std::endl;
    for (const auto& pair : ageMap) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    // Erase an element
    ageMap.erase("Bob");

    // Print map contents after deletion
    std::cout << "Entries in the map after deleting Bob:" << std::endl;
    for (const auto& pair : ageMap) {
        std::cout << pair.first << " is " << pair.second << " years old." << std::endl;
    }

    return 0;
}
