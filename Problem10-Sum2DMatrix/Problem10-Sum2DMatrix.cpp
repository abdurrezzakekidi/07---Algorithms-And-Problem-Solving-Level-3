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

int main()
{

	srand((unsigned)time(NULL)); // random seed

	int Matrix1[3][3];

	Fill2DArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";

	Print2DArray(Matrix1, 3, 3);

	cout << "\nSum of Matrix1 is: " << SumMatrix(Matrix1, 3, 3);
	



	system("pause>0");

}


