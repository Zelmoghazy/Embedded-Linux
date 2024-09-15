#include <iostream>
#include <fstream>

int main() {
    // Open a file for reading
    std::ifstream file("example.txt");
    
    // Check if the file opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 1;
    }

    char ch;

    // Read the file character by character and check the stream state
    while (file.get(ch)) {
        std::cout << ch;

        // Check if the stream is still in good condition
        if (file.good()) {
            std::cout << " (Stream is good)" << std::endl;
        }

        // Check if the end of the file has been reached
        if (file.eof()) {
            std::cout << "\nEnd of file reached." << std::endl;
            break;
        }

        // Check if there was a non-fatal read failure
        if (file.fail()) {
            std::cerr << "\nNon-fatal I/O error occurred." << std::endl;
            file.clear(); // Clear the error flag and try to continue
        }

        // Check if there was a fatal read failure
        if (file.bad()) {
            std::cerr << "\nFatal I/O error occurred." << std::endl;
            break;
        }
    }

    // If we exit the loop, check if EOF was reached
    if (file.eof()) {
        std::cout << "\nSuccessfully reached the end of the file." << std::endl;
    }

    // Close the file
    file.close();

    return 0;
}
