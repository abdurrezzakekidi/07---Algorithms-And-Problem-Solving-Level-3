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

char  ReadChar()
{
    char Ch1;
    cout << "\nPlease Enter a Character?\n";
    cin >> Ch1;

    return Ch1;
}

char  InvertLetterCase(char char1) 
{ 
    return isupper(char1) ? tolower(char1) : toupper(char1);
}

short CountLetter(string S1, char Letter, bool MatchCase = true)
{
    short Counter = 0;
    for (short i = 0; i < S1.length(); i++)
    {
        if (MatchCase)
        {
            if (S1[i] == Letter)
                Counter++;
        }
        else
        {
            if (tolower(S1[i]) == tolower(Letter))
                Counter++;
        }

    }
    return Counter;

           
    
    
}

int main()
{
    string s1 = ReadString();
    char ch1 = ReadChar();

	cout << "\nLetter \'" << ch1 << "\' Count = " << CountLetter(s1, ch1);

    cout << "\nLetter\'" << ch1 << "\'";
    cout << "Or\'" << InvertLetterCase(ch1) << "'\ ";
    cout << "Count = " << CountLetter(s1, ch1, false);
	 
        


	return 0;


  

}


