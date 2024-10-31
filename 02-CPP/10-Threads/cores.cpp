#include <iostream>
#include <thread>



int main() 
{
    unsigned int cores = std::thread::hardware_concurrency();
    if (cores == 0) {
        std::cout << "Could not determine the number of cores." << std::endl;
    } else {
        std::cout << "Number of cores: " << cores << std::endl;
    }
    getMemoryInfo();
    return 0;
}
