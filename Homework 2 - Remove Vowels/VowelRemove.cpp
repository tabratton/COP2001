// File name: VowelRemove.cpp (incomplete)
// Author: Dahai Guo
// Last modified: May 9, 2012


#include <iostream>
#include <string>

using namespace std;

char lowerCase(char ch);
string removeVowel(string str);

int main(int argc, char ** argv){

	if(argc != 2){
		cout << "Please input a string" << endl;
		return 1;
	}

	string str1 = argv[1];
	string str2 = removeVowel(str1);

	cout << str1 << endl;
	cout << str2 << endl;
}

char lowerCase(char ch) {
	if (ch > 64 && ch < 91) {
		ch = ch + 32;
	}
	return ch;
}

string removeVowel(string str) {
	string::iterator it;
	for (int i = str.length() - 1; 0 <= i; i--) {
		it = str.begin() + i;
		switch (lowerCase(str.at(i))) {
		case 97:
			str.erase(it);
			break;
		case 101:
			str.erase(it);
			break;
		case 105:
			str.erase(it);
			break;
		case 111:
			str.erase(it);
			break;
		case 117:
			str.erase(it);
			break;
		default:
			break;
		}
	}
	return str;
}