#include <chrono>
#include <iostream>
#include <thread>
 
class A 
{
    private:
        int* ptr;
    public:
    A(int* ptr) 
    {
        this->ptr = ptr;
        std::cout << "A()" << std::endl;
    }

    A(const A& other) 
    {
        this->ptr = new int(*(other.getResource()));
        std::cout << "A(const A&) - deep copy" << std::endl;
    }

    A(A& other) 
    {
        this->ptr = new int(*(other.getResource()));
        std::cout << "A(A&) - deep copy" << std::endl;
    }

    A& operator=(A& other) 
    {
        this->ptr = new int(*(other.getResource()));
        std::cout << "operator=(A& other) - deep copy" << std::endl;
        return *this;
    }

    A(A&& other) 
    {
        this->ptr = other.getResource();
        other.setResource(nullptr);
        std::cout << "A(A&& other)  - moved" << std::endl;
    }

    A(const A&& other) 
    {
        this->ptr = other.getResource();
        // other.nullify();
        std::cout << "A(const A&& other)  - moved" << std::endl;
    }


    A& operator=(A&& other)
    {
        this->ptr = other.getResource();
        other.setResource(nullptr);
        std::cout << "operator=(A&& other)  - moved" << std::endl;
        return *this;
    }

    int* getResource() const
    {
        return ptr;
    }

    void setResource(int* ptr)
    {
        this->ptr = ptr;
    }

    void nullify()
    {
        this->ptr = nullptr;
    }

};

const void some(const A a) {
    printf("%d", *a.getResource());
};

int main()
{
    int *g = new int(88);
    const A a(g);

    some(std::move(a));

    // const A b = a;
    // const A bc = b;
    // A d(g);
    // d = a;
    // A dh(a);

    // A dhm(std::move(a));
    // dh = std::move(dh);
    // std::cout << *(dh.getResource()) << std::endl;
}
