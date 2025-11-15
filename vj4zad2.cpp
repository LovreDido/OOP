#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void input_vector(vector<int>& v) {
    int broj;
    cout << "Unesite brojeve (0 za kraj): ";
    while (true) {
        cin >> broj;
        if (broj == 0) break;
        v.push_back(broj);
    }
}

void print_vector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    vector<int> brojevi;
    input_vector(brojevi);

    cout << "Originalni vektor: ";
    print_vector(brojevi);
    vector<int> jedinstveni;
    for (int broj : brojevi) {

        if (find(jedinstveni.begin(), jedinstveni.end(), broj) == jedinstveni.end()) {
            jedinstveni.push_back(broj);
        }
    }

    cout << "Jedinstveni elementi: ";
    print_vector(jedinstveni);


    sort(jedinstveni.begin(), jedinstveni.end(), [](int a, int b) {
        return abs(a) < abs(b);
        });

    cout << "Sortirani po apsolutnoj vrijednosti: ";
    for (size_t i = 0; i < jedinstveni.size(); i++) {
        cout << jedinstveni[i];
        if (i != jedinstveni.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    return 0;
}