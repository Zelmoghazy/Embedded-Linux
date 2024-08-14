#include <iostream>

int main(void)
{
    // Dynamic memory allocation

    int* arr = new int[5];

    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 10;
    }

    std::cout << "Array values: ";
    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Free the allocated array memory
    delete[] arr;
    arr = nullptr;

    /* ------------------------------ */
}

