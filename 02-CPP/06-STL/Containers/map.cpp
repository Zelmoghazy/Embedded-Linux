#include <iostream>
#include <map>
#include <ostream>
#include <string>
#include <utility>

int main(void) 
{
    // Create a map where the key is a string and the value is an integer
    std::map<std::string, int> ageMap;

    // Insert elements into the map
    ageMap.insert(std::make_pair("Zeyad", 23));
    ageMap.insert({"Ahmed",50});
    ageMap.emplace("Test",15);
    ageMap["Alice"] = 30;
    ageMap["Bob"] = 25;
    ageMap["Charlie"] = 35;

    std::cout << "Size : "  << ageMap.size()  << std::endl;
    std::cout << "Empty : " << ageMap.empty() << std::endl;

    // Access and print elements using keys
    std::cout << "Alice's age: " << ageMap["Alice"] << std::endl;
    std::cout << "Bob's age: "   << ageMap["Bob"]   << std::endl;

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
