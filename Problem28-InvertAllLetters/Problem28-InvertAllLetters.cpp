#include <iostream>
#include "D:\MyCPP_Libs\MyStringUtility.h"

using namespace std;

char InvertLetterCase(char Char1)
{
	//short hand if
	return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

string InvertAllLettersCase(string S1)
{
	for (int i = 0; i < S1.length(); i++)
	{
		S1[i] = InvertLetterCase(S1[i]);
	}
	return S1;
}

int main()
{
	string s1 = MyStringLib::ReadString();
	cout << "\nString after Inverting All Letters Case:\n";
	s1 = InvertAllLettersCase(s1);
	cout << s1 << endl;

	return 0;
   
}


