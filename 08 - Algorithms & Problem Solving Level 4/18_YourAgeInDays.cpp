#pragma warning(disable : 4996)
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
	string Months[12] = { "January", "February", "March", "April", "May", "June",
						  "July", "August", "September", "October", "November", "December" };
	return Months[MonthNumber - 1];
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

sDate GetSystemDate() {
	sDate systemDate;
	time_t now = time(0);
	tm* ltm = localtime(&now);
	systemDate.Year = 1900 + ltm->tm_year;
	systemDate.Month = 1 + ltm->tm_mon;
	systemDate.Day = ltm->tm_mday;
	return systemDate;
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


bool IsDate1BeforeDate2(sDate date1, sDate date2) {
	if (date1.Year != date2.Year)
		return date1.Year < date2.Year;

	if (date1.Month != date2.Month)
		return date1.Month < date2.Month;

	return date1.Day < date2.Day;
}

int GetDifferentDaysBetweenTwoDates(sDate date1, sDate date2, bool IncludeEndDay = false) {
	int DifferentDays = 0;
	while (IsDate1BeforeDate2(date1, date2)) {
		date1 = IncreseDateByOneDay(date1);
		DifferentDays++;
	}

	return (IncludeEndDay ? DifferentDays + 1 : DifferentDays);
}
int main()
{
	
	
	sDate birthDate = ReadFullDate();
	sDate CurrentDate = GetSystemDate();
	cout<<"Your age in days is: "<<GetDifferentDaysBetweenTwoDates(birthDate, CurrentDate, true);






	system("pause>0");
	return 0;
}