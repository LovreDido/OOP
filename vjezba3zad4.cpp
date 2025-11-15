#include <iostream>
#include <string>

using namespace std;

struct Student {
    string ime;
    string JMBAG;
    int godina_studija;
    int broj_ECTS;
    double prosjek_ocjena;
};
void ispisi_studenta(Student& s) {
    cout << s.ime << " (" << s.JMBAG << ") - "
        << s.godina_studija << ". godina, "
        << s.broj_ECTS << " ECTS, prosjek: "
        << s.prosjek_ocjena << endl;
}

void povecaj_godinu(Student& s) {
    s.godina_studija++;
    cout << s.ime << " je prešao/la na " << s.godina_studija << ". godinu" << endl;
}

void filter_students(Student studenti[], size_t velicina,
    void (*akcija)(Student&),
    bool (*filter)(Student&)) {
    for (size_t i = 0; i < velicina; i++) {
        if (filter(studenti[i])) {
            akcija(studenti[i]);
        }
    }
}

int main() {

    Student studenti[] = {
        {"Ana Anić", "0012345678", 1, 0, 0.0},
        {"Ivo Ivić", "0023456789", 1, 30, 3.8},
        {"Marko Markić", "0034567890", 2, 60, 4.2},
        {"Petra Petrić", "0045678901", 1, 15, 3.1},
        {"Lara Larić", "0056789012", 3, 50, 3.9},
        {"Karlo Karlić", "0067890123", 2, 25, 2.8}
    };

    size_t broj_studenata = sizeof(studenti) / sizeof(studenti[0]);
    cout << "SVI:" << endl;
    for (size_t i = 0; i < broj_studenata; i++) {
        ispisi_studenta(studenti[i]);
    }
    cout << endl;
    cout << "STUDENTI PRVE GODINE S BAREM JEDNIM ISPITOM:" << endl;
    filter_students(studenti, broj_studenata,
        ispisi_studenta,
        [](Student& s) {
            return s.godina_studija == 1 && s.broj_ECTS > 0;
        });
    cout << endl;
    cout << " STUDENTI S PROSJEKOM VEĆIM OD 3.5:" << endl;
    filter_students(studenti, broj_studenata,
        ispisi_studenta,
        [](Student& s) {
            return s.prosjek_ocjena > 3.5;
        });
    cout << endl;
    cout << "POVEĆANJE GODINE STUDENTIMA S BAREM 45 ECTS:" << endl;
    filter_students(studenti, broj_studenata,
        povecaj_godinu,
        [](Student& s) {
            return s.broj_ECTS >= 45;
        });
    cout << endl;
    for (size_t i = 0; i < broj_studenata; i++) {
        ispisi_studenta(studenti[i]);
    }

    return 0;
}