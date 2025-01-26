#include <iostream>

namespace mj
{
template<typename T>
class unique_ptr
{

private:
    T* m_underlying_ptr;
public:
    unique_ptr(T* passed_ptr = nullptr) {
        printf("unique_ptr created through constructor\n");
        m_underlying_ptr = passed_ptr;
    };

    ~unique_ptr(){
        if (m_underlying_ptr == nullptr) {
            printf("unique_ptr destroyed through destructor. but ptr is already deleted.\n");
            return;
        }
        
        printf("unique_ptr destroyed through destructor\n");
        
        delete m_underlying_ptr;
        m_underlying_ptr = nullptr;
    };

    unique_ptr(const unique_ptr&) = delete; // if this deleted unique_ptr(unique_ptr& other) also doesn't works
    unique_ptr& operator=(unique_ptr&) = delete;

    // unique_ptr(unique_ptr& other) {

    // }

    unique_ptr(unique_ptr&& other) : m_underlying_ptr(other.m_underlying_ptr) {
        printf("unique_ptr created through move constructor\n");
        m_underlying_ptr = nullptr;
    }

    unique_ptr& operator=(unique_ptr&& other) {
        printf("unique_ptr created through move assignment");
        if (this != &other) {
            delete m_underlying_ptr;
            m_underlying_ptr = other.m_underlying_ptr;
            other.m_underlying_ptr = nullptr;
        }
        return *this;
    }
};
    
}; // namespace mj

