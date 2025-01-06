#include <new>



class placementnew
{
private:
    /* data */
public:
    placementnew(/* args */) {};

    alignas(int) unsigned char buf[sizeof(int)];

    void allocate_placement_new() {
        int* int_ptr = new(buf) int;
        // delete int_ptr;
        // int_ptr = nullptr;
    }

    void allocate_new() {
        int* int_ptr = new int;
        // delete int_ptr;
        // int_ptr = nullptr;
    }
 
};

