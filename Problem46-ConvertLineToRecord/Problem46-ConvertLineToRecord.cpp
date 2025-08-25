#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

struct sClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;

};

vector<string> SplitString(string s1, string delimiter)
{
	vector<string> vString;
	short pos = 0;
	string word = "";

	while ((pos = s1.find(delimiter)) != string::npos)
	{
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

sClient ConvertLineToRecord(string Line, string Seprerator = "#//#")

{
    sClient Client;
    vector <string> vClientData;

	vClientData = SplitString(Line, Seprerator);

	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]); // cast string to double

	return Client;

}

void PrintClientRecord(sClient Client)
{
	cout << "\n\n The following is the extracted client record:\n";
	cout << "\nAccount Number:  " << Client.AccountNumber;
	cout << "\nPin Code:        " << Client.PinCode;
	cout << "\nName :            " << Client.Name;
	cout << "\nPhone:            " << Client.Phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;

}

int main()
{
	string stLine = "A182#//#1453#//#Abdurrezzak Ekidi#//#0534566554#//#5270.000000"; 
	cout << "\nLine Record is:\n";

	cout << stLine; sClient Client = ConvertLineToRecord(stLine);
	PrintClientRecord(Client);     system("pause>0");

    
}


