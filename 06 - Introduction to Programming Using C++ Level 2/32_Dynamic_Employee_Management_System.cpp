#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct StEmployee {
	string Name;
	int Age;
	double Salary;
};



void ReadInformation(vector<StEmployee>& Employees) {
	StEmployee Employee1;
	char Times;

	do
	{
		cout << "Enter Employee name:";
		cin >> Employee1.Name;
		cout << "\nEnter Employee age: ";
		cin >> Employee1.Age;
		cout << "\nEnter Employee salary: ";
		cin >> Employee1.Salary;
		Employees.push_back(Employee1);
		cout << "\nDo you want to add another employes (Y/N)";
		cin >> Times;



	} while (Times == 'Y' || Times == 'y');
};

void PrintInformation(vector<StEmployee>& Employees) {
	for (StEmployee &Employee : Employees) {
		cout << "Employee Name: " << Employee.Name << endl;
		cout << "Employee Age: " << Employee.Age << endl;
		cout << "Empolyee Salary: " << Employee.Salary << endl;
		cout << endl;

	}
}

int main() {
	vector <StEmployee> Employees;
	StEmployee Employee1;

	ReadInformation(Employees);
	PrintInformation(Employees);


}