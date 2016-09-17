#include <iostream>
#include <iomanip>
#include <ctime>

// This function does the following:
//   1. allocates a triangle 2D array with "numRows" rows. The beginning row's length is one.
//      The length of each row below is one more than the previous row. 
//   2. Assign each element in the 2D array a random integer in [0,99)
void allocateTriangle(int ** & twoDArray, int numRows);

// Prints the triangle 2D array described above.
void printTriangle(int ** & twoDArray, int numRows);

// Given a triangle 2D array, this function grows it to a square 2D array. All the 
// existing number in the array must not be lost. For each of the additional array
// element, assign a random integer in [0,99)
// RESTRICTION: ANY UNUSED DYNAMIC MEMORY MUST BE DELETED
void growToSquare(int ** & twoDArray, int numRows);

// Prints the square array described above.
void printSquare(int ** & twoDArray, int numRows);

using namespace std;

int main(int argc, char ** argv) {

	srand(time(NULL));

	int ** twoDArray;
	int numRows = 10;
	allocateTriangle(twoDArray, numRows);
	cout << "******* Triangle array *******" << endl;
	printTriangle(twoDArray, numRows);
	growToSquare(twoDArray, numRows);
	cout << "******* Sqaure array *******" << endl;
	printSquare(twoDArray, numRows);

	return 0;
}

void allocateTriangle(int ** & twoDArray, int numRows) {
	twoDArray = new int *[numRows];
	for (int i = 0, offset = numRows - 1; i < numRows; i++, offset--) {
		twoDArray[i] = new int[numRows - offset];
		for (int j = 0; j < numRows - offset; j++) {
			twoDArray[i][j] = rand() % 100;
		}
	}
}

void printTriangle(int ** & twoDArray, int numRows) {
	for (int i = 0, offset = numRows - 1; i < numRows; i++, offset--) {
		for (int j = 0; j < numRows - offset; j++) {
			cout << setw(5) << twoDArray[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void growToSquare(int ** & twoDArray, int numRows) {
	for (int i = 0, offset = numRows - 1; i < numRows; i++, offset--) {
		int * newRow = new int[numRows];
		for (int j = 0; j < numRows - offset; j++) {
			newRow[j] = twoDArray[i][j];
		}

		for (int j = numRows - 1; j > numRows - offset - 1; j--) {
			newRow[j] = rand() % 100;
		}

		delete [] twoDArray[i];
		twoDArray[i] = newRow;
	}
}

void printSquare(int ** & twoDArray, int numRows) {
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < numRows; j++) {
			cout << setw(5) << twoDArray[i][j];
		}
		cout << endl;
	}
}
