#include <iostream>

template <typename T, size_t N>
class stack
{
private:
    T underlying_container[N];
    size_t element_index{0};
public:
    
    void push(T element)
    {
        if (element_index >= N)
        {
            throw std::overflow_error("stack is overflowed");
        }
        underlying_container[element_index++] = element;
    }

    T pop()
    {
        if (element_index <= 0)
        {
            throw std::overflow_error("stack is underflowed");
        }
        return underlying_container[--element_index];
    }

    bool empty()
    {
        return element_index <= 0;
    }

    T& top()
    {
        if (element_index <= 0)
        {
            throw std::overflow_error("stack is overflowed");
        }
        return underlying_container[element_index];
    }

    size_t size()
    {
        return element_index;
    }


};

int main()
{
    stack<int, 5> int_stack;
    int_stack.push(100);
    int_stack.push(10);
    int_stack.push(100);
    int_stack.push(10000000);
    int_stack.push(10);
    // int_stack.push(1); // throws

    for (size_t i = 0; i < 5; i++)
    {
        std::cout << int_stack.pop() << std::endl;
    }
    

}