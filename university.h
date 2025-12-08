#ifndef UNIVERSITY_CONSTANTS_H
#define UNIVERSITY_CONSTANTS_H
#include<iostream>
using namespace std;

struct UniversityConstants {
	static const int maxects = 60;
	static const int required = 40;
	static void print_rules() {
		cout << "max broj ects po god. : " << maxects <<endl;
		cout << "potreban broj ects po god. : " << required << endl;
	}
};
#endif