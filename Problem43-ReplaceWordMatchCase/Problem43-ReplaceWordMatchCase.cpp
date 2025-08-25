#include <iostream>
#include<vector>
#include <string>

using namespace std;

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

string JoinString(vector <string> vString, string Delim)
{
	string S1;
	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());
}

string LowerAllString(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

string ReplaceWordInStringUsingSplit(string S1,
	string StringToReplace, string sReplaceTo, bool MatchCase = true)
{
	vector <string> vString = SplitString(S1, " ");
	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = sReplaceTo;
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace))
			{
				s = sReplaceTo;
			}
		}
	}
	return JoinString(vString, " ");
}

    

int main()
{
	string S1 = "Welcome to Syria , Syria is a nice country";
	string StringToReplace = "syria"; 
	string ReplaceTo = "USA"; 

	cout << "\nOriginal String:\n" << S1;

	cout << "\n\nReplace with match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1,
		StringToReplace, ReplaceTo);

	cout << "\n\nReplace with dont match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(S1,
		StringToReplace, ReplaceTo, false);


    
}


