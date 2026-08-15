#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientFile = "Clients.txt";

// Forward Declarations
void ShowMainMenu();
void ShowTransactionsMenu();

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

// =========================================================================
// 1. Text & File Processing Functions
// =========================================================================

vector<string> Splitstring(string str, string delimiter) {
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
    if (vClient.size() >= 5) {
        Client.AccountNumber = vClient[0];
        Client.PinCode = vClient[1];
        Client.Name = vClient[2];
        Client.Phone = vClient[3];
        Client.AccountBalance = stod(vClient[4]);
    }
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

vector<sClient> LoadCleintsDataFromFile(string FileName) {
    vector<sClient> vClients;
    fstream MyFile;
    MyFile.open(FileName, ios::in);
    if (MyFile.is_open()) {
        string Line;
        sClient Client;
        while (getline(MyFile, Line)) {
            if (Line != "") {
                Client = ConvertLineToRecord(Line);
                vClients.push_back(Client);
            }
        }
        MyFile.close();
    }
    return vClients;
}

vector<sClient> SaveCleintsDataToFile(string FileName, vector<sClient> vClients) {
    fstream MyFile;
    MyFile.open(FileName, ios::out);

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

void AddDataLineToFile(string FileName, string stDataLine) {
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}

// =========================================================================
// 2. Display Cards & Records
// =========================================================================

void PrintClientRecordLine(sClient Client) {
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(10) << left << Client.PinCode;
    cout << "| " << setw(20) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.Phone;
    cout << "| " << setw(12) << left << Client.AccountBalance;
    cout << endl;
}

void PrintClientRecordBalanceLine(sClient Client) {
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(25) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
    cout << endl;
}

void PrintClientCard(sClient Client) {
    cout << "\nThe following are the client details:\n";
    cout << "-----------------------------------";
    cout << "\nAccount Number : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n-----------------------------------\n";
}

// =========================================================================
// 3. Search & Validation Helpers
// =========================================================================

bool ClientExistsByAccountNumber(string AccountNumber, string FileName) {
    vector<sClient> Clients = LoadCleintsDataFromFile(FileName);
    for (sClient& Client : Clients) {
        if (Client.AccountNumber == AccountNumber) {
            return true;
        }
    }
    return false;
}

bool FindClientByAccountNumber(string AccountNumber, vector<sClient> vClients, sClient& Client) {
    for (sClient& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

// =========================================================================
// 4. Show All Clients
// =========================================================================

void ShowAllClientsScreen() {
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);

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

    if (vClients.size() == 0) {
        cout << "\t\t\t\tNo Clients Available In the System!";
    }
    else {
        for (sClient Client : vClients) {
            PrintClientRecordLine(Client);
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
}

// =========================================================================
// 5. Add New Client
// =========================================================================

sClient ReadNewClient() {
    sClient client;
    while (true) {
        cout << "Enter Account Number: ";
        getline(cin >> ws, client.AccountNumber);
        if (!ClientExistsByAccountNumber(client.AccountNumber, ClientFile)) {
            break;
        }
        else {
            cout << "Client with [" << client.AccountNumber << "] already exists, Enter another Account Number: \n";
        }
    }

    cout << "Enter Pin Code: ";
    getline(cin, client.PinCode);
    cout << "Enter Name: ";
    getline(cin, client.Name);
    cout << "Enter Phone: ";
    getline(cin, client.Phone);
    cout << "Enter Account Balance: ";
    cin >> client.AccountBalance;
    return client;
}

void AddNewClient() {
    sClient Client = ReadNewClient();
    AddDataLineToFile(ClientFile, ConvertRecordToLine(Client));
}

void ShowAddNewClientsScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Clients Screen";
    cout << "\n-----------------------------------\n";

    char AddMore = 'Y';
    do {
        cout << "Adding New Client:\n\n";
        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

// =========================================================================
// 6. Delete Client
// =========================================================================

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    for (sClient& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to delete this client? y/n ? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y') {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveCleintsDataToFile(ClientFile, vClients);
            vClients = LoadCleintsDataFromFile(ClientFile);
            cout << "\n\nClient Deleted Successfully.";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
    return false;
}

void ShowDeleteClientScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);
    string AccountNumber = "";

    cout << "\nPlease enter Account Number? ";
    cin >> AccountNumber;

    DeleteClientByAccountNumber(AccountNumber, vClients);
}

// =========================================================================
// 7. Update Client
// =========================================================================

sClient ChangeClientRecord(string AccountNumber) {
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

bool UpdateClientByAccountNumber(string AccountNumber, vector<sClient>& vClients) {
    sClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);

        cout << "\n\nAre you sure you want to update this client? y/n ? ";
        cin >> Answer;

        if (toupper(Answer) == 'Y') {
            for (sClient& C : vClients) {
                if (C.AccountNumber == AccountNumber) {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveCleintsDataToFile(ClientFile, vClients);
            cout << "\n\nClient Updated Successfully.";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
        return false;
    }
    return false;
}

void ShowUpdateClientScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);
    string AccountNumber = "";

    cout << "\nPlease enter Account Number? ";
    cin >> AccountNumber;

    UpdateClientByAccountNumber(AccountNumber, vClients);
}

// =========================================================================
// 8. Find Client
// =========================================================================

void ShowFindClientScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);
    sClient Client;
    string AccountNumber = "";

    cout << "\nPlease enter Account Number? ";
    cin >> AccountNumber;

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);
    }
    else {
        cout << "\nClient with Account Number [" << AccountNumber << "] is not found!";
    }
}

