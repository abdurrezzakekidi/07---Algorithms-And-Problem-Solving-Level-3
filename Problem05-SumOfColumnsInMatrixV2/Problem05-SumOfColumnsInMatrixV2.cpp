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
			cout << setw(3) << array[i][j] << " ";
		}
		cout << endl;
	}
}

int ColSum(int arr[3][3], short Rows, short ColNumber)
{
	int Sum = 0;
	for (short i = 0; i <= Rows - 1; i++)
	{
		Sum += arr[i][ColNumber];
	}
	return Sum;
}
void SumMatixRowsInArry(int arr[3][3], int arrSum[3], short Rows, short Cols)
{
	for (short i = 0; i < Cols; i++)
	{
		arrSum[i] = ColSum(arr, Rows, i);
	}
}

void PrintRowsSumArray(int arrSum[3], short Cols)
{
	cout << "\nThe the following are the sum of each Col in the matrix:\n";
	for (short i = 0; i < Cols; i++)
	{
		cout << " Cols " << i + 1 << " Sum = " << arrSum[i] << endl;
	}
}

int main() {

	srand((unsigned)time(NULL)); // random seed

	int arr[3][3];
	int arrSum[3];

	Fill2DArrayWithRandomNumbers(arr, 3, 3);

	cout << "\nThe following is a 3x3 random matrix:\n";
	Print2DArray(arr, 3, 3);

	SumMatixRowsInArry(arr, arrSum, 3, 3);
	PrintRowsSumArray(arrSum, 3);
	system("pause>0");
}
