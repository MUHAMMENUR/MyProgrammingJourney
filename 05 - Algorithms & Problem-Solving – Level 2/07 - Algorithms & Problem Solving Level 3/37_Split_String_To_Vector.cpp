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


vector <string> SplitString(string str,string delimiter) {
	short pos = 0;
	string sWord;
	vector <string> words;

	while ((pos = str.find(delimiter)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != ""){
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






int main()
{
	vector <string> Words;
	Words= SplitString(Readstring()," ");
	cout << "\nWords in the string are:\n";
	for (auto& words : Words) {
		cout << words << endl;
	}
	

	system("pause>0");
	
}

