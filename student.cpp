#include "student.h"
#include <iostream>

int Student::total_students = 0;

Student::Student(int id, const std::string& name,
    const std::string& study_program, int year)
    : id(id), name(name), study_program(study_program), year(year) {
    total_students++;
    std::cout << "Kreiran student: " << name << " (Ukupno studenata: " << total_students << ")\n";
}

Student::Student(const Student& other)
    : id(other.id), name(other.name),
    study_program(other.study_program), year(other.year) {
    total_students++;
    std::cout << "Kopiran student: " << name << " (Ukupno studenata: " << total_students << ")\n";
}


Student::~Student() {
    total_students--;
    std::cout << "Unisten student: " << name << " (Preostalo studenata: " << total_students << ")\n";
}

int Student::get_total_students() {
    return total_students;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "ID: " << student.id << "\n";
    os << "Ime: " << student.name << "\n";
    os << "Studijski program: " << student.study_program << "\n";
    os << "Godina: " << student.year << "\n";
    os << "------------------------";
    return os;
}

std::istream& operator>>(std::istream& is, Student& student) {
    std::cout << "Unesite ID studenta: ";
    is >> student.id;
    is.ignore();

    std::cout << "Unesite ime studenta: ";
    std::getline(is, student.name);

    std::cout << "Unesite studijski program: ";
    std::getline(is, student.study_program);

    std::cout << "Unesite godinu studija (1-5): ";
    is >> student.year;

    return is;
}