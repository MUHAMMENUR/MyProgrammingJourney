#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
const string ClientsFileName = "Clients.txt";

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
};

sClient ReadNewClient(){

	sClient client;
	cout << "Enter Account Number: ";
	getline(cin >> ws, client.AccountNumber);
	cout << "\nEnter pin code: ";
	getline(cin >> ws, client.PinCode);
	cout << "\nEnter Name: "; 
	getline(cin >> ws, client.Name);
	cout << "\nEnter Phone: ";
	getline(cin >> ws, client.Phone);
	cout << "\nEnter Account Balance: ";
	cin >> client.AccountBalance;
	return client;
}

string ConvertRecordToLine(sClient Client, string Seperator =
	"#//#")
{
	string stClientRecord = "";
	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);
	return stClientRecord;
}

void AddDataLineToFile(string FileName, string stDataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);
	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;
		MyFile.close();
	}
}


void AddNewClient()
{
	sClient Client;
	Client = ReadNewClient();
	AddDataLineToFile(ClientsFileName,
		ConvertRecordToLine(Client));
}


void AddClients()
{
	char AddMore = 'Y';
	do
	{
		system("cls");
		cout << "Adding New Client:\n\n";
		AddNewClient();
		cout << "\nClient Added Successfully, do you want to add more clients ? Y / N ? ";
			
			cin >> AddMore;
	} while (toupper(AddMore) == 'Y');
}

int main()
{
	AddClients();
	system("pause>0");
	return 0;
}