#include <iostream>
#include <cstddef>  


inline bool ascending(int a, int b) {
	return a < b;  
}

inline bool descending(int a, int b) {
	return a > b;  
}

void sortt(int niz[], std::size_t size, bool(*cmp)(int, int)) {
	for (std::size_t i = 0; i < size - 1; ++i) {
		for (std::size_t j = 0; j < size - 1 - i; ++j) {
			if (cmp(niz[j + 1], niz[j])) { 
				int temp = niz[j];
				niz[j] = niz[j + 1];
				niz[j + 1] = temp;
			}
		}
	}
}

void printArray(int niz[], std::size_t size) {
	for (std::size_t i = 0; i < size; ++i) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int niz[] = { 10, 3, 8, 15, 7 };
	std::size_t size = sizeof(niz) / sizeof(niz[0]);

	std::cout << "Uzlazno: ";
	sortt(niz, size, ascending);
	printArray(niz, size);

	int niz2[] = { 10, 3, 8, 15, 7 };  
	std::cout << "Silazno: ";
	sortt(niz2, size, descending);
	printArray(niz2, size);

	return 0;
}
