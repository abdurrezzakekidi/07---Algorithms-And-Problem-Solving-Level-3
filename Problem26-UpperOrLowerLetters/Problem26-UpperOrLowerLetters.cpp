#include <iostream>
#include <string>
#include "D:\MyCPP_Libs\MyInputsLib.h"

using namespace std;

string  ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}

string UpperAllString(string S1)
{
	cout << "\nString After Upper:\n";
	for (short i = 0; i < S1.length(); i++)
		{
		
			S1[i] = toupper(S1[i]);
	}	
	return S1;
}

string LowerAllString(string S1)
{
	cout << "\nString After Lower:\n";
	for (short i = 0; i < S1.length(); i++)
	{

		S1[i] = tolower(S1[i]);
	}
	return S1;
}

int main()
{
	string S1 = ReadString();

	
	S1 = UpperAllString(S1);
	cout << S1 << endl;

	S1 = LowerAllString(S1);
    cout << S1 << endl;

}


