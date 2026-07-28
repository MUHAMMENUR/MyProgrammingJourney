#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
void ReadNumber(vector <int>& Numbers) {
	char ch = 'Y';
	int Number=0;

	while (ch == 'Y' || ch == 'y') {
		cout << "Enter Number: ";
		cin >> Number;
		Numbers.push_back(Number);
		cout << "Do you want to enter another number? (Y/N): ";
		cin >> ch;

	}
}
void PrintNumbers(vector <int>& Numbers) {
	for (auto &n : Numbers) {
		cout << n << " ";
	}
}
int main() {
	vector<int> Numbers;
	ReadNumber(Numbers);
	PrintNumbers(Numbers);
}