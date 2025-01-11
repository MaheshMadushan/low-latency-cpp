#include <iostream>
#include <utility>

class LearnCopyMoveAssignementConstructors {
    public:
    int some_data;
    int* some_ptr;
    LearnCopyMoveAssignementConstructors(int _data, int* ptr) : some_data(_data),some_ptr(ptr) {};
    // copy constructor
    LearnCopyMoveAssignementConstructors(const LearnCopyMoveAssignementConstructors& other) {
        std::cout << "in const copy constructor" << std::endl;
    }
    LearnCopyMoveAssignementConstructors(LearnCopyMoveAssignementConstructors& other) { // this gets priority - not const cp ctor
        std::cout << "in non-const copy constructor" << std::endl;
    }
    // default copy constructor
    // LearnCopyMoveAssignementConstructors(const LearnCopyMoveAssignementConstructors& other) = delete;
};

const LearnCopyMoveAssignementConstructors someFunc(const LearnCopyMoveAssignementConstructors a) { // copy constructor used
    return a; // const copy constructor used since this is const
}

// if cp ctor deleted, use this pass by ref (no copies) (do not use pass by value and ref same time it is ambiguous)
// LearnCopyMoveAssignementConstructors& someFunc(LearnCopyMoveAssignementConstructors& a) {
//     std::cout << &a << std::endl; // // same address of a
//     return a; // ref returned
// }

int main() {
    int* ptr = new int{99};
    LearnCopyMoveAssignementConstructors a{9, ptr};
    std::cout << "=====================================" << std::endl;
    std::cout << "data in the non const object" << std::endl;
    std::cout << "non ptr object: " << a.some_data << std::endl;
    std::cout << "ptr object: " << *a.some_ptr << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "calling function that is using non-const copy ctor (pass by value) - object is non const" << std::endl;
    auto a1_copy = someFunc(a); // uses non const cp ctor
    a1_copy.some_data = 888;
    std::cout << "=====================================" << std::endl;
    
    
    std::cout << "calling function that is using copy ctor (pass by value) - object is non const" << std::endl;
    int* ptr_b = new int{88};
    const LearnCopyMoveAssignementConstructors b{8, ptr_b};
    auto b1 = someFunc(b); // uses const cp ctor
    std::cout << "=====================================" << std::endl;

    std::cout << &a << std::endl;
    auto a_copy = someFunc(a); // if copy ctor deleted just pass by ref, pass by value wouldn't work
    std::cout << &a_copy << std::endl; // same address of a, if some funct returned ref
    // delete a.some_ptr; // invalidates the some_ptr of copies if use default copies
    // a.some_ptr = nullptr;
    std::cout << b.some_data << std::endl; // copies object. if cp ctor = default (just copies data)
    std::cout << *b.some_ptr << std::endl; // copies object. if cp ctor = default (just copies data) points to same ptr as source object
    std::cout << a.some_data << std::endl;
    std::cout << *a.some_ptr << std::endl;

}