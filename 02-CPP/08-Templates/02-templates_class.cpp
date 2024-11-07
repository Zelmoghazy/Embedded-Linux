#include <iostream>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> elements;  // container to hold stack elements

public: 
    // Push an element onto the stack
    void push(T const& elem) {
        elements.push_back(elem);
    }

    // Pop an element from the stack
    void pop() {
        if (elements.empty()) {
            std::cout << "Stack is empty, cannot pop." << std::endl;
            return;
        }
        elements.pop_back();
    }

    // Get the top element of the stack
    T top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack is empty.");
        }
        return elements.back();
    }

    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Get the size of the stack
    size_t size() const {
        return elements.size();
    }
};

int main() 
{
    // Creating a stack of integers
    Stack<int> intStack;

    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    std::cout << "Top of int stack: " << intStack.top() << std::endl;
    std::cout << "Size of int stack: " << intStack.size() << std::endl;

    intStack.pop();
    std::cout << "Top after pop: " << intStack.top() << std::endl;

    // Creating a stack of strings
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");

    std::cout << "Top of string stack: " << stringStack.top() << std::endl;
    std::cout << "Size of string stack: " << stringStack.size() << std::endl;

    return 0;
}
