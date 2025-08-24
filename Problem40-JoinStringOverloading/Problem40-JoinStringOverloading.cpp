#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(vector<string> vString, string Delimiter)
{
    string S1 = "";

    for (string& s : vString)
    {
        S1 = S1 + s + Delimiter;

    }
    return S1.substr(0, S1.length() - Delimiter.length());
}

string JoinString(string arrSreing[], short Length, string Delimiter)
{
    string S1 = "";
    for (short i = 0; i < Length; i++)
    {
        S1 = S1 + arrSreing[i] + Delimiter;
    }
	return S1.substr(0, S1.length() - Delimiter.length());
    
}

int main()
{

    vector<string> vString = { "Mohammed","Ali","Ahmed","Mazen" };

    string S1 = JoinString(vString, "!");
    cout << S1 << endl;

	string arrString[] = { "Mohammed","Ali","Ahmed","Mazen" };
	S1 = JoinString(arrString, 4, "!");
	cout << S1 << endl;


    system("pause>0");
}


