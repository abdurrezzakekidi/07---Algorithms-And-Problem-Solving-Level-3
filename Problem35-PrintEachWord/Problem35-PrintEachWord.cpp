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

void PrintEachWord(string S1)
{
	cout << "Words in the string are : \n";
	string Word;
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
			Word += S1[i];
		else
		{
			cout << Word << "\n";
			Word = "";
		}
	}
	cout << Word << "\n";
}

void PrintEachWordInString(string S1)
{

	string delim = " "; // delimeter

	cout << "\n Your string words are: \n\n";
	short pos = 0; // position
	string sWord; // define a string variable

	// use find() function to get the position of delimeters
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // extract the word
		if (sWord != "")
		{
			cout << sWord << endl; // print the word
		}
		S1.erase(0, pos + delim.length()); /* erase() until positon and move to next word. */

	}
	if (S1 != "")
	{
		cout << S1 << endl; // print the last word
	}

}

int main()
{

	string S1 = ReadString();
	//PrintEachWord(S1);
	PrintEachWordInString(S1);
    
}


