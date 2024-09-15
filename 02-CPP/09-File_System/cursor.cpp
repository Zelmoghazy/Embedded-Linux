#include <iostream>
#include <fstream>

int main() {
    // Open a file in both input and output mode (read and write)
    std::fstream file("./data/example.txt", std::ios::in | std::ios::out | std::ios::trunc);
    
    // Write some text to the file
    file << "Hello, World!";
    
    // Flush the buffer and reset the file pointer for reading
    file.flush();
    
    // Get and print the current "put" (write) pointer position
    std::streampos writePos = file.tellp();
    std::cout << "Current write position (tellp): " << writePos << std::endl;

    // Move the "get" (read) pointer to the beginning of the file
    file.seekg(0, std::ios::beg);

    // Get and print the current "get" (read) pointer position
    std::streampos readPos = file.tellg();
    std::cout << "Current read position (tellg): " << readPos << std::endl;

    // Read from the file starting at the new position
    std::string content;
    file >> content;  // Read the first word

    std::cout << "Read content: " << content << std::endl;

    // Move the write pointer to the 7th position and overwrite
    file.seekp(7, std::ios::beg);
    file << "C++";

    // Move the "get" pointer back to the beginning to read the modified content
    file.seekg(0, std::ios::beg);
    std::getline(file, content);

    std::cout << "Modified content: " << content << std::endl;

    // Close the file
    file.close();

    return 0;
}
