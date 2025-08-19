#include <iostream>
#include <iomanip>

using namespace std;

void Print2DArray(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(5) << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols / 2; j++) {
			if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
			{
				return false; 
			}
		}
	}
	return true; 
}

int main()
{

	int Matrix1[3][3] = {
		{ 1, 2, 1 }, 
	    { 5, 5, 5 }, 
	    { 7, 3, 7 } 
	};

	Print2DArray(Matrix1, 3, 3);

	if(IsPalindromeMatrix(Matrix1, 3,3))
		cout << "Matrix1 is a palindrome matrix." << endl;
	else
		cout << "Matrix1 is not a palindrome matrix." << endl;


}


