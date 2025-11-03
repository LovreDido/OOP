/*#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void fix_spaces(string& text) {
	
	for (size_t i = 0; i + 1 < text.size(); ) {
		if (isspace(text[i]) && isspace(text[i + 1])) {
			text.erase(i, 1); 
		}
		else {
			++i;
		}
	}

	for (size_t i = 1; i < text.size(); ) {
		if ((text[i] == ',' || text[i] == '.') && text[i - 1] == ' ') {
			text.erase(i - 1, 1);
		}
		else {
			++i;
		}
	}

	for (size_t i = 0; i + 1 < text.size(); ++i) {
		if (text[i] == ',') {
			if (text[i + 1] != ' ') {
				text.insert(i + 1, " ");
			}
		}
	}

	while (!text.empty() && isspace(text.front()))
		text.erase(text.begin());
	while (!text.empty() && isspace(text.back()))
		text.pop_back();
}

int main() {
	string s = "Puno   razmaka  ,i  tocka .";
	cout << "Prije:  \"" << s << "\"" << endl;
	fix_spaces(s);
	cout << "Poslije: \"" << s << "\"" << endl;
	return 0;
}
*/