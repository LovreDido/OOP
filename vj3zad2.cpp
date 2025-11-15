#include <iostream>
#include <cstddef>  
using namespace std;
template<typename T>
inline bool ascending(const T& a, const T& b) {
    return a < b;
}
template<typename T>
inline bool descending(const T& a, const T& b) {
    return a > b;
}
template<typename T>
void sortt(T niz[], std::size_t size, bool(*cmp)(const T&, const T&)) {
    for (std::size_t i = 0; i < size - 1; ++i) {
        for (std::size_t j = 0; j < size - 1 - i; ++j) {
            if (cmp(niz[j + 1], niz[j])) {
                T temp = niz[j];
                niz[j] = niz[j + 1];
                niz[j + 1] = temp;
            }
        }
    }
}

template<typename T>
void printArray(const T niz[], std::size_t size) {
    for (std::size_t i = 0; i < size; ++i) {
        cout << niz[i] << " ";
    }
    cout << endl;
}

int main() {
 
    int niz_int[] = { 10, 3, 8, 15, 7 };
    std::size_t size_int = sizeof(niz_int) / sizeof(niz_int[0]);

    cout << "Uzlazno: ";
    sortt(niz_int, size_int, ascending<int>);
    printArray(niz_int, size_int);

    int niz_int2[] = { 10, 3, 8, 15, 7 };
    cout << "Silazno: ";
    sortt(niz_int2, size_int, descending<int>);
    printArray(niz_int2, size_int);
    double niz_double[] = { 10.5, 3.2, 8.7, 15.1, 7.9 };
    std::size_t size_double = sizeof(niz_double) / sizeof(niz_double[0]);

    cout << "Uzlazno: ";
    sortt(niz_double, size_double, ascending<double>);
    printArray(niz_double, size_double);

    double niz_double2[] = { 10.5, 3.2, 8.7, 15.1, 7.9 };
    cout << "Silazno: ";
    sortt(niz_double2, size_double, descending<double>);
    printArray(niz_double2, size_double);

    return 0;
}