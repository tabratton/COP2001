// File name: PasswordTest.cpp (incomplete)
// Author: Dahai Guo
// Last modified: May 9, 2012

#include <iostream>
#include <ctime>

using namespace std;

string phoneButtons[8] = {
	"abc", "def", "ghi", "jkl",
	"mno", "pqrs", "tuv", "wxyz"
};

bool checkPswd(string keyStrokes, string password);

int main(int argc, char ** argv) {

	if (argc != 3) {
		cout << "Please input the key strokes from the phone and the password." << endl;
		return 1;
	}

	string keyStrokes = argv[1];
	string password = argv[2];


	bool check = checkPswd(keyStrokes, password);
	if (check) {
		cout << "Password Verified" << endl;
	}
	else {
		cout << "Wrong Password" << endl;
	}

	return 0;
}

bool checkPswd(string keyStrokes, string password) {

	if (keyStrokes.length() != password.length()) {
		return false;
	}

	for (int i = 0; i < keyStrokes.length(); i++) {

		int tempKeyASCII = keyStrokes.at(i);
		bool foundLetter = false;

		if (tempKeyASCII - 48 == 0 || tempKeyASCII - 48 == 1) {
			return false;
		}

		string tempButtonString = phoneButtons[tempKeyASCII - 50];
	
		for (int j = 0; j < tempButtonString.length(); j++) {
			if (tempButtonString.at(j) == password.at(i)) {
				foundLetter = true;
				break;
			}
		}

		if (!foundLetter) {
			return false;
		}
	}

	return true;
}