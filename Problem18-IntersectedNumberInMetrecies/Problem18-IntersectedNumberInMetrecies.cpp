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
			cout << setw(5) << Matrix[i][j] << " ";
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

void FindIntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	int Number;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Number = Matrix1[i][j];

			if (NumberExistsInMatrix(Matrix2, Rows, Cols, Number))
			{
				cout << setw(3) << Number << "   ";
			}
		}
	}
	
}




int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3], Matrix2[3][3];

	Fill2DArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	Print2DArray(Matrix1, 3, 3);

	Fill2DArrayWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	Print2DArray(Matrix2, 3, 3);

	FindIntersectedNumbers(Matrix1, Matrix2, 3, 3);

	

}


