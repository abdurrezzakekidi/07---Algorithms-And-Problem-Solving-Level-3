#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "D://MyCPP_Libs/MyStringUtility.h"

using namespace std;

const string ClientFileName = "Client.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(string s1, string delimiter)
{
    vector<string> v;
    short pos = 0;
    string word = "";

    while ((pos = s1.find(delimiter)) != string::npos)
    {
        cout << "found the delimiter at pos: " << pos << endl;

        word = s1.substr(0, pos);

        if (word != "")
            v.push_back(word);

        s1.erase(0, pos + delimiter.length());
    }

    // no more delimiter found in the string (last word)
    if (s1 != "")
        v.push_back(s1);

    return v;
}

stClient ConverLineToRecord(string Line, string Seperator = "#//#")
{
    stClient Client;
    vector<string> vClientData;
    vClientData = MyStringLib::SplitString(Line, Seperator);
    Client.AccountNumber = vClientData[0];
    Client.PinCode = vClientData[1];
    Client.Name = vClientData[2];
    Client.Phone = vClientData[3];
    Client.AccountBalance = stod(vClientData[4]); // cast string to double 

    return Client;
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
        if (client.AccountNumber == inputAccNum)
            return client;
    }

    // Return a "not found" dummy client
    return { "", "", "", "", 0.0 };
}

// Programming Advices Solution
bool findClientByAccNumberV2(const string& accountNumber, stClient& client)
{
    vector<stClient> vClients = LoadCleintsDataFromFile("");

    for (stClient c : vClients)
    {
        if (c.AccountNumber == accountNumber)
        {
            client = c; // assiging the found client
            return true;
        }
    }

    return false;
}

void PrintClientCard(const stClient& client)
{
    cout << "\nThe following client details:\n";

    cout << "Account Number: " << client.AccountNumber << endl;
    cout << "Pin Code: " << client.PinCode << endl;
    cout << "Name: " << client.Name << endl;
    cout << "Phone Number: " << client.Phone << endl;
    cout << "Account Balance: " << client.AccountBalance << endl;
}

int main()
{
    stClient Client;
    string AccountNumber = MyStringLib::ReadString("Please enter accout number:");

    if (findClientByAccNumberV2(AccountNumber, Client))
    { 
        PrintClientCard(Client);
    }
    else
    {
        cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!";
    }   
    system("pause>0");

    return 0;
}