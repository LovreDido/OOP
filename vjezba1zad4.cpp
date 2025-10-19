#include <iostream>
using namespace std;

int& at(int niz[], int i) {
    return niz[i];
}
int main() {
    int niz[] = { 1, 2, 3, 4, 5 };
    int i = 2;
    cout << "" << niz[i] << endl;
    at(niz, i) += 1;
    cout << "" << niz[i] << endl;
    return 0;
}
