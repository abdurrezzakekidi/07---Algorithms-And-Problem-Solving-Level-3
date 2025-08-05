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

void MultiplyMatrix(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0;  j  < Cols;  j ++)
		{
			MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];

		}
	}
}

int main()
{

	srand((unsigned)time(NULL)); // random seed

	int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];

	Fill2DArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	Print2DArray(Matrix1, 3, 3);

	Fill2DArrayWithRandomNumbers(Matrix2, 3, 3);
	cout << "\nMatrix2:\n";
	Print2DArray(Matrix2, 3, 3);

	MultiplyMatrix(Matrix1, Matrix2, MatrixResults, 3, 3);
	cout << "\nResults:\n";  
	Print2DArray(MatrixResults, 3, 3);



	system("pause>0");
}


