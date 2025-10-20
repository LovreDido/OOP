#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<ctime>
using namespace std;
double **alociranje(int r, int s) {
	double **matrica = new double*[r];
	for (int i = 0; i < r; i++) {
		matrica[i] = new double[s];
	}
	return matrica;
}
void deleteovanje(double **matrica, int r) {
	for (int i = 0; i < r; i++) {
		delete[] matrica[i];
	}
	delete[] matrica;
}
void unos(double **matrica, int r, int s) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			cout << "[" << i << "][" << j << "]";
			cin >> matrica[i][j];
		}
	}
}
void ispis(double** matrica, int r, int s) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			cout << matrica[i][j]<<" ";
		}
	}
}
double**zbrajanje(double **A, double **B, int r, int s) {
	double ** rez = alociranje(r, s);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			rez[i][j] = A[i][j] + B[i][j];
		}
	}
	return rez;
}
double**oduzimanje(double **A, double **B, int r, int s) {
	double ** rez1 = alociranje(r, s);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			rez1[i][j] = A[i][j] - B[i][j];
		}
	}
	return rez1;
}
double**mnozenje(double **A, double **B, int r, int s) {
	double ** rez2 = alociranje(r, s);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			rez2[i][j] = A[i][j] * B[i][j];
		}
	}
	return rez2;
}
double**transponiranje(double **matrica, int r, int s) {
	double ** trans = alociranje(r, s);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			trans[j][i] = matrica[i][j];
		}
	}
	return trans;
}
void generiranje(double **matrica, int r, int s,double a,double b) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < s; j++) {
			matrica[i][j] = a + (rand() / (double)RAND_MAX)*(b - a);
		}
	}
}
