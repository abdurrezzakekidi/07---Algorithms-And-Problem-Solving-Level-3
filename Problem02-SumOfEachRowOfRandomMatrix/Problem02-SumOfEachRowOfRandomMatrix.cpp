#include <iostream>
#include <iomanip>
#include "D:\MyCPP_Libs\MyRandomUtility.h"
#include "D:\MyCPP_Libs\ArrayLib.h"

using namespace std;

void Print2DArray(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < columns; j++) {
			cout << setw(3) << array[i][j] << " ";
		}
		cout << endl;
	}
}
int RowSum(int arr[3][3], short RowNumber, short Cols) 
{ 
	int Sum = 0; 
	for (short j = 0; j <= Cols - 1; j++)
	{ 
		Sum += arr[RowNumber][j];
	} 
	return Sum;
} 
void PrintEachRowSum(int arr[3][3], short Rows, short Cols) 
{
	cout << "\nThe the following are the sum of each row in the matrix:\n";
	for (short i = 0; i < Rows; i++)
	{ 
		cout << " Row " << i + 1 << " Sum = " << RowSum(arr, i, Cols) << endl;
	} 
}

int main() {

	srand((unsigned)time(NULL)); // random seed

	int array[3][3];

	MyArrayLib::Fill2DArrayWithRandomNumbers(array, 3, 3);
	cout << "The following is 3x3 random matrix:" << endl;
	Print2DArray(array, 3, 3);
	
	PrintEachRowSum(array, 3, 3);
	return 0;
}
