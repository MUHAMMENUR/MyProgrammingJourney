#include <string>
#include <vector>
#include <iostream>
using namespace std;



string Joinstring(vector <string>& vecstring, string delimiter) {

	string str = "";
	for (auto& s : vecstring) {
		str =str+ s + delimiter;
	}
	 return str.substr(0, str.length() - delimiter.length()); ;
}


string Joinstring(string str[], short size, string delimiter) {
	string result = "";
	for (int i = 0; i < size; i++) {
		result = result + str[i] + delimiter;
	}
	return result.substr(0, result.length() - delimiter.length());
	
}

int main()
{
	vector <string> vecstring = { "Muhammed","Nur","Sanda","Kanco" };
	string str[] = { "Muhammed","Nur","Sanda","Kanco" };
	short size = sizeof(str) / sizeof(str[0]);
	cout << "Join string: " << endl;
	cout << Joinstring(vecstring, " ") << endl;
	cout << Joinstring(str, size, " ") << endl;

	system("pause>0");
	
}

