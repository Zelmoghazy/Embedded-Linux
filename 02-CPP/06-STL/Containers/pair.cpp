#include <iostream>
#include <utility> // For std::pair

int main() {
    // Creating a pair where the first element is an int and the second is a std::string
    std::pair<int, std::string> myPair(1, "Hello");

    // Accessing elements of the pair
    std::cout << "First: " << myPair.first << std::endl;
    std::cout << "Second: " << myPair.second << std::endl;

    // Creating another pair using the make_pair function
    auto anotherPair = std::make_pair(2, "World");

    // Accessing elements of the second pair
    std::cout << "First of anotherPair: " << anotherPair.first << std::endl;
    std::cout << "Second of anotherPair: " << anotherPair.second << std::endl;

    return 0;
}
