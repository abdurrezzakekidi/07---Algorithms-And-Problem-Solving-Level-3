#include <iostream>
#include <string>



using namespace std;

char ReadCharacter()
{
	char Ch1;
	cout << "Please Enter Your Character?\n";
	cin >> Ch1;
	return Ch1;
}

char InvertLetterCase(char Char1)
{
	//short hand if
	return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

int main()
{
	char C1 = ReadCharacter();
	cout << "Character After Inverting Case: \n";

	C1 = InvertLetterCase(C1);
	cout << C1 << endl;
	return 0;
   
}

