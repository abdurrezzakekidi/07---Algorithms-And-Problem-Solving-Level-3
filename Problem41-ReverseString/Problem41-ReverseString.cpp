#include <iostream>
#include<vector>
#include <string>

using namespace std;

string  ReadString()
{
	string S1;
	cout << "Please Enter Your String?\n";
	getline(cin, S1);
	return S1;
}

vector<string> SplitString(string s1, string delimiter)
{
	vector<string> vString;
	short pos = 0;
	string word = "";

	while ((pos = s1.find(delimiter)) != string::npos)
	{
		cout << "found the delimiter at pos: " << pos << endl;

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

string ReverseWordsInString(string S1)
{
	vector <string> vString;
	string S2 = "";

	vString = SplitString(S1, " ");

	//declare iterator
	vector <string> ::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;
		S2 += *iter + " ";
	}
	S2 = S2.substr(0, S2.length() - 1);

	return S2;
}

int main()
{
	string S1 = ReadString();

	cout << "\n\nString after reversing words";
	cout << "\n" << ReverseWordsInString(S1);

	return 0;
    
}

