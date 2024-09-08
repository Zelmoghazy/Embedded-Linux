#include <iostream>
#include <fstream>
#include <vector>

int main() {
    // Open the binary file in input mode and binary mode
    std::ifstream file("binary_file.bin", std::ios::in | std::ios::binary);

    // Check if the file was opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    // Seek to the end of the file to determine its size
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);  // Move back to the beginning of the file

    // Create a vector to hold the binary data
    std::vector<char> buffer(fileSize);

    // Read the binary data into the buffer
    file.read(buffer.data(), fileSize);

    // Check if reading was successful
    if (!file) {
        std::cerr << "Error: Only " << file.gcount() << " could be read." << std::endl;
    } else {
        std::cout << "Successfully read " << fileSize << " bytes from the file." << std::endl;
    }

    // Close the file
    file.close();

    // Process or output the binary data as needed
    // (For example, output the first few bytes)
    std::cout << "First 10 bytes of the file:" << std::endl;
    for (size_t i = 0; i < 10 && i < buffer.size(); ++i) {
        std::cout << std::hex << static_cast<int>(buffer[i] & 0xFF) << " ";
    }
    std::cout << std::endl;

    return 0;
}
