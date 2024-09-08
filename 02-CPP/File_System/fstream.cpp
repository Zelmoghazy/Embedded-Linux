#include <iostream>
#include <fstream> // for fstream
#include <string>

int main() 
{
    // Create an instance of fstream for file I/O
    std::fstream file;

    // Open the file in write mode
    file.open("./data/example.txt", std::ios::out);

    if (file.is_open()) {
        // Write to the file
        file << "Hello, this is a test file.\n";
        file << "Writing to the file using fstream.\n";
        file.close(); // Close the file after writing
    } else {
        std::cerr << "File could not be opened for writing!" << std::endl;
        return 1;
    }

    // Open the file in read mode
    file.open("./data/example.txt", std::ios::in);
    if (file.is_open()) {
        std::string line;
        // Read the file line by line
        while (getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close(); // Close the file after reading
    } else {
        std::cerr << "File could not be opened for reading!" << std::endl;
        return 1;
    }

    return 0;
}
