#include <iostream>

// understanding lvalue and rvalue refs 1
class A {
    public:
    int i;
    A(int _i) {i = _i;};
    A(A&) {
        std::cout << "copy ctor non const&" << std::endl;
    }
    A(const A&) {
        std::cout << "copy ctor const&" << std::endl;
    }
    A(const A&&) {
        std::cout << "copy ctor const&&" << std::endl;
    }
    A& operator=(A&) {
        std::cout << "copy assignment non const&" << std::endl;
        return *this;
    }

    ~A() {
        std::cout << i << " destructed" << std::endl;
    }
        
};


int main() {
    A a(8);
    // A& ref_a = a; // does not uses any constructors
    // // if non const copy ctor implemented uses this
    // // if non const copy instrcutor not implemented 
    // // const copy ctors implemented uses it
    // A a1 = a;
    // // if non const copy ctor implemented uses this
    // // if non const copy instrcutor not implemented 
    // // const copy ctors implemented uses it
    // const A a2 = a;

    // const A const_a(9);
    // // ref should be const
    // const A& ref_const_a = const_a; 
    // // should have implemented const ref constructor
    // A non_const_copy_of_const_a = const_a; 
    // const A const_copy_of_const_a = const_a;

    // // uses const& constructor if const&& constructor not implemented
    // A moved_a = std::move(a);

    A&& rvalue_a = std::move(a); // does not creates object
    std::cout << rvalue_a.i << std::endl;
    A a_ = std::move(a); // creates a_ object

}
