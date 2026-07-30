#include <string>
#include <vector>
#include <iostream>
using namespace std;



string Readstring(string str1) {
	string str = "";
	cout << str1;
	getline(cin, str);
	return str;

}



string RemovePunctuationsFromString(string str) {
	string str2 = "";
	for(int i=0;i<str.length();i++){
		if (!ispunct(str[i])) {
			str2 += str[i];
		}
	}
	return str2;
}





int main()
{
	
	string str = Readstring("Enter a string: ");
	cout << "String after removing punctuations: " << RemovePunctuationsFromString(str) << endl;

	system("pause>0");
}


