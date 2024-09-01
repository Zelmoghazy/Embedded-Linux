#include <iostream>
#include <cstring>

// Generic template class
template <typename T>
class Storage {
private:
    T value;

public:
    Storage(T val) : value(val) {}

    void print() const {
        std::cout << "Stored value: " << value << std::endl;
    }

    T getValue() const {
        return value;
    }
};

// Explicit specialization for char*
template <>
class Storage<char*> {
private:
    char* value;

public:
    // Constructor: making a deep copy of the char* input
    Storage(char* val) {
        value = new char[strlen(val) + 1];
        strcpy(value, val);
    }

    // Destructor: cleaning up allocated memory
    ~Storage() {
        delete[] value;
    }

    void print() const {
        std::cout << "Stored string: " << value << std::endl;
    }

    char* getValue() const {
        return value;
    }
};

// Explicit specialization for const char*
template <>
class Storage<const char*> {
private:
    const char* value;

public:
    Storage(const char* val) : value(val) {}

    void print() const {
        std::cout << "Stored constant string: " << value << std::endl;
    }

    const char* getValue() const {
        return value;
    }
};

int main() {
    // Using the generic Storage for int
    Storage<int> intStorage(100);
    intStorage.print();

    // Using the specialized Storage for char*
    char myString[] = "Hello, World!";
    Storage<char*> charStorage(myString);
    charStorage.print();

    // Using the specialized Storage for const char*
    Storage<const char*> constCharStorage("Hello, C++!");
    constCharStorage.print();

    return 0;
}
