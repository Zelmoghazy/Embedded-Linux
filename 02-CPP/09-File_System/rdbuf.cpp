#include <iostream>
#include <fstream>

int main(void) 
{
    // Create an ofstream object to write to a file
    std::ofstream file("./data/output.txt");

    // Save the original buffer of std::cout
    std::streambuf* coutBuf = std::cout.rdbuf();

    // Redirect std::cout to the file
    std::cout.rdbuf(file.rdbuf());

    // Now this will write to the file instead of the console
    std::cout << "This line is written to the file 'output.txt'." << std::endl;

    // Restore the original buffer (redirect std::cout back to the console)
    std::cout.rdbuf(coutBuf);

    // Now this will write to the console again
    std::cout << "This line is written to the console." << std::endl;

    // Close the file
    file.close();

    return 0;
}
