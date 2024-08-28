#include <iostream>
#include <map>
#include <string>

int main() {
    // Creating a multimap where the key is an integer and the value is a string
    std::multimap<int, std::string> students;

    // Inserting elements into the multimap
    students.insert({101, "Alice"});
    students.insert({102, "Bob"});
    students.insert({101, "Charlie"});
    students.insert({103, "David"});
    students.insert({102, "Eve"});
    students.insert({101, "Frank"});

    // Displaying all elements in the multimap
    std::cout << "Students in the multimap:\n";
    for (const auto& entry : students) {
        std::cout << "ID: " << entry.first << ", Name: " << entry.second << '\n';
    }

    // Finding all students with a specific ID (e.g., 101)
    std::cout << "\nStudents with ID 101:\n";
    auto range = students.equal_range(101);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "ID: " << it->first << ", Name: " << it->second << '\n';
    }

    // Erasing students with a specific ID (e.g., 102)
    std::cout << "\nErasing students with ID 102:\n";
    students.erase(102);

    // Displaying all elements in the multimap after erasure
    std::cout << "\nStudents in the multimap after erasure:\n";
    for (const auto& entry : students) {
        std::cout << "ID: " << entry.first << ", Name: " << entry.second << '\n';
    }

    return 0;
}
