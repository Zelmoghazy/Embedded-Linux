#include <cstddef>
#include <iostream>

int main(void)
{
    // Dynamic memory allocation

    int* ptr = new int{42};
    std::cout << "Value: " << *ptr << std::endl;

    delete ptr;
    ptr = nullptr;

    /* ----------------------------------------------- */

    // array of objects are created by calling new[]
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
    // arrays of objects are destructed by calling delete[]
    delete[] arr;
    arr = nullptr;

    /* ------------------------------ */
}

