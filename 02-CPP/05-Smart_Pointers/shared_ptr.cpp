#include <iostream>
#include <memory>  

/*
    - shared pointers manages shared ownership of a dynamically allocated object through reference counting.
    - Multiple shared_ptr instances can own the same object, and the object is automatically deallocated 
      when the last shared_ptr is destroyed.
    - It supports thread-safe reference counting, custom deleters, and can work with std::weak_ptr to 
      avoid circular dependencies.
    - While it simplifies memory management and prevents leaks, it introduces some overhead due to 
      reference counting and thread safety.
*/

class MyClass {
public:
    MyClass() {
        std::cout << "MyClass Constructor\n";
    }
    ~MyClass() {
        std::cout << "MyClass Destructor\n";
    }
    void display() const {
        std::cout << "MyClass display method\n";
    }
};

int main(void) 
{
    // Creating a shared_ptr to manage a new MyClass instance
    std::shared_ptr<MyClass> ptr1 = std::make_shared<MyClass>();
    // auto ptr1 = std::make_shared<MyClass>();

    // Use the shared pointer to access the object
    ptr1->display();

    {
        // Creating another shared_ptr that shares ownership with ptr1
        std::shared_ptr<MyClass> ptr2 = ptr1;
        std::cout << "Reference count: " << ptr1.use_count() << "\n";  // Output the reference count

        // Accessing the object using the second shared pointer
        ptr2->display();
    }  // ptr2 goes out of scope here, but the object is not deleted since ptr1 still owns it

    std::cout << "Reference count after ptr2 goes out of scope: " << ptr1.use_count() << "\n";

    // Object is automatically deleted when ptr1 goes out of scope at the end of main
    return 0;
}
