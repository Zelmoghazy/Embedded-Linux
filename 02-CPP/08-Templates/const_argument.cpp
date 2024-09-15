#include <iostream>

// Template class with a const integer template argument
template <int N>
class Array {
public:
    // Constructor that initializes the array with zeros
    Array() {
        for (int i = 0; i < N; ++i) {
            arr[i] = 0;
        }
    }

    // Method to set a value at a specific index
    void set(int index, int value) {
        if (index >= 0 && index < N) {
            arr[index] = value;
        }
    }

    // Method to get a value at a specific index
    int get(int index) const {
        if (index >= 0 && index < N) {
            return arr[index];
        }
        return -1; // Return -1 if index is out of bounds
    }

private:
    int arr[N]; // Array of size N
};

int main(void) 
{
    // Create an Array object with size 5
    Array<5> myArray;

    // Set values in the array
    myArray.set(0, 10);
    myArray.set(1, 20);
    myArray.set(2, 30);

    // Print values from the array
    std::cout << "Element at index 0: " << myArray.get(0) << std::endl;
    std::cout << "Element at index 1: " << myArray.get(1) << std::endl;
    std::cout << "Element at index 2: " << myArray.get(2) << std::endl;

    return 0;
}
