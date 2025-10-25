#include <iostream>
using namespace std;

struct Vektor {
    int* niz;
    int log, fiz;
};

Vektor* vector_new(int kap) {
    Vektor* v = new Vektor;
    v->niz = new int[kap];
    v->log = 0;
    v->fiz = kap;
    return v;
}

void vector_delete(Vektor* v) {
    delete[] v->niz;
    delete v;
}

void vector_push_back(Vektor* v, int x) {
    if (v->log >= v->fiz) {
        v->fiz *= 2;
        int* novi = new int[v->fiz];
        for (int i = 0; i < v->log; i++) novi[i] = v->niz[i];
        delete[] v->niz;
        v->niz = novi;
    }
    v->niz[v->log++] = x;
}

void vector_pop_back(Vektor* v) {
    if (v->log > 0) v->log--;
}

int vector_front(Vektor* v) {
    return v->niz[0];
}

int vector_back(Vektor* v) {
    return v->niz[v->log - 1];
}

int vector_size(Vektor* v) {
    return v->log;
}

void ispisi(Vektor* v) {
    for (int i = 0; i < v->log; i++)
        cout << v->niz[i] << " ";
    cout << endl;
}

int main() {
    Vektor* v = vector_new(2);
    vector_push_back(v, 10);
    vector_push_back(v, 20);
    vector_push_back(v, 30);
    cout << "Vektor: ";
    ispisi(v);
    cout << "Prvi: " << vector_front(v) << endl;
    cout << "Zadnji: " << vector_back(v) << endl;
    cout << "Velicina: " << vector_size(v) << endl;
    vector_pop_back(v);
    cout << "Nakon brisanja zadnjeg: ";
    ispisi(v);
    vector_delete(v);
    return 0;
}