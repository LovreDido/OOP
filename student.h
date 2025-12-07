#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

class Student {
private:
    int id;
    std::string name;
    std::string study_program;
    int year;
    static int total_students;

public:
    Student(int id = 0, const std::string& name = "",
        const std::string& study_program = "", int year = 1);

    Student(const Student& other);

    
    ~Student();

    static int get_total_students();

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getStudyProgram() const { return study_program; }
    int getYear() const { return year; }
};

#endif