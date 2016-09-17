#include <cstdlib>
#include <iostream>
using namespace std;

int calculateGCD(int, int);

int main(int argc, char ** argv) {
	int num1;
	int num2;
	int gdc;

	if (argc == 1) {
		cout << "Please enter the first positive integer: " << endl;
		cin >> num1;
		while (cin.bad() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input \nPlease enter the first positive integer" << endl;
			cin >> num1;
		}
		cout << "Please enter the second positive integer: " << endl;
		cin >> num2;
		while (cin.bad() || cin.peek() != '\n') {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input \nPlease enter the second positive integer" << endl;
			cin >> num2;
		}
		gdc = calculateGCD(num1, num2);
		cout << "The Greatest Common Divisor between " << num1 << " and " << num2 << " is " << gdc << endl;
	} else if (argc == 3) {
		if (atoi(argv[1]) < 1 || atoi(argv[2]) < 1) {
			cout << "Please input two positive integers" << endl;
		} else {
			num1 = atoi(argv[1]);
			num2 = atoi(argv[2]);
			gdc = calculateGCD(num1, num2);
			cout << "The Greatest Common Divisor between " << num1 << " and " << num2 << " is " << gdc << endl;
		}
	}
	return 0;
}

int calculateGCD(int num1, int num2) {
	int gdc;
	if (num2 == 0) {
		gdc = num1;
	}
	else {
		gdc = calculateGCD(num2, num1 % num2);
	}
	return gdc;
}
