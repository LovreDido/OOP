#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include<string>
using namespace std;
class Course {
private:
	string ime;
	string sifra;
	int ects;
public:
	Course(const string ime="",const string sifra="",int ects=5)
		: ime(ime),sifra(sifra),ects(ects){}
	string get_ime()const { return ime; }
	string sifra()const { return sifra; }
	int get_ects()const { return ects; }
	friend ostream& operator<<(std::ostream& os, const Course& course);
	friend istream& operator<<(std::istream& is, Course& course);

};

#endif 
