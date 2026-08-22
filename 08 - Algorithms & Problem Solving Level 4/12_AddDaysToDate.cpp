#include <iostream>
#include <string>

using namespace std;



struct sDate {
	short Day;
	short Month;
	short Year;
};

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
string MonthShortName(short MonthNumber)
{
	string Months[12] = { "January", "February", "March", "April", "May", "June",
						  "July", "August", "September", "October", "November", "December" };
	return Months[MonthNumber - 1];
}


void PrintCalendar(short Year, short Month)
{
	short daysInMonth = DaysInMonth(Year, Month); 

	cout << " ----------- " << MonthShortName(Month) << "----------" << endl;
	cout << "Su Mo Tu We Th Fr Sa" << endl;
	short firstDayOfWeek = DayOfWeekOrder(Year, Month, 1);

	for (short i = 0; i < firstDayOfWeek; ++i) {
			cout << "   ";
		}
		for (short day = 1; day <= daysInMonth; ++day) {
			cout << (day < 10 ? " " : "") << day << " ";
			if ((firstDayOfWeek + day) % 7 == 0) {
				cout << endl;
			}
		}
		cout << endl;
	}

void PrintFrom1To12(short Year) {
	cout << "==================================================\n";
	cout << "\t\t\t\t" << Year << endl;
	cout << "==================================================\n";
	for (short i = 1; i <= 12; ++i) {
		
		PrintCalendar(Year, i);

	}
}
short ReadDay(string prompt)
{
	short day;
	cout << prompt;
	cin >> day;
	return day;
}
int GetNumberOfDaysFromBeginningOfYear(short Year, short Month, short Day) {
	int totalDays = 0;
	for (short m = 1; m < Month; ++m) {
		totalDays += DaysInMonth(Year, m);
	}
	totalDays += Day;
	return totalDays;
}

sDate GetDateFromDayOrderInYear(short Year, short Dayorder) {
	sDate date;
	short RemainingDays = Dayorder;
	short Month = 1;
	date.Month = 1;
	date.Year = Year;

	while (true) {
		short daysInMonth = DaysInMonth(Year, Month);
		if(RemainingDays>daysInMonth) {
			RemainingDays -= daysInMonth;
			date.Month++;
		} else {
			date.Day = RemainingDays;
			break;
		}
	}
	return date;
}


int ReadAddDays(string prompt) {
	short DaysToAdd;
	cout << prompt;
	cin >> DaysToAdd;
	return DaysToAdd;
}

sDate DateToAdd(sDate date, short DaysToAdd) {
	short RemainingDays = DaysToAdd + GetNumberOfDaysFromBeginningOfYear(date.Year, date.Month, date.Day);
	
	short MonthDays = 0;
	date.Month = 1;
	while (true) {
		MonthDays = DaysInMonth(date.Year, date.Month);
		if(RemainingDays>MonthDays) {
			RemainingDays -= MonthDays;
			date.Month++;
			if (date.Month > 12) {
				date.Month = 1;
				date.Year++;
			}
		} else  {
			date.Day = RemainingDays;
			break;
		}
	}
	return date;
}

int main()
{
	short Day = ReadDay("Please enter a day: ");
	short Month = ReadMonth("Please enter a month: ");
	short year = ReadYear("Please enter a year: ");
	sDate date = { Day, Month, year };
	cout << "The number of days from the beginning of the year is: " << GetNumberOfDaysFromBeginningOfYear(year, Month, Day) << endl;
	date = GetDateFromDayOrderInYear(year, GetNumberOfDaysFromBeginningOfYear(year, Month, Day));
	cout << "Date for is: " << date.Day << "/" << date.Month << "/" << date.Year << endl;
	short DaysToAdd = ReadAddDays("Please enter the number of days to add: ");
	date = DateToAdd(date, DaysToAdd);
	cout << "The new date after adding " << DaysToAdd << " days is: " << date.Day << "/" << date.Month << "/" << date.Year << endl;

	system("pause>0");
	return 0;
}