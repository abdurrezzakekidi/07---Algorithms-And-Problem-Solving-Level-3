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

short CountWordsInString(string S1)
{
	short CounterWords = 0;
	string delim = " "; // delimeter
	short pos = 0; // position
	string sWord; // define a string variable
	// use find() function to get the position of delimeters
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // extract the word
		if (sWord != "")
		{
			CounterWords++; // count the word
		}
		S1.erase(0, pos + delim.length()); /* erase() until positon and move to next word. */
	}
	if (S1 != "")
	{
		CounterWords++; // count the last word
	}
	return CounterWords;
}

int main()
{
	string S1 = ReadString();

	cout << "\nThe number of words in your string is: ";
	CountWordsInString(S1);

}


