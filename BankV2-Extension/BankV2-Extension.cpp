#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

void ShowMainMenue();
void ShowTransactionsMenueScreen();

enum enMainMenuOptions {
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
	eTransctions = 6,
    eExit = 7
};

enum enTransactionsMenuOptions {
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalances = 3,
    eMainMenue = 4
};

struct stClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

short ReadMainMenueOption() {
    cout << "Choose what do you want to do? [1 to 7]? ";
    short choice = 0;
    cin >> choice;
    return choice;
}

short ReadTransactionsMenueOption() {
    cout << "Choose what do you want to do? [1 to 4]? ";
    short choice = 0;
    cin >> choice;
    return choice;
}

vector<string> SplitString(string s1, string delimiter) {
    vector<string> vString;
    short pos = 0;
    string word = "";

    while ((pos = s1.find(delimiter)) != string::npos) {
        word = s1.substr(0, pos);
        if (word != "")
            vString.push_back(word);
        s1.erase(0, pos + delimiter.length());
    }

    if (s1 != "")
        vString.push_back(s1);

    return vString;
}

stClient ConvertLineToRecord(string line, string seperator = "#//#") {
    stClient client;
    vector<string> vClientData = SplitString(line, seperator);

    if (vClientData.size() < 5) {
        client.AccountNumber = "";
        client.PinCode = "";
        client.Name = "";
        client.Phone = "";
        client.AccountBalance = 0.0;
        return client;
    }

    client.AccountNumber = vClientData[0];
    client.PinCode = vClientData[1];
    client.Name = vClientData[2];
    client.Phone = vClientData[3];

    try {
        client.AccountBalance = stod(vClientData[4]);
    }
    catch (...) {
        client.AccountBalance = 0.0; // Hatalı sayıysa 0 ata
    }

    return client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#") {
    string stClientRecord = "";
    stClientRecord += Client.AccountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord += Client.Phone + Seperator;
    stClientRecord += to_string(Client.AccountBalance);
    return stClientRecord;
}

vector<stClient> LoadClientsDataFromFile(string filePath) {
    vector<stClient> vClients;
    fstream MyFile(filePath, ios::in);

    if (MyFile.is_open()) {
        string Line;
        stClient Client;
        while (getline(MyFile, Line)) {
            Client = ConvertLineToRecord(Line);
            vClients.push_back(Client);
        }
        MyFile.close();
    }
    return vClients;
}

vector<stClient> SaveClientsDataToFile(string FileName, vector<stClient> vClients) {
    fstream MyFile(FileName, ios::out);
    string DataLine;

    if (MyFile.is_open()) {
        for (stClient C : vClients) {
            if (!C.MarkForDelete) {
                DataLine = ConvertRecordToLine(C);
                MyFile << DataLine << endl;
            }
        }
        MyFile.close();
    }
    return vClients;
}

bool ClientExistsByAccountNumber(string AccountNumber, string FileName) {
    vector<stClient> vClients = LoadClientsDataFromFile(FileName);
    for (stClient& Client : vClients) {
        if (Client.AccountNumber == AccountNumber)
            return true;
    }
    return false;
}

double ReadAccountBalance() {
    double balance;
    while (true) {
        cout << "Enter AccountBalance? ";
        if (cin >> balance) {
            // doğru sayi girildi
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // satırdaki kalanı temizle
            return balance;
        }
        else {
            // yanlış giriş
            cout << "Invalid input. Please enter a numeric value.\n";
            cin.clear(); // hata bayrağını temizle
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // hatalı girdiyi temizle
        }
    }
}

stClient ReadNewClient() {
    stClient Client;

    cout << "Enter Account Number? ";
    getline(cin >> ws, Client.AccountNumber);
    while (ClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName)) {
        cout << "\nClient with [" << Client.AccountNumber << "] already exists, please enter another: ";
        getline(cin >> ws, Client.AccountNumber);
    }

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    Client.AccountBalance = ReadAccountBalance();

    return Client;
}

void AddDataLineToFile(string FileName, string stDataLine) {
    fstream MyFile(FileName, ios::out | ios::app);
    if (MyFile.is_open()) {
        MyFile << stDataLine << endl;
        MyFile.close();
    }
}

void AddNewClient() {
    stClient Client = ReadNewClient();
    AddDataLineToFile(ClientsFileName, ConvertRecordToLine(Client));
}

void AddNewClients() {
    char AddMore = 'Y';
    do {
        cout << "Adding New Client:\n\n";
        AddNewClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> AddMore;
    } while (toupper(AddMore) == 'Y');
}

void PrintClientRecordLine(stClient Client) {
    cout << "| " << left << setw(15) << Client.AccountNumber;
    cout << "| " << left << setw(10) << Client.PinCode;
    cout << "| " << left << setw(40) << Client.Name;
    cout << "| " << left << setw(15) << Client.Phone;
    cout << "| " << left << setw(12) << fixed << setprecision(2) << Client.AccountBalance;
}

