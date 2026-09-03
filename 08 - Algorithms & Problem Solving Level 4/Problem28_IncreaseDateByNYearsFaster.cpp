#include <iostream>
#include <string>
#include <ctime>

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
	d = (Day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;

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






string MonthShortName(short MonthNumber)
{
	string Months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	return Months[MonthNumber - 1];
}

void SwapDates(sDate& Date1, sDate& Date2)
{
	sDate TempDate;

	TempDate = Date1;
	Date1 = Date2;
	Date2 = TempDate;
}

int GetNumberOfDaysFromBeginningOfYear(short Year, short Month, short Day) {
	int totalDays = 0;
	for (short m = 1; m < Month; ++m) {
		totalDays += DaysInMonth(Year, m);
	}
	totalDays += Day;
	return totalDays;
}

short ReadDay(string message) {
	short day;
	do {
		cout << message;
		cin >> day;
	} while (day < 1 || day > 31);
	return day;
}

short ReadMonth(string message) {
	short month;
	do {
		cout << message;
		cin >> month;
	} while (month < 1 || month > 12);
	return month;
}	

short ReadYear(string message) {
	short year;
	do {
		cout << message;
		cin >> year;
	} while (year < 1900 || year > 2100);
	return year;
}

sDate ReadFullDate()
{
	sDate Date;
	Date.Day = ReadDay("Please enter a Day? ");
	Date.Month = ReadMonth("Please enter a Month? ");
	Date.Year = ReadYear("Please enter a Year? ");
	return Date;
}


bool IslastDayInMonth(sDate date) {

	return date.Day == DaysInMonth(date.Year, date.Month);

}
bool IslastMonth(sDate date) {
	return date.Month == 12;
}

sDate IncreseDateByOneDay(sDate date) {
	if (IslastDayInMonth(date)) {
		if (IslastMonth(date)) {
			date.Day = 1;
			date.Month = 1;
			date.Year++;

		}
		else {
			date.Day = 1;
			date.Month++;
		}
	}
	else {
		date.Day++;
	}
	return date;
}

sDate IncreseDateByNdays(sDate date, short Day) {
	for (short i = 0; i < Day; i++) {
		date = IncreseDateByOneDay(date);
	}
	return date;
}

sDate IncreseDateByOneWeek(sDate date) {
	return(IncreseDateByNdays(date, 7));
}

sDate IncreseDateByNWeeks(sDate date, short Weeks) {
	return(IncreseDateByNdays(date, Weeks * 7));
}

sDate IncreseDateByOneMonth(sDate date) {
	
		if (IslastMonth(date)) {
			date.Month = 1;
			date.Year++;
		}
		else {
			date.Month++;
		}
	short NumberOfDaysInCurrentMonth = DaysInMonth(date.Year, date.Month);
	if (date.Day > NumberOfDaysInCurrentMonth)
	{
		date.Day = NumberOfDaysInCurrentMonth;
	}


	return date;
	}
	
sDate IncreseDateByNMonths(sDate date, short Months) {
	for (short i = 0; i < Months; i++) {
		date = IncreseDateByOneMonth(date);

	}
	return date;
}

sDate IncreseDateByOneYear(sDate date) {
	date.Year++;
	short NumberOfDaysInCurrentMonth = DaysInMonth(date.Year, date.Month);
	if (date.Day > NumberOfDaysInCurrentMonth)
	{
		date.Day = NumberOfDaysInCurrentMonth;
	}
	return date;
}

sDate IncreseDateByNYears(sDate date, short Years) {
	date.Year += Years;
	return date;
}

int main()
{
	
	
	sDate date = ReadFullDate();
	date = IncreseDateByOneDay(date);
	cout << "The next date is: " << date.Day << "/" << date.Month << "/" << date.Year << endl;
	short After10Days = 10;
	date = IncreseDateByNdays(date, After10Days);
	cout << "The date after " << After10Days << " days is: " << date.Day << "/" << date.Month << "/" << date.Year << endl;
	date = IncreseDateByOneWeek(date);
	cout << "The date after one week is: " << date.Day << "/" << date.Month << " / " << date.Year << endl;
	date = IncreseDateByNWeeks(date, 10);
	cout << "The date after 10 weeks is: " << date.Day << "/" << date.Month << "/" << date.Year << endl;
	date = IncreseDateByOneMonth(date);
	cout << "The date after one month is: " << date.Day << "/" << date.Month << "/" << date.Year << endl;
	date = IncreseDateByNMonths(date, 10);
	cout << "The date after 10 months is: " << date.Day << "/" << date.Month << "/" << date.Year << endl;
	date = IncreseDateByOneYear(date);
	cout << "The date after one year is: " << date.Day << "/" << date.Month << "/" << date.Year << endl;
	date = IncreseDateByNYears(date, 10);
	cout << "The date after 10 years is: " << date.Day << "/" << date.Month << "/" << date.Year << endl;




	system("pause>0");
	return 0;
}