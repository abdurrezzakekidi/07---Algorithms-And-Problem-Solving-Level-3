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

enum enWhatToCount
{
	SmallLetters = 1,
	CapitalLetters = 2,
	AllLetters = 3
};

short CountLetters(string S1, enWhatToCount whatToCount = enWhatToCount::AllLetters)
{
	if (whatToCount == enWhatToCount::AllLetters)
	{
		return S1.length();
	}
	short count = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if(whatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
			count++;

		else if(whatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
			count++;

	}
	return count;
}

int CountCapitalLetters(string s1)
{
	short count = 0;

	for (short i = 0; i < s1.length(); i++)
		if (isupper(s1[i]))
			count++;

	return count;
}

int CountSmallLetters(string s1)
{
	short count = 0;

	for (short i = 0; i < s1.length(); i++)
		if (islower(s1[i]))
			count++;

	return count;
}

int main()
{
	string s1 = ReadString();

	cout << "\nString Length is: " << s1.length() << endl;
	cout << "Capital Letters Count = " << CountCapitalLetters(s1) << endl;
	cout << "Small Letters Count = " << CountSmallLetters(s1) << endl;

	cout << "\n------ Using Generic Function ------\n";
	cout << "\nString Length is: " << CountLetters(s1) << endl;
	cout << "Capital Letters Count = " << CountLetters(s1, enWhatToCount::CapitalLetters) << endl;
	cout << "Small Letters Count = " << CountLetters(s1, enWhatToCount::SmallLetters) << endl;
  
}


