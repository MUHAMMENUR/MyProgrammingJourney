#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientFile = "Clients.txt";
void ShowMainMenu();

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete=false;
};
enum enMainMenuOptions {
	eListClients = 1,
	eAddNewClient = 2,
	eDeleteClient = 3,
	eUpdateClient = 4,
	eFindClient = 5,
	eExit = 6
};
vector <string> Splitstring(string str, string delimiter) {
	vector<string> result;
	size_t pos = 0;
	string token;
	while ((pos = str.find(delimiter)) != string::npos) {
		token = str.substr(0, pos);
		result.push_back(token);
		str.erase(0, pos + delimiter.length());
	}
	result.push_back(str);
	return result;

}
sClient ConvertLineToRecord(string line, string delimiter = "#//#") {
	sClient Client;
	vector<string> vClient = Splitstring(line, delimiter);
	Client.AccountNumber = vClient[0];
	Client.PinCode = vClient[1];
	Client.Name = vClient[2];
	Client.Phone = vClient[3];
	Client.AccountBalance = stod(vClient[4]);
	return Client;
}
string ConvertRecordToLine(sClient Client, string delimiter = "#//#") {
	string line = "";
	line += Client.AccountNumber + delimiter;
	line += Client.PinCode + delimiter;
	line += Client.Name + delimiter;
	line += Client.Phone + delimiter;
	line += to_string(Client.AccountBalance);
	return line;
}
vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	vector <sClient> vClients;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientRecordLine(sClient Client)
{
	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(20) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;
	cout << endl;
}

void ShowAllClientsScreen()
{
	vector <sClient> vClients = LoadCleintsDataFromFile(ClientFile);

	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Account Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(20) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;

	if (vClients.size() == 0)
	{
		cout << "\t\t\t\tNo Clients Available In the System!";
	}
	else
	{
		for (sClient Client : vClients)
		{
			PrintClientRecordLine(Client);
		}
	}

	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName) {
	vector<sClient>Clients = LoadCleintsDataFromFile(FileName);


	for (sClient& Client : Clients) {
		if (Client.AccountNumber == AccountNumber) {
			return true;
		}
	}
	return false;
}

sClient ReadNewClient() {

	sClient client;
	while (true) {
		cout << "Enter Account Number: ";
		getline(cin >> ws, client.AccountNumber);
		if (!ClientExistsByAccountNumber(client.AccountNumber, ClientFile)) {
			break;
		}
		else {
			cout << "Account Number already exists. Please enter a different Account Number." << endl;
		}
	}
	
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
	AddDataLineToFile(ClientFile, ConvertRecordToLine(Client));
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

bool FindClientByAccountNumber(string AccountNumber, sClient& Client) {
	vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);

	for (sClient& C : vClients) {
		if (C.AccountNumber == AccountNumber) {
			Client = C;
			return true;
		}
	}
	return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector <sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {
	fstream MyFile;
	MyFile.open(FileName, ios::out); // Overwrite mode

	string DataLine;
	if (MyFile.is_open()) {
		for (sClient& C : vClients) {
			if (C.MarkForDelete == false) {
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientCard(sClient Client)
{
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------";
	cout << "\nAccount Number: " << Client.AccountNumber;
	cout << "\nPin Code     : " << Client.PinCode;
	cout << "\nName         : " << Client.Name;
	cout << "\nPhone        : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;
	cout << "\n-----------------------------------\n";
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want to delete this client? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
			SaveCleintsDataToFile(ClientFile, vClients);

			vClients = LoadCleintsDataFromFile(ClientFile);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}

	return false;
}

void ShowDeleteClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tDelete Client Screen";
	cout << "\n-----------------------------------\n";

	vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);
	string AccountNumber = "";

	cout << "\nPlease enter Account Number? ";
	cin >> AccountNumber;

	DeleteClientByAccountNumber(AccountNumber, vClients);
}

sClient ChangeClientRecord(string AccountNumber)
{
	sClient Client;
	Client.AccountNumber = AccountNumber;

	cout << "\nEnter PinCode: ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name: ";
	getline(cin, Client.Name);

	cout << "Enter Phone: ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance: ";
	cin >> Client.AccountBalance;

	return Client;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients)
{
	sClient Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);

		cout << "\n\nAre you sure you want to update this client? y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			for (sClient& C : vClients)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}
			}

			SaveCleintsDataToFile(ClientFile, vClients);
			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
		return false;
	}

	return false;
}

void ShowUpdateClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tUpdate Client Info Screen";
	cout << "\n-----------------------------------\n";

	vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);
	string AccountNumber = "";

	cout << "\nPlease enter Account Number? ";
	cin >> AccountNumber;

	UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowFindClientScreen()
{
	cout << "\n-----------------------------------\n";
	cout << "\tFind Client Screen";
	cout << "\n-----------------------------------\n";

	sClient Client;
	string AccountNumber = "";

	cout << "\nPlease enter Account Number? ";
	cin >> AccountNumber;

	if (FindClientByAccountNumber(AccountNumber, Client))
	{
		PrintClientCard(Client);
	}
	else
	{
		cout << "\nClient with Account Number [" << AccountNumber << "] is not found!";
	}
}
void GoBackToMainMenu()
{
	cout << "\n\nPress any key to go back to Main Menu...";
	system("pause>0");
	ShowMainMenu();
}

short ReadMainMenuOption()
{
	cout << "Choose what do you want to do? [1 to 6]? ";
	short Choice = 0;
	cin >> Choice;
	return Choice;
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOption)
{
	switch (MainMenuOption)
	{
	case enMainMenuOptions::eListClients:
		system("cls");
		ShowAllClientsScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eAddNewClient:
		system("cls");
		AddClients();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eDeleteClient:
		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eUpdateClient:
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eFindClient:
		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;

	case enMainMenuOptions::eExit:
		system("cls");
		cout << "\n-----------------------------------\n";
		cout << "\tProgram Ends :-)";
		cout << "\n-----------------------------------\n";
		break;
	}
}
void ShowMainMenu()
{
	system("cls");
	cout << "===========================================\n";
	cout << "\t\tMain Menu Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Show Client List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Exit.\n";
	cout << "===========================================\n";

	PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}
int main() {
	ShowMainMenu();
    return 0;
}