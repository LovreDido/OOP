#include "course.h"
using namespace std;
ostream& operator<<(ostream& os, const Course& course) {
	os << course.sifra << " " << course.ime << " " << course.ects << " ";
	return os;
}
istream& operator<<(istream& is, const Course& course) {
	cout << "unesi sifru: ";
	getline(is >> ws, course.sifra);
	cout << "unesi ime: ";
	getline(is >> ws, course.ime);
	cout << "unesi ects: ";
	is >> course.ects;
	return is;

}

