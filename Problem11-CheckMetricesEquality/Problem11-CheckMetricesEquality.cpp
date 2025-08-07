#include <iostream>
#include <iomanip>
#include "D:\MyCPP_Libs\MyRandomUtility.h"
#include "D:\MyCPP_Libs\ArrayLib.h"

using namespace std;

void Fill2DArrayWithRandomNumbers(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			array[i][j] = MyRandomLib::RandomNumber(1, 10);
		}
	}
}

void Print2DArray(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			printf(" %0*d   ", 2, array[i][j]);
		}
		cout << endl;
	}
}

int SumMatrix(int Arr[3][3], short Cols, short Rows)
{
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			Sum += Arr[i][j];
		}
	}
	return Sum;
}
bool AreEqualMatrices(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
	return (SumMatrix(Matrix1, Rows, Cols) == SumMatrix(Matrix2, Rows, Cols));
}

int main()
{

	srand((unsigned)time(NULL)); // random seed

	int Matrix1[3][3], Matrix2[3][3];

	Fill2DArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	Print2DArray(Matrix1, 3, 3);
	cout << "\nSum of Matrix1 is: " << SumMatrix(Matrix1, 3, 3);

	Fill2DArrayWithRandomNumbers(Matrix2, 3, 3);
	cout << "\n\nMatrix2:\n";
	Print2DArray(Matrix2, 3, 3);
	cout << "\nSum of Matrix1 is: " << SumMatrix(Matrix2, 3, 3) <<endl;


	if(AreEqualMatrices(Matrix1, Matrix2, 3,3))
		cout << "\nYES: both martices are equal.";
	else
		cout << "\nNo: martices are NOT equal.";
	




	system("pause>0");

}


