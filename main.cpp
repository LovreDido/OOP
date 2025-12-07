
#include <iostream>
#include <vector>
#include <memory>
#include "student.h"

void testScope() {
    std::cout << "\n--- Početak testScope funkcije ---\n";
    std::cout << "Trenutni broj studenata: " << Student::get_total_students() << "\n";

    Student lokalniStudent(300, "Lokalni Student", "Testni program", 2);
    std::cout << "U testScope funkciji: " << Student::get_total_students() << " student(a)\n";

    std::cout << "--- Kraj testScope funkcije ---\n";
}

int main() {
    std::cout << "Početni broj studenata: " << Student::get_total_students() << "\n\n";

    std::vector<Student> studenti;
    int brojStudenata;

    std::cout << "Koliko studenata zelite unijeti? ";
    std::cin >> brojStudenata;
    std::cin.ignore();

    for (int i = 0; i < brojStudenata; i++) {
        std::cout << "\n--- Unos podataka za studenta " << i + 1 << " ---\n";
        Student s;
        std::cin >> s;
        studenti.push_back(s);
        std::cout << "Trenutni broj studenata: " << Student::get_total_students() << "\n";
    }

    std::cout << "\n\n--- Popis svih studenata ---\n";
    for (const auto& student : studenti) {
        std::cout << student << "\n\n";
    }

    std::cout << "\n--- Testiranje kopiranja ---\n";
    if (!studenti.empty()) {
        Student kopija = studenti[0]; 
        std::cout << "Kreirana kopija: " << kopija.getName() << "\n";
        std::cout << "Broj studenata nakon kopiranja: " << Student::get_total_students() << "\n";
    }

    testScope();

    std::cout << "\n--- Testiranje sa unique_ptr ---\n";
    {
        auto pametniStudent = std::make_unique<Student>(400, "Pametni Student", "AI", 4);
        std::cout << "Unutar bloka sa unique_ptr: " << Student::get_total_students() << " student(a)\n";
    }
    std::cout << "Nakon bloka sa unique_ptr: " << Student::get_total_students() << " student(a)\n";

    std::cout << "\n--- Testni student kreiran konstruktorom ---\n";
    Student testniStudent(100, "Marko Markovic", "Racunarstvo", 3);
    std::cout << testniStudent << "\n";

    std::cout << "\n--- Statistika ---\n";
    std::cout << "Ukupan broj studenata (trenutno): " << Student::get_total_students() << "\n";

    std::cout << "\n--- Finalni popis studenata ---\n";
    for (size_t i = 0; i < studenti.size(); i++) {
        std::cout << studenti[i] << "\n\n";
    }

    std::cout << "Broj studenata prije izlaska iz main: " << Student::get_total_students() << "\n";

    return 0;
}