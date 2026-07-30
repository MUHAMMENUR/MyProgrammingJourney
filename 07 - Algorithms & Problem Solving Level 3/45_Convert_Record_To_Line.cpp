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

sClient ReadClient() {
	sClient client;
	cout << "Please enter the account number: ";
	cin >> client.AccountNumber;
	cout << "Please enter the pin code: ";
	cin >> client.PinCode;
	cout << "Please enter the name: ";
	cin.ignore();	
	getline(cin, client.Name);
	cout << "Please enter the phone number: ";
	cin >> client.Phone;
	cout << "Please enter the account balance: ";
	cin >> client.AccountBalance;
	return client;

}




string ConvertRecordToLine(sClient client, string Separator = "#//#") {
	string stClientRecord = "";
	stClientRecord += client.AccountNumber + Separator;
	stClientRecord += to_string(client.PinCode) + Separator;
	stClientRecord += client.Name + Separator;
	stClientRecord += client.Phone + Separator;
	stClientRecord += to_string(client.AccountBalance);
	return stClientRecord;


}


int main()
{
	cout << "\nPlease Enter Client Data: \n\n";
	sClient Client;
	Client = ReadClient();
	cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertRecordToLine(Client);
	

	system("pause>0");
}


