#include <iostream>
#include <string>

using namespace std;



struct sDate {
	short Day;
	short Month;
	short Year;
};

sDate ReadDate()
{
	sDate date;
	cout << "Enter day: ";
	cin >> date.Day;
	cout << "\nEnter month: ";
	cin >> date.Month;
	cout << "\nEnter year: ";
	cin >> date.Year;
	return date;
}


bool IsDateEqual(sDate date1, sDate date2) {
	return (date1.Year == date2.Year && date1.Month == date2.Month && date1.Day == date2.Day);

}

int main()
{
	sDate date1 = ReadDate();
	cout << "Date 1: " << date1.Day << "/" << date1.Month << "/" << date1.Year << endl;
	sDate date2 = ReadDate();
	cout << "Date 2: " << date2.Day << "/" << date2.Month << "/" << date2.Year << endl;
	if(IsDateEqual(date1, date2))
	{
		cout << "Date 1 is equal to Date 2." << endl;
	}
	else
	{
		cout << "Date 1 is not equal to Date 2." << endl;
	}

	system("pause>0");
	return 0;
}