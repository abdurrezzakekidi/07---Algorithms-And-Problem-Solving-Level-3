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

int MaxNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int Max = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] > Max)
			{
				Max = Matrix[i][j];
			}
		}
	}
	return Max;
}

int MinNumberInMatrix(int Matrix[3][3], short Rows, short Cols)
{
	short Min = Matrix[0][0];
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] < Min)
			{
				Min = Matrix[i][j];
			}
		}
	}
	return Min;
}


int main()
{
	srand((unsigned)time(NULL));

	int Matrix1[3][3];

	Fill2DArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	Print2DArray(Matrix1, 3, 3);

	cout << "\nMax Number in Matrix: ";
	cout << MaxNumberInMatrix(Matrix1, 3, 3);

	cout << "\nMin Number in Matrix: ";
	cout << MinNumberInMatrix(Matrix1, 3, 3);


	return 0;
}


