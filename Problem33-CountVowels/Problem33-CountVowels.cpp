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

short CountVowels(string S1)
{
	short CounterVowel = 0;
	for (short i = 0; i < S1.length(); i++)
	{
		if (IsVowel(S1[i]))
			CounterVowel++;

	}
	return CounterVowel;
}

int main()
{

	string S1 = ReadString();
	cout << "Number of Vowels is: " << CountVowels(S1);
    
}


