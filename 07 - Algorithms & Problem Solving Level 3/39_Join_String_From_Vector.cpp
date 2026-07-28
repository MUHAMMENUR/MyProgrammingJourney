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

string Joinstring(vector <string>& vecstring, string delimiter) {

	string str = "";
	for (auto& s : vecstring) {
		str =str+ s + delimiter;
	}
	 return str.substr(0, str.length() - delimiter.length()); ;
}

int main()
{
	vector <string> vecstring = { "Muhammed","Nur","Sanda","Kanco" };
	cout << "Join string: " << endl;
	cout << Joinstring(vecstring, " ") << endl;

	system("pause>0");
	
}

