#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
bool IsLeapYear(int number) {
    return (number % 4 == 0 && number % 100 != 0) || (number % 400 == 0);
}

int main() {

	cout << "Enter a year: ";
	int year;
	cin >> year;
	if (IsLeapYear(year)) {
		cout << year << " is a leap year." << endl;
	}
	else {
		cout << year << " is not a leap year." << endl;
	}
    return 0;
}