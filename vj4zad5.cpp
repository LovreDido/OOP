#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  
using namespace std;
void reverse_strings(vector<string>& words) {
	for (auto& word : words) {
		reverse(word.begin(), word.end());
	}
}
void print_vector(const vector<string>& v) {
	cout << "[ ";
	for (const auto& s : v)
		cout << "\"" << s << "\" ";
	cout << "]" << endl;
}

int main() {
	vector<string> words = { "hello", "world", "c++" };
	cout << "Prije: ";
	print_vector(words);
	reverse_strings(words);
	cout << "Poslije:";
	print_vector(words);

	return 0;
}
