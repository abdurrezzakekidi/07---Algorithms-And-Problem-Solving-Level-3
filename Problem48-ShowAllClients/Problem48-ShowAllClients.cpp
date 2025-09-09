#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const string ClientsFileName = "Clients.txt";

struct sClient {
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance{};
};

vector<string> SplitString(string s, const string& delim)
{
    vector<string> parts;
    std::string::size_type pos = 0;

    while ((pos = s.find(delim)) != std::string::npos) {
        string token = s.substr(0, pos);
        if (!token.empty())
            parts.push_back(token);
        s.erase(0, pos + delim.length());
    }
    if (!s.empty())
        parts.push_back(s);

    return parts;
}

sClient ConvertLinetoRecord(const string line, const string& sep = "#//#")
{
    sClient client;
    vector <string> vClientData;

    vClientData = SplitString(line, sep);

    
    
        client.AccountNumber = vClientData[0];
        client.PinCode = vClientData[1];
        client.Name = vClientData[2];
        client.Phone = vClientData[3];
        client.AccountBalance = stod(vClientData[4]); // string -> double
    
    return client;
}

vector<sClient> LoadClientsDataFromFile(const string& fileName)
{
    vector<sClient> vClients;
    fstream Myfile;
     Myfile.open(fileName, ios::in); // read only

    if (Myfile.is_open())
    {
        string line;
		sClient client;

        while (std::getline(Myfile, line))
        {
            client = ConvertLinetoRecord(line);

			vClients.push_back(client);
        }
        Myfile.close();
    }
    return vClients;
}

void PrintClientRecord( sClient Client)
{
    cout << "| " << setw(15) << left << Client.AccountNumber
        << "| " << setw(10) << left << Client.PinCode
        << "| " << setw(25) << left << Client.Name
        << "| " << setw(20) << left << Client.Phone
        << "| " << setw(20) << left << fixed << setprecision(2) << Client.AccountBalance;
}

void PrintAllClientsData(vector<sClient>& clients)
{
    cout << "\n\t\t\t\t\tClient List (" << clients.size() << ") Client(s).";
    cout << "\n_______________________________________________________"
        "_________________________________________\n\n";
    cout << "| " << left << setw(15) << "Accout Number"
        << "| " << left << setw(10) << "Pin Code"
        << "| " << left << setw(25) << "Client Name"
        << "| " << left << setw(20) << "Phone"
        << "| " << left << setw(20) << "Balance" << '\n';
    cout << "_______________________________________________________"
        "_________________________________________\n";

    for (const sClient Client : clients) {
        PrintClientRecord(Client);
        cout << '\n';
    }

    cout << "_______________________________________________________"
        "_________________________________________\n\n";
}

int main()
{
    vector<sClient> clients = LoadClientsDataFromFile(ClientsFileName);
    PrintAllClientsData(clients);
    system("pause>0");
    return 0;
}
