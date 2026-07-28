#include <string>
#include <vector>
#include <iostream>
using namespace std;

string Readstring() {
	string input;
	cout << "Enter a string: ";
	getline(cin, input);
	return input;
}

string Trimleft(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ') {
			return str.substr(i, str.length() - i);
		}
	}
	return "";
}

string Trimright(string Str) {
	for (int i = Str.length() - 1; i >= 0; i--) {
		if(Str[i]!=' ' ){
			return Str.substr(0, i + 1);
		}
	}
	return "";
}


string Trim(string Str) {
	return Trimright(Trimleft(Str));
}




int main()
{
	string str = Readstring();
	cout << "Trimleft: " << Trimleft(str) << endl;
	cout << "Trim left length: " << Trimleft(str).length() << endl;
	cout << "Trimright: " << Trimright(str) << endl;
	cout << "Trim right length: " << Trimright(str).length() << endl;
	cout << "Trim: " << Trim(str) << endl;
	cout << "Trim length: " << Trim(str).length() << endl;

	system("pause>0");
	
}

