/*#include <iostream>
using namespace std;

int *fibonacci(int n){
	if (n <= 0) 
		return 0;
	
	int *niz = new int[n];
	if (n >= 1)
		niz[0] = 1;
	if (n >= 2)
		niz[1] = 1;
	for (int i = 2; i < n; i++) {
		niz[i] = niz[i - 1] + niz[i - 2];
	}
	return niz;


}
int main() {
	int n = 7;
	int *rez = fibonacci(n);
	cout << "rez je:";
	for (int i = 0; i < n; i++) {
		cout << rez[i] << " ";
	}
	delete[] rez;
	return 0;

}