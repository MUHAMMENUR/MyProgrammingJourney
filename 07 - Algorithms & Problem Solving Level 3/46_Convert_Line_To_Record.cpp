#include <string>
#include <vector>
#include <iostream>
using namespace std;



struct sClient {
	string AccountNumber;
	int PinCode;
	string Name;
	string Phone;
	int AccountBalance;
};


string Readstring(string message) {
	string str;
	cout << message;
	getline(cin >> ws, str);
	return str;
}


/**
 * Function: SplitString
 * ---------------------
 * Splits a line by custom delimiter (#//#) into a vector of strings.
 */
vector<string> SplitString(string str, string delimiter = "#//#") {
	vector<string> vTokens;
	short pos = 0;
	string sWord;

	while ((pos = str.find(delimiter)) != std::string::npos) {
		sWord = str.substr(0, pos);
		if (sWord != "") {
			vTokens.push_back(sWord);
		}
		str.erase(0, pos + delimiter.length());
	}

	if (str != "") {
		vTokens.push_back(str);
	}

	return vTokens;
}

sClient ConvertLinetoRecord(string line, string delimiter = "#//#") {
	sClient Client;
	vector <string> vClientData = SplitString(line, delimiter);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = stoi(vClientData[1]);
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stoi(vClientData[4]);
	return Client;
}


void PrintClientRecord(sClient Client) {
	cout << "Account Number: " << Client.AccountNumber << endl;
	cout << "Pin Code: " << Client.PinCode << endl;
	cout << "Name: " << Client.Name << endl;
	cout << "Phone: " << Client.Phone << endl;
	cout << "Account Balance: " << Client.AccountBalance << endl;
}

int main()
{
	sClient Client1;

	Client1 = ConvertLinetoRecord(Readstring("Enter All of the Client Data in one line: "));
	PrintClientRecord(Client1);

	
	

	system("pause>0");
}


