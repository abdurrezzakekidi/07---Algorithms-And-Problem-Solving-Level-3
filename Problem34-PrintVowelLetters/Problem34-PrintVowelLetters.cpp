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

bool IsVowel(char ch1)
{
	ch1 = tolower(ch1);
	return (ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u');
}

void PrintVowels(string S1)
{
	cout << "Vowels in the string are : ";
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
			cout << S1[i] << "  ";
	}
}



int main()
{
	string S1 = ReadString();
	PrintVowels(S1);

}

