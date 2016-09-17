#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
enum Month {
	Jan, Feb, Mar, Apr, May, Jun,
	Jul, Aug, Sep, Oct, Nov, Dec
};

enum Day { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

#define Day_1980_1_1 Tue
#define Start_Year 1980
#define Num_Of_Months 12
#define Num_Of_Days 7

string month_str[12] = {
	"Janunary", "Feburary", "March", "April",
	"May", "June", "July", "August",
	"September", "October", "November", "December"
};

string day_str[7] = {
	"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// finds the first day in the given year
int findFirstDay(int year);
// prints the calendar in the given month
int printMonthCalendar(Month month, int offSet);
// prints the calendar of the given year
void printYrCalendar(int year);

int main(int argc, char ** argv) {
	int year = 0;
	if (argc != 2 || (year = atoi(argv[1])) < 1980) {
		cout << "Please input the year number (>=1980)!" << endl;
		return 1;
	}

	//Determines if it is a leap year and sets February's days accordingly
	if (year % 400 == 0) {
		monthDays[1] = 29;
	}
	else if (year % 100 == 0) {
		monthDays[1] = 28;
	}
	else if (year % 4 == 0) {
		monthDays[1] = 29;
	}

	printYrCalendar(year);
}

void printYrCalendar(int year) {
	int offSet = findFirstDay(year);

	//Iterates through the months of the year
	for (int i = 0; i < 12; i++) {
		Month currentMonth = (Month) i;
		offSet = printMonthCalendar(currentMonth, offSet);
		cout << endl;
	}

}

int printMonthCalendar(Month month, int offSet) {

	cout << "     ****** " + month_str[month] + " ******" << endl;

	//Prints a header for the month with the days of the week
	for (int i = 0; i < 7; i++) {
		cout << setw(5);
		cout << day_str[i];
	}
	cout << endl;

	int currentDay = 1;

	//Resets the first day of the week to Sunday if the last day of the last month was Saturday
	if (offSet > 7) {
		offSet = 1;
	}

	//Prints the first day of the month
	cout << setw(offSet * 5);
	cout << currentDay;
	currentDay++;

	//Prints the rest of the first week
	for (int i = offSet; i < 7; i++) {
		cout << setw(5) << currentDay;
		currentDay++;
	}
	cout << endl;

	//Prints the remaining weeks of the month
	while (currentDay <= monthDays[month]) {
		for (int j = 1; j <= 7; j++) {
			cout << setw(5);
			cout << currentDay;
			currentDay++;
			if (currentDay > monthDays[month]) {
				cout << endl;
				return j + 1;
			}
		}
		cout << endl;
	}

}

int findFirstDay(int year) {
	int startYear = 1980;
	int difference = year - startYear;
	int shift = 3;

	//Calculates the shift in start date that the previous year adds
	for (int i = 1; i <= difference; i++) {
		if ((i - 1) % 4 == 0) {
			shift += 2;
		}
		else {
			shift++;
		}

		//If the shift goes over 7, it is re-adjusted back down to fit in the 1-7 range
		if (shift > 7) {
			shift = shift - 7;
		}
	}

	return shift;
}