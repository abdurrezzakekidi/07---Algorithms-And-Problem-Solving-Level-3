#include <iostream>
#include <string>
#include <vector>

using namespace std;

string JoinString(vector<string> vString, string Delimiter)
{
    string S1 ="";

    for (string& s : vString)
    {
		S1 = S1 + s + Delimiter;
      
    }
	return S1.substr(0, S1.length() - Delimiter.length());
}

int main()
{
    
    vector<string> vString = { "Mohammed","Ali","Ahmed","Mazen" };
    string S1 = JoinString(vString, "{,}");
    cout << S1 << endl;
	system("pause>0");
}


