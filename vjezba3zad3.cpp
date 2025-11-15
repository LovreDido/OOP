#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto je_paran = [](int n) { return n % 2 == 0; };
auto je_neparan = [](int n) { return n % 2 != 0; };
auto udvostruci = [](int n) { return n * 2; };
auto prepolovi = [](int n) { return n / 2; };
void transformiraj_niz(vector<int>& niz) {
    for (int& broj : niz) {
        if (je_paran(broj)) {
            broj = prepolovi(broj);
        }
        else {
            broj = udvostruci(broj);
        }
    }
}

void suma_i_produkt(const vector<int>& niz, int& suma, int& produkt) {
    suma = 0;
    produkt = 1;

    auto dodaj_u_sumu = [&](int broj) {
        suma += broj;
        };

    auto dodaj_u_produkt = [&](int broj) {
        produkt *= broj;
        };

    for (int broj : niz) {
        dodaj_u_sumu(broj);
        dodaj_u_produkt(broj);
    }
}

int suma_vecih_od_praga(const vector<int>& niz, int prag) {
    int suma = 0;
    auto dodaj_ako_veci = [prag, &suma](int broj) {
        if (broj > prag) {
            suma += broj;
        }
        };

    for (int broj : niz) {
        dodaj_ako_veci(broj);
    }

    return suma;
}

void ispisi_niz(const vector<int>& niz, const string& naziv) {
    cout << naziv << ": ";
    for (int broj : niz) {
        cout << broj << " ";
    }
    cout << endl;
}

int main() {
    vector<int> niz = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cout << "ORIGINALNI NIZ:" << endl;
    ispisi_niz(niz, "Niz");
   
    vector<int> niz1 = niz; 
    transformiraj_niz(niz1);
    cout << "\n1. PARNE PREPOLOVI, NEPARNE UDVOSTRUCI:" << endl;
    ispisi_niz(niz, "Original");
    ispisi_niz(niz1, "Transformiran");
    int suma, produkt;
    suma_i_produkt(niz, suma, produkt);
    cout << "\n2. SUMA I PRODUKT:" << endl;
    cout << "Suma: " << suma << endl;
    cout << "Produkt: " << produkt << endl;
    int prag = 5;
    int suma_prag = suma_vecih_od_praga(niz, prag);
    cout << "\n3. SUMA BROJEVA VECIH OD PRAGA (" << prag << "):" << endl;
    cout << "Suma: " << suma_prag << endl;

    return 0;
}