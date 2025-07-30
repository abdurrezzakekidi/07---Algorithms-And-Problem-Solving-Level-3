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
	for (short i = 0; i <= Rows -1; i++)
	{
		Sum += arr[i][ColNumber];
	}
	return Sum;
}
void PrintEachColSum(int arr[3][3], short Rows, short Cols)
{
	cout << "\nThe the following are the sum of each Col in the matrix:\n";
	for (short j = 0; j < Cols; j++)
	{
		cout << " Cols " << j + 1 << " Sum = " << ColSum(arr, Rows, j) << endl;
	}
}

int main() {

	srand((unsigned)time(NULL)); // random seed

	int array[3][3];

	Fill2DArrayWithRandomNumbers(array, 3, 3);
	cout << "The following is 3x3 random matrix:" << endl;
	Print2DArray(array, 3, 3);

	PrintEachColSum(array, 3, 3);
	return 0;
}
