#include <iostream>
#include <iomanip>
#include "D:\MyCPP_Libs\MyRandomUtility.h"
#include "D:\MyCPP_Libs\MyInputsLib.h"

using namespace std;

void Fill2DArrayWithRandomNumbers(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			Matrix[i][j] = MyRandomLib::RandomNumber(1, 100);
		}
	}
}

void Print2DArray(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++) {
		for (short j = 0; j < Cols; j++) {
			cout << setw(3) << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}



bool NumberExistsInMatrix(int Matrix[3][3], short Rows, short Cols, short Number)
{
	
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				return true; // Number found
			};
		}
	}
	return false;
}

int main()
{
	srand((unsigned)time(NULL)); 

	int Matrix1[3][3];

	Fill2DArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";

	Print2DArray(Matrix1, 3, 3);

	short Number = MyInputLib::ReadPositiveNumber("Enter the number to look for in matrix: ");

	if (NumberExistsInMatrix(Matrix1, 3, 3, Number))
		cout << "Yes: it is there. \n";
	else
		cout << "No: It is NOT there.\n";
    
}


