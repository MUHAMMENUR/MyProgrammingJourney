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


vector <string> SplitString(string str, string delimiter) {
	short pos = 0;
	string sWord;
	vector <string> words;

	while ((pos = str.find(delimiter)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != "") {
			words.push_back(sWord);
		}
		str.erase(0, pos + delimiter.length());
	}
	if (str != "")
	{
		words.push_back(str);
	}

	return words;
}



void PrintVectorInReverse(vector<string> words) {
	cout << "Words in the string are: " << endl;
	for (int i = words.size()-1; i>=0 ; i--) {
		cout << words[i] << endl;
	}
}


int main()
{
	string str1 = Readstring("Enter the string: ");
	vector<string> words = SplitString(str1, " ");
	PrintVectorInReverse(words);


	system("pause>0");
}