void ShowAllClientsScreen() {
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    cout << "\n\t\tClient List (" << vClients.size() << ") Client(s).\n";
    cout << "----------------------------------------------------------------------------------------------------------------------\n";
    cout << "| " << left << setw(15) << "Account Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Name";
    cout << "| " << left << setw(15) << "Phone";
    cout << "| " << left << setw(12) << "Account Balance" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------\n";

    if (vClients.empty())
        cout << "\t\tNo Clients Available In The System!\n";
    else
        for (stClient Client : vClients) {
            PrintClientRecordLine(Client);
            cout << endl;
        }
    cout << "----------------------------------------------------------------------------------------------------------------------\n";
}

void PrintClientRecordBalanceLine(stClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber;
    cout << "| " << setw(40) << left << Client.Name;
    cout << "| " << setw(12) << left << Client.AccountBalance;
}

void PrintClientCard(stClient Client) {
    cout << "\nClient Details:\n";
    cout << "-----------------------------------------------------------------";
    cout << "\nAccount Number : " << Client.AccountNumber;
    cout << "\nPin Code       : " << Client.PinCode;
    cout << "\nName           : " << Client.Name;
    cout << "\nPhone          : " << Client.Phone;
    cout << "\nAccount Balance: " << Client.AccountBalance;
    cout << "\n----------------------------------------------------------------\n";
}

bool FindClientByAccountNumber(string AccountNumber, vector<stClient> vClients, stClient& Client) {
    for (stClient C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            Client = C;
            return true;
        }
    }
    return false;
}

bool MarkClientForDeleteByAccountNumber(string AccountNumber, vector<stClient>& vClients) {
    for (stClient& C : vClients) {
        if (C.AccountNumber == AccountNumber) {
            C.MarkForDelete = true;
            return true;
        }
    }
    return false;
}

stClient ChangeClientRecord(string AccountNumber) {
    stClient Client;
    Client.AccountNumber = AccountNumber;

    cout << "\nEnter PinCode? ";
    getline(cin >> ws, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    Client.AccountBalance = ReadAccountBalance();

    return Client;
}

bool DeleteClientByAccountNumber(string AccountNumber, vector<stClient>& vClients) {
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);
        cout << "\nAre you sure you want to delete this client? y/n: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            MarkClientForDeleteByAccountNumber(AccountNumber, vClients);
            SaveClientsDataToFile(ClientsFileName, vClients);
            vClients = LoadClientsDataFromFile(ClientsFileName);
            cout << "\nClient Deleted Successfully.";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
    return false;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector<stClient>& vClients) {
    stClient Client;
    char Answer = 'n';

    if (FindClientByAccountNumber(AccountNumber, vClients, Client)) {
        PrintClientCard(Client);
        cout << "\nAre you sure you want update this client? y/n: ";
        cin >> Answer;
        if (toupper(Answer) == 'Y') {
            for (stClient& C : vClients) {
                if (C.AccountNumber == AccountNumber) {
                    C = ChangeClientRecord(AccountNumber);
                    break;
                }
            }
            SaveClientsDataToFile(ClientsFileName, vClients);
            cout << "\nClient Updated Successfully.";
            return true;
        }
    }
    else {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }
    return false;
}

bool DepositBalanceToClientByAccountNumber(string AccountNumber, vector<stClient>& vClients, double Amount)
{
    
    char Answer = 'n';

    cout << "\n\nAre you sure you want perform this transaction? y/n ?";
	cin >> Answer;

    if (toupper(Answer) == 'Y')
    {
        for (stClient& C : vClients) 
        {
            if (C.AccountNumber == AccountNumber)
            {
                C.AccountBalance += Amount;
				SaveClientsDataToFile(ClientsFileName, vClients);
				cout << "\n\nDone Successfuly. New balance is: " << C.AccountBalance;
				return true;

            }
        }

		return false;
	}

}

string ReadClientAccountNumber() {
    string AccountNumber;
    cout << "\nPlease enter Account Number? ";
    cin >> AccountNumber;
    return AccountNumber;
}

void ShowDeleteClientScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tDelete Client Screen\n";
    cout << "-----------------------------------\n";
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    DeleteClientByAccountNumber(AccountNumber, vClients);
}

void ShowUpdateClientScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tUpdate Client Info Screen\n";
    cout << "-----------------------------------\n";
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();
    UpdateClientByAccountNumber(AccountNumber, vClients);
}

void ShowAddNewClientsScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tAdd New Client Screen\n";
    cout << "-----------------------------------\n";
    AddNewClients();
}

void ShowFindClientScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tFind Client Screen\n";
    cout << "-----------------------------------\n";
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    stClient Client;
    string AccountNumber = ReadClientAccountNumber();
    if (FindClientByAccountNumber(AccountNumber, vClients, Client))
        PrintClientCard(Client);
    else
        cout << "\nClient with Account Number [" << AccountNumber << "] is not found!";
}

void ShowDepositsScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tDeposit Screen\n";
    cout << "-----------------------------------\n";

    stClient Client;

    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with Account Number [" << AccountNumber << "] is not found, please enter another: ";
        getline(cin >> ws, AccountNumber);
    }
    PrintClientCard(Client);
    double Amount = 0;
    cout << "\nPlease Enter Deposit Amount? ";
    cin >> Amount;
    DepositBalanceToClientByAccountNumber(AccountNumber, vClients, Amount);
}

void ShowWithdrawScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tWithdraw Screen\n";
    cout << "-----------------------------------\n";

    stClient Client;
    vector<stClient> vClients = LoadClientsDataFromFile(ClientsFileName);
    string AccountNumber = ReadClientAccountNumber();

    while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
    {
        cout << "\nClient with Account Number [" << AccountNumber << "] is not found, please enter another: ";
        getline(cin >> ws, AccountNumber);
    }
    PrintClientCard(Client);

    double Amount = 0;
    cout << "\nPlease Enter Withdraw Amount? ";
    cin >> Amount;

    // validate that amount does not exeeds the account balance
    while (Amount > Client.AccountBalance)
    {
        cout << "\nAmount Exceeds the balance, you can withdraw up to : " << Client.AccountBalance << endl;
        cout << "Please enter another amount? ";
        cin >> Amount;
    }

    DepositBalanceToClientByAccountNumber(AccountNumber, vClients, -1 * Amount);
}

void ShowTotalBalances() 
{
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFileName); 

    cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl;   
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(40) << "Client Name";  
    cout << "| " << left << setw(12) << "Balance";  
    cout << "\n_______________________________________________________";  
    cout << "_________________________________________\n" << endl;

    double TotalBalances = 0;

    if (vClients.size() == 0) 
        cout << "\t\t\t\tNo Clients Available In the System!";
    else 

        for(stClient Client : vClients) 
        {
            PrintClientRecordBalanceLine(Client); 
            TotalBalances += Client.AccountBalance;  
            cout << endl;
        } 

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n" << endl; 
    cout << "\t\t\t\t\t   Total Balances = " << TotalBalances;
}

void ShowTotalBalancesScreen()
{
	 ShowTotalBalances();

}
    
  
void ShowEndScreen() {
    cout << "\n-----------------------------------\n";
    cout << "\tProgram Ends :-)\n";
    cout << "-----------------------------------\n";
}

void GoBackToMainMenue() {
    cout << "\n\nPress any key to go back to Main Menue...";
    system("pause>0");
    ShowMainMenue();
}

void GoBackToTransactionsMenue() {
    cout << "\n\nPress any key to go back to Transactions Menue...";
    system("pause>0");
    ShowTransactionsMenueScreen();
}

void PerfromMainMenueOption(enMainMenuOptions MainMenueOption) {
    switch (MainMenueOption) {
    case eListClients:
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    case eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;
    case eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;
    case eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;
    case eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

	case eTransctions:
		system("cls");
        ShowTransactionsMenueScreen();
    case eExit:
        system("cls");
        ShowEndScreen();
        break;
    }
}

void PerfromTransactionsMenueOption(enTransactionsMenuOptions TransactionsMenuOption) {
    switch (TransactionsMenuOption) {
    case eDeposit:
        system("cls");
        ShowDepositsScreen();
        GoBackToTransactionsMenue();
        break;
    case eWithdraw:
        system("cls");
		ShowWithdrawScreen();
        GoBackToMainMenue();
        break;

    case eTotalBalances:
        system("cls");
        ShowTotalBalancesScreen();
        GoBackToMainMenue();
        break;

    case eMainMenue:
        ShowMainMenue();
    }
}

void ShowMainMenue() {
    system("cls");
    cout << "=====================================\n";
    cout << "\tMain Menue Screen\n";
    cout << "=====================================\n";
    cout << "\t[1] Show Client List.\n";
    cout << "\t[2] Add New Client.\n";
    cout << "\t[3] Delete Client.\n";
    cout << "\t[4] Update Client Info.\n";
    cout << "\t[5] Find Client.\n";
    cout << "\t[6] Transections .\n";
    cout << "\t[7] Exit.\n";
    cout << "=====================================\n";
    PerfromMainMenueOption((enMainMenuOptions)ReadMainMenueOption());
}

void ShowTransactionsMenueScreen() {
    system("cls");
    cout << "=====================================\n";
    cout << "\tTransactions Menue Screen\n";
    cout << "=====================================\n";
    cout << "\t[1] Deposit .\n";
    cout << "\t[2] Withdraw .\n";
    cout << "\t[3] Total Balances.\n";
    cout << "\t[4] Main Menue.\n";
    cout << "=====================================\n";
    PerfromTransactionsMenueOption((enTransactionsMenuOptions)ReadTransactionsMenueOption());
}

int main() {
    ShowMainMenue();
    system("pause>0");
    return 0;
}
