#include <iostream>

// implement a few standard containers and algorithms
// allowed headers: iostream, initializer_list
// namespace: nstd

#include "array.h"

int main() {
	nstd::array<int, 3> a = { 1, 2, 3 };

	nstd::array<int, 3>::iterator it = a.begin();

	for (; it != a.end(); ++it) {
		std::cout << *it << std::endl;
	}

	system("pause");
}