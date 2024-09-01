#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

/*
    RAII (Resource Acquisition Is Initialization) is a programming idiom in C++ that ties resource management to object lifetime
        - Resources (memory, files, locks) are acquired in a constructor.
        - Resources are released in the corresponding destructor.
        - Objects are typically allocated on the stack, ensuring automatic cleanup.

    Benefits:
        - Automatic resource management
        - Exception safety (exceptions thrown may cause the allocated memory not to be freed and result in a memory leak. )
        - Prevents resource leaks


  */

class FileHandler {
private:
    std::fstream file;
    std::string  filename;

public:
    // Constructor: opens the file
    FileHandler(const std::string& name) : filename(name) 
    {
        file.open(filename, std::ios::in | std::ios::out | std::ios::app);
        if (!file.is_open()) {
            // If no destructor and exception is thrown here the file is never closed
            throw std::runtime_error("Unable to open file: " + filename);
        }
        std::cout << "File opened: " << filename << std::endl;
    }

    // Destructor: closes the file
    ~FileHandler() {
        if (file.is_open()) {
            file.close();
            std::cout << "File closed: " << filename << std::endl;
        }
    }

    // Write data to the file
    void write(const std::string& data) {
        if (!file.is_open()) {
            throw std::runtime_error("File is not open");
        }
        file << data << std::endl;
    }

    // Read data from the file
    std::string read() {
        if (!file.is_open()) {
            throw std::runtime_error("File is not open");
        }
        std::string content;
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.clear();  // Clear EOF flag
        file.seekg(0); // Reset file pointer to beginning
        return content;
    }

    // Prevent copying
    FileHandler(const FileHandler&) = delete;
    FileHandler& operator=(const FileHandler&) = delete;
};

// Example usage
int main() 
{
    try {
        FileHandler file("example.txt");
        file.write("Hello, RAII!");
        std::cout << "File contents: " << file.read() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}