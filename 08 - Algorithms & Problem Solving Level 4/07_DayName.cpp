#include <iostream>

using namespace std;

// Function to determine whether a given year is a leap year
bool isLeapYear(short Year)
{
	// A year is a leap year if it is divisible by 4 AND not by 100,
	// OR if it is divisible by 400
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

short DayOfWeekOrder(short Year, short Month, short Day) {
	int a, y, m, d;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + 12 * a - 2;
	d = (Day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;

	return d;
}

string DayOfWeekName(int d) {
	switch (d) {
	case 0: return "Sunday";
	case 1: return "Monday";
	case 2: return "Tuesday";
	case 3: return "Wednesday";
	case 4: return "Thursday";
	case 5: return "Friday";
	case 6: return "Saturday";
	default: return "Invalid day";
	}
	
	
}

short DaysInMonth(short Year, short Month) {
	switch (Month) {
	case 1: 
	case 3: 
	case 5: 
	case 7: 
	case 8: 
	case 10: 
	case 12: 
		return 31;
	case 4: 
	case 6: 
	case 9: 
	case 11: 
		return 30;
	case 2: 
		return isLeapYear(Year) ? 29 : 28;
	default:
		return -1; 
	}
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

short ReadDay(string prompt) {
	short day;
	cout << prompt;
	cin >> day;
	return day;
}
int main()
{
	// Read inputs from the user
	short year = ReadYear("Please enter a year to check? ");
	short month = ReadMonth("Please enter a month to check? ");
	short day= ReadDay("Please enter a day to check? ");
	short dayOfWeek = DayOfWeekOrder(year, month, day);
	short daysInMonth = DaysInMonth(year, month);
	string dayOfWeekName = DayOfWeekName(dayOfWeek);
	cout << "\nDate          : " << day << "/" << month << "/" << year;
	cout << "\nDay Order     : " << dayOfWeek;
	cout << "\nDay Name      : " << dayOfWeekName << endl;




	
	system("pause>0");
	return 0;
}