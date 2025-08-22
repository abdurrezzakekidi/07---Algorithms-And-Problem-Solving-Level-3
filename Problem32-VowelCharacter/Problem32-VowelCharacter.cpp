#include <iostream>
#include <string>
using namespace std;


char  ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;

    return Ch1;
}

bool CkeckIsVovel(char ch1)
{
	char Vovels[] = { 'a','e','i','o','u','A','E','I','O','U' };
    for (short i = 0; i < sizeof(Vovels); i++)
    {
        if (ch1 == Vovels[i])
            return true;
	}
	return false;
}
bool IsVovel(char ch1)
{
	ch1 = tolower(ch1);
	return (ch1 == 'a' || ch1 == 'e' || ch1 == 'i' || ch1 == 'o' || ch1 == 'u');
}



int main()
{
    char ch1 = ReadChar();
	/*
	if (CkeckIsVovel(ch1))
		cout << "\nYes Letter \'" << ch1 << "\' is Vowel\n";
	else
		cout << "\nNo Letter \'" << ch1 << "\' is not Vowel\n";
		*/


	if (IsVovel(ch1))
		cout << "\nYes Letter \'" << ch1 << "\' is Vowel\n";
	else
		cout << "\nNo Letter \'" << ch1 << "\' is not Vowel\n";


    return 0;




}





