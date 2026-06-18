#include <iostream>
#include <memory>
#include <vector>


/*
    A smart pointer is an object that behaves like a pointer. It has the special feature that the
    object it points to is deleted when the pointer is deleted. Smart pointers are convenient for
    objects stored in dynamically allocated memory, using new. The purpose of using smart
    pointers is to make sure the object is deleted properly and the memory released when the
    object is no longer used. A smart pointer may be regarded as a simple way to implement a
    data container or a dynamically sized array without defining a container class.
    The C++11 standard defines smart pointers as std::unique_ptr and std::shared_ptr. 

    std::unique_ptr has the feature that there is always one, and
    only one pointer that owns the allocated object. Ownership is transferred from one
    unique_ptr to another by assignment.

    shared_ptr allows multiple pointers to the same object.

    Smart pointers can be useful in the situation where the logic structure of a program dictates
    that an object must be dynamically created by one function and later deleted by another
    function and these two functions are unrelated to each other (not member of the same
    class). If the same function or class is responsible for creating and deleting the object then
    you do not need a smart pointer.
 */

/* 
* Features :
    - Exclusive ownership: A unique_ptr exclusively owns the object it points to. 
        - There can't be two unique_ptrs managing the same object.
    - Automatic deletion: When a unique_ptr goes out of scope, it automatically deletes
      the object it owns, preventing memory leaks.
    - Move semantics: Ownership can be transferred between unique_ptrs using std::move().
        - Copying is not allowed.
    - Null state: A unique_ptr can be empty (null). You can check this with if(ptr) or if(!ptr).
    - Custom deleters: You can specify custom deletion behavior if needed.
    - Array support: unique_ptr can manage arrays with unique_ptr<T[]>.
    - No overhead: unique_ptr is designed to be as efficient as raw pointers in most cases.
        - there is no extra cost in accessing but there is in creation, deletion or movement
          of a smart pointer
    - Standard container compatible: You can use unique_ptr in standard containers like vector or map.
    - Make_unique: C++14 introduced std::make_unique for safer object creation.
    - Converting to shared_ptr: You can convert a unique_ptr to a shared_ptr if shared ownership
      becomes necessary.
 */

class Resource {
private:
    std::string name;

public:
    Resource(const std::string& n) : name(n) {
        std::cout << "Resource " << name << " created.\n";
    }

    ~Resource() {
        std::cout << "Resource " << name << " destroyed.\n";
    }

    void use() {
        std::cout << "Using resource " << name << ".\n";
    }
};

// Function that takes ownership of a unique_ptr
void takeOwnership(std::unique_ptr<Resource> res) {
    res->use();
    // unique_ptr will be automatically destroyed when this function ends
}

// Function that takes ownership of a unique_ptr
void refPointer(const std::unique_ptr<Resource> &res) {
    res->use();
    // unique_ptr will be automatically destroyed when this function ends
}

// Function that returns a unique_ptr
std::unique_ptr<Resource> createResource(const std::string& name) {
    return std::make_unique<Resource>(name);
}

int main(void) 
{
    // Creating a unique_ptr
    std::unique_ptr<Resource> res1 = std::make_unique<Resource>("res1");
    //auto res1 = std::make_unique<Resource>("res1");
    
    res1->use();

    // Moving ownership [cannot copy]
    std::unique_ptr<Resource> res2 = std::move(res1);
    res2->use();

    // res1 is now nullptr
    if (!res1) {
        std::cout << "res1 is null\n";
    }

    // Passing unique_ptr to a function (transfers ownership) 
    takeOwnership(std::move(res2));

    if (!res2) {
        std::cout << "res2 is null\n";
    }

    // Getting a unique_ptr from a function
    auto res3 = createResource("res3");

    refPointer(res3);

    // Still has ownership;
    res3->use();


    std::unique_ptr<Resource[]> unique_res_arr(new Resource[3]{Resource("First"),Resource("Second"),Resource("Third")});

    for (int i = 0; i < 3; ++i) {
        unique_res_arr[i].use();
    }

    // Using unique_ptr in containers
    std::vector<std::unique_ptr<Resource>> resourceVector;
    resourceVector.push_back(std::make_unique<Resource>("vecRes1"));
    resourceVector.push_back(std::make_unique<Resource>("vecRes2"));

    for (const auto& res : resourceVector) {
        res->use();
    }

    auto fn_delete = [](int *ptr){std::cout<<"delete\n";delete ptr;};

    std::unique_ptr<int,decltype(fn_delete)> int_ptr(new int(32),fn_delete);


    // Everything will be automatically cleaned up when main() ends

    return 0;
}