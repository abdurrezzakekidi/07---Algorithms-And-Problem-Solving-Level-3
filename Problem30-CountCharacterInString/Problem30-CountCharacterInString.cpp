#include <iostream>
#include <string>
using namespace std;

string  ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}

char  ReadChar() 
{ 
    char Ch1; 
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;

    return Ch1;
}

short CountLetter(string S1, char Ch1)
{
    short count = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (S1[i] == Ch1)
            count++;
    }
    return count;
}

int main()
{
    string s1 = ReadString();
    char ch1 = ReadChar();

    cout << "\nLetter \'" << ch1 << "\' Count = " << CountLetter(s1, ch1);
	return 0;
    
}


