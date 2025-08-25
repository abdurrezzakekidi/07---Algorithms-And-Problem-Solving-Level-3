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

string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sReplceTo)
{
	short pos = S1.find(StringToReplace);

	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(), sReplceTo);
		pos = S1.find(StringToReplace); // find next

	}
	return S1;

}

int main()
{
	string S1 = ReadString();

	string StringToReplace = "Syria";
	string ReplaceTo = "Turkey";

	cout << "\nOrigial String\n" << S1; 

	cout << "\n\nString After Replace:";

	cout << "\n" << ReplaceWordInStringUsingBuiltInFunction(S1, StringToReplace, ReplaceTo);


   
}


