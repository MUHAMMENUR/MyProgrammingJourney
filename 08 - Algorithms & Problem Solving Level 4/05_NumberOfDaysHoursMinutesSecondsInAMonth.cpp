#include <iostream>

using namespace std;

// Function to determine whether a given year is a leap year
bool isLeapYear(short Year)
{
	// A year is a leap year if it is divisible by 4 AND not by 100,
	// OR if it is divisible by 400
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

// Function to get the total number of days in a specific month of a given year
short NumberOfDaysInAYear(short Year, short Month)
{
	switch (Month)
	{
		// Months with 31 days
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;

		// Months with 30 days
	case 4: case 6: case 9: case 11:
		return 30;

		// February: 29 days in leap years, 28 days otherwise
	case 2:
		return isLeapYear(Year) ? 29 : 28;

		// Invalid month handler
	default:
		return -1;
	}
}

// Function to calculate the total hours in the selected month
short NumberOfHoursInAYear(short Year, short Month)
{
	return NumberOfDaysInAYear(Year, Month) * 24;
}

// Function to calculate the total minutes in the selected month
int NumberOfMinutesInAYear(short Year, short Month)
{
	return NumberOfHoursInAYear(Year, Month) * 60;
}

// Function to calculate the total seconds in the selected month
int NumberOfSecondsInAYear(short Year, short Month)
{
	return NumberOfMinutesInAYear(Year, Month) * 60;
}

// Helper function to read the year from user input
short ReadYear(string prompt)
{
	short year;
	cout << prompt;
	cin >> year;
	return year;
}

// Helper function to read the month from user input
short ReadMonth(string prompt)
{
	short month;
	cout << prompt;
	cin >> month;
	return month;
}

int main()
{
	// Read inputs from the user
	short year = ReadYear("Please enter a year to check? ");
	short month = ReadMonth("Please enter a month to check? ");

	// Display month statistics (Days, Hours, Minutes, Seconds)
	cout << "\nNumber of Days in month [" << month << "] is "
		<< NumberOfDaysInAYear(year, month);
	cout << "\nNumber of Hours in month [" << month << "] is "
		<< NumberOfHoursInAYear(year, month);
	cout << "\nNumber of Minutes in month [" << month << "] is "
		<< NumberOfMinutesInAYear(year, month);
	cout << "\nNumber of Seconds in month [" << month << "] is "
		<< NumberOfSecondsInAYear(year, month);

	system("pause>0");
	return 0;
}