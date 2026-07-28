#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct StEmployee {
	string Name;
	int Age;
	double Salary;
};


bool IsNumberfound(vector <int>& v1, int Target) {
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] == Target) {
			return true;
		}
	}
	return false;
}

void DoubleEvenNumbers(vector <int>& l) {
	for (int i = 0; i < l.size(); i++) {
		if (l[i] % 2 == 0) {
			l[i] = l[i] * 2;
		}
		

	}
}

void PrintVector(const vector<int>& l) {
	for (auto& i :l ) {
		cout << i << " ";
	}
}

void GiveSalaryBonus(vector<StEmployee>& Employees) {
	for (StEmployee& Employee : Employees) {
		Employee.Salary = Employee.Salary * 1.10;
		
	}
}




void PrintAdultEmployees(const vector<StEmployee>& Employees)
	{
		for (const StEmployee& Employee : Employees) {
			if (Employee.Age >= 18) {
				cout << "Name: " << Employee.Name << endl;
				cout << "Age: " << Employee.Age << endl;
				cout << "Salary: " << Employee.Salary << endl;
				cout << endl;
			}
		}
	}
int main() {
	vector <StEmployee> Employees;
	StEmployee Employee1;

	Employee1.Name = "Muhammed Nur";
	Employee1.Age = 21;
	Employee1.Salary = 23.000;
	Employees.push_back(Employee1);

	Employee1.Name= "Ahmed Kanco";
	Employee1.Age = 12;
	Employee1.Salary = 12.331;
	Employees.push_back(Employee1);


	Employee1.Name = "Sidra Boşnak";
	Employee1.Age = 21;
	Employee1.Salary = 231.32;
	Employees.push_back(Employee1); 




	for (StEmployee& Employee : Employees) {
		cout << "Name: " << Employee.Name << endl;
		cout << "Age: " << Employee.Age << endl;
		cout << "Salary: " << Employee.Salary << endl;
		cout << endl;
	}
	vector <int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	int Target =0;
	cout << "Enter the number to be searched in the vector: ";
	cin>>Target;
	IsNumberfound(v1, Target) ? cout << "Number found in the vector" << endl :cout<<"Number is not found in the vector"<<endl;
	DoubleEvenNumbers(v1);
	PrintVector(v1);
	GiveSalaryBonus(Employees);
	PrintAdultEmployees(Employees);
}