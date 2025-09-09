#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

const string fileName = "Clients.txt";

struct stClient
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double accountBalance;
};

string ReadAccountNumber()
{
    string AccountNumber = "";

    cout << "Please enter the account number of client: ";
    cin >> AccountNumber;

    return AccountNumber;
}

string ConvertRecordToLine(stClient client, string seperator = "#//#")
{
    string stClientRecord = "";

    stClientRecord += client.accountNumber + seperator;
    stClientRecord += client.pinCode + seperator;
    stClientRecord += client.name + seperator;
    stClientRecord += client.phone + seperator;
    stClientRecord += to_string(client.accountBalance);

    return stClientRecord;
}

vector<string> SplitString(string s1, string delimiter)
{
    vector<string> vString;
    short pos = 0;
    string word = "";

    while ((pos = s1.find(delimiter)) != string::npos)
    {
        cout << "found the delimiter at pos: " << pos << endl;

        word = s1.substr(0, pos);

        if (word != "")
            vString.push_back(word);

        s1.erase(0, pos + delimiter.length());
    }

    // no more delimiter found in the string (last word)
    if (s1 != "")
        vString.push_back(s1);

    return vString;
}

vector<string> ConvertAllRecordsToLine(vector<stClient> vRecords)
{
    vector<string> vClientsString;

    for (stClient record : vRecords)
    {
        vClientsString.push_back(ConvertRecordToLine(record));
    }

    return vClientsString;
}

stClient ConverLineToRecord(string line, string seperator = "#//#")
{
    stClient client;
    vector<string> vClientData;

    vClientData = SplitString(line, seperator);
    client.accountNumber = vClientData[0];
    client.pinCode = vClientData[1];
    client.name = vClientData[2];
    client.phone = vClientData[3];
    client.accountBalance = stod(vClientData[4]); // cast string to double 

    return client;
}

vector<stClient> LoadCleintsDataFromFile(string filePath)
{
    vector<stClient> vClients;
    fstream MyFile;
    MyFile.open(filePath, ios::in); // read Mode

    if (MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConverLineToRecord(Line);
            vClients.push_back(Client);
        }

        MyFile.close();
    }

    return vClients;
}

stClient FindClientByAccountNumber(const vector<stClient>& vData, const string& inputAccNum)
{

    for (stClient client : vData)
    {
        if (client.accountNumber == inputAccNum)
            return client;
    }

    // Return a "not found" dummy client
    return { "", "", "", "", 0.0 };
}

void PrintClientCard(const stClient& client)
{
    cout << "\nThe following client details:\n";

    cout << "Account Number: " << client.accountNumber << endl;
    cout << "Pin Code: " << client.pinCode << endl;
    cout << "Name: " << client.name << endl;
    cout << "Phone Number: " << client.phone << endl;
    cout << "Account Balance: " << client.accountBalance << endl;

}

void SaveVectorToFile(vector<string> vectorToSave)
{
    fstream file;
    file.open(fileName, ios::out);

    if (file.is_open())
    {
        for (string line : vectorToSave)
        {
            if (line != "")
                file << line << endl;
        }

        file.close();
    }
}

void DeleteClient(const vector<stClient>& vClients, const stClient& client)
{
    vector<string> vClientsString = ConvertAllRecordsToLine(vClients);

    for (string& line : vClientsString)
        if (line == ConvertRecordToLine(client))
        {
            line.clear();
        }

    SaveVectorToFile(vClientsString);

}

int main()
{
    vector<stClient> vClients = LoadCleintsDataFromFile(fileName);
    string accNum = ReadAccountNumber();

    stClient client = FindClientByAccountNumber(vClients, accNum);
    char choice;

    if (client.accountNumber != "")
    {
        PrintClientCard(client);
        
        cout << "Are you sure you want to delete this client? 'y' or 'n'";
        cin >> choice;

        if (tolower(choice) == 'y')
            DeleteClient(vClients, client);
    }

    else
    {
        cout << "\nA client with account number of (" << accNum << ") is not found!" << endl;
    }

    return 0;
}