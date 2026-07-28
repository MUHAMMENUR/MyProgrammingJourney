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


void PrintEachWordInString(string str) {
	string delimiter = " ";
	short pos = 0;
	string sWord;


	while ((pos = str.find(delimiter)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != ""){
			cout<<sWord<<endl ;
		}

		str.erase(0, pos + delimiter.length());
	}
	if (str != "")
	{
		cout << str << endl; 
	}
}



int main()
{
    
	string input = Readstring();
	PrintEachWordInString(input);
}

