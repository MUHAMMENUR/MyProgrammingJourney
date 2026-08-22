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


bool Isfirstdatebiggerthansecond(sDate date1, sDate date2) {
	return (date1.Year > date2.Year) ? true : (date1.Year == date2.Year) ? (date1.Month > date2.Month) ? true : (date1.Month == date2.Month) ? (date1.Day > date2.Day?true:false):false:false;

}

int main()
{
	sDate date1 = ReadDate();
	sDate date2 = ReadDate();
	if(Isfirstdatebiggerthansecond(date1, date2))
	{
		cout << "Date 1 is bigger than Date 2." << endl;
	}
	else
	{
		cout << "Date 1 is not bigger than Date 2." << endl;
	}

	system("pause>0");
	return 0;
}