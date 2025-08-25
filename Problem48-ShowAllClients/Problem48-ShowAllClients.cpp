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

sClient ConvertLinetoRecord(const string& line, const string& sep = "#//#")
{
    sClient client;
    vector<string> f = SplitString(line, sep);

    // Dosyada eksik/sorunlu satır varsa erişim taşmasını önle
    if (f.size() >= 5) {
        client.AccountNumber = f[0];
        client.PinCode = f[1];
        client.Name = f[2];
        client.Phone = f[3];
        client.AccountBalance = std::stod(f[4]); // string -> double
    }
    return client;
}

vector<sClient> LoadClientsDataFromFile(const string& fileName)
{
    vector<sClient> clients;
    fstream in(fileName, ios::in);
    if (in.is_open()) {
        string line;
        while (std::getline(in, line)) {
            if (!line.empty())
                clients.push_back(ConvertLinetoRecord(line));
        }
        in.close();
    }
    return clients;
}

void PrintClientRecord(const sClient& c)
{
    cout << "| " << setw(15) << left << c.AccountNumber
        << "| " << setw(10) << left << c.PinCode
        << "| " << setw(25) << left << c.Name
        << "| " << setw(20) << left << c.Phone
        << "| " << setw(20) << left << fixed << setprecision(2) << c.AccountBalance;
}

void PrintAllClientsData(const vector<sClient>& clients)
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

    for (const sClient& c : clients) {
        PrintClientRecord(c);
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