// =========================================================================
// 9. Transactions Section (Deposit, Withdraw, Total Balances)
// =========================================================================

bool DepositBalanceByAccountNumber(string AccountNumber, double Amount, vector<sClient>& vClients) {
    char Answer = 'n';
    cout << "\n\nAre you sure you want to perform this transaction? y/n ? ";
    cin >> Answer;

    if (toupper(Answer) == 'Y') {
        for (sClient& C : vClients) {
            if (C.AccountNumber == AccountNumber) {
                C.AccountBalance += Amount;
                SaveCleintsDataToFile(ClientFile, vClients);
                cout << "\n\nDone Successfully. New balance is: " << C.AccountBalance << endl;
                return true;
            }
        }
    }
    return false;
}

void ShowDepositScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);
    sClient Client;
    string AccountNumber = "";

    cout << "\nPlease enter Account Number? ";
    cin >> AccountNumber;

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        cout << "\nPlease enter Account Number? ";
        cin >> AccountNumber;
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter deposit amount? ";
    cin >> Amount;

    DepositBalanceByAccountNumber(AccountNumber, Amount, vClients);
}

void ShowWithdrawScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen";
    cout << "\n-----------------------------------\n";

    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);
    sClient Client;
    string AccountNumber = "";

    cout << "\nPlease enter Account Number? ";
    cin >> AccountNumber;

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
        cout << "\nPlease enter Account Number? ";
        cin >> AccountNumber;
    }

    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease enter withdraw amount? ";
    cin >> Amount;

    while (Amount > Client.AccountBalance) {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceByAccountNumber(AccountNumber, Amount * -1, vClients);
}

void ShowTotalBalancesScreen() {
    vector<sClient> vClients = LoadCleintsDataFromFile(ClientFile);

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(25) << "Client Name";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0) {
        cout << "\t\t\t\tNo Clients Available In the System!";
    }
    else {
        for (sClient& Client : vClients) {
            PrintClientRecordBalanceLine(Client);
            TotalBalances += Client.AccountBalance;
        }
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
}

// =========================================================================
// 10. Menus & Navigation
// =========================================================================

enum enTransactionsMenuOptions {
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalances = 3,
    eShowMainMenu = 4
};

enum enMainMenuOptions {
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eTransactions = 6,
    eExit = 7
};

void GoBackToMainMenu() {
    cout << "\n\nPress any key to go back to Main Menu...";
    system("pause>0");
    ShowMainMenu();
}

void GoBackToTransactionsMenu() {
    cout << "\n\nPress any key to go back to Transactions Menu...";
    system("pause>0");
    ShowTransactionsMenu();
}

short ReadTransactionsMenuOption() {
    cout << "Choose what do you want to do? [1 to 4]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

void PerformTransactionsMenuOption(enTransactionsMenuOptions Option) {
    switch (Option) {
    case enTransactionsMenuOptions::eDeposit:
        system("cls");
        ShowDepositScreen();
        GoBackToTransactionsMenu();
        break;

    case enTransactionsMenuOptions::eWithdraw:
        system("cls");
        ShowWithdrawScreen();
        GoBackToTransactionsMenu();
        break;

    case enTransactionsMenuOptions::eTotalBalances:
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToTransactionsMenu();
        break;

    case enTransactionsMenuOptions::eShowMainMenu:
        ShowMainMenu();
        break;
    }
}

void ShowTransactionsMenu() {
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tTransactions Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Deposit.\n";
    cout << "\t[2] Withdraw.\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menu.\n";
    cout << "===========================================\n";

    PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption());
}

short ReadMainMenuOption() {
    cout << "Choose what do you want to do? [1 to 7]? ";
    short Choice = 0;
    cin >> Choice;
    return Choice;
}

void PerformMainMenuOption(enMainMenuOptions MainMenuOption) {
    switch (MainMenuOption) {
    case enMainMenuOptions::eListClients:
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenu();
        break;

    case enMainMenuOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
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

    case enMainMenuOptions::eTransactions:
        system("cls");
        ShowTransactionsMenu();
        break;

    case enMainMenuOptions::eExit:
        system("cls");
        cout << "\n-----------------------------------\n";
        cout << "\tProgram Ends :-)";
        cout << "\n-----------------------------------\n";
        break;
    }
}

void ShowMainMenu() {
    system("cls");
    cout << "===========================================\n";
    cout << "\t\tMain Menu Screen\n";
    cout << "===========================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transactions.\n";
    cout << "\t[7] Exit.\n";
    cout << "===========================================\n";

    PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption());
}

int main() {
    ShowMainMenu();
    return 0;
}