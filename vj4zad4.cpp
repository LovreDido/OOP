/*
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool is_vowel(char c) {
	c = tolower(c);
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string word_to_pig_latin(const string& word) {
	if (word.empty()) return word;

	string result = word;
	if (is_vowel(word[0])) {
	
		result += "hay";
	}
	else {
	
		result = word.substr(1) + word[0] + "ay";
	}
	return result;
}

int main() {
	cout << word_to_pig_latin("apple") << endl;
	cout << word_to_pig_latin("hello") << endl; 

	return 0;
}
*/