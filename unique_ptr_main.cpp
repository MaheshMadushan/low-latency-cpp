#include <iostream>
#include "unique_ptr.hpp"

int main() {
	mj::unique_ptr<int> unique_int(new int(9));
	mj::unique_ptr<int> my_up(std::move(unique_int));
	mj::unique_ptr<int> my_up1 = std::move(my_up);
	// mj::unique_ptr<int> my_up1(unique_int); // not valid copy assignment is deleted
	// mj::unique_ptr<int> my_up = unique_int; // not valid copy assignment is deleted
}