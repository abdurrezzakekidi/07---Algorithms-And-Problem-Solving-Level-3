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

 void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols) 
 {
	 short MiddleRow = Rows / 2;
	 for (short i = 0; i < Cols; i++) 
	 {
		 printf(" %0*d   ", 2, arr[MiddleRow][i]);
	 } 
	 cout << "\n";
 } 
 void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols) 
 { short MiddleCol = Cols / 2;
 for (short j = 0; j < Rows; j++)
 {
	 printf(" %0*d   ", 2, arr[j][MiddleCol]);
 }
 cout << "\n";
 }
int main()
{

	srand((unsigned)time(NULL)); // random seed

	int Matrix1[3][3];

	Fill2DArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";
	Print2DArray(Matrix1, 3, 3);

	cout << "\nMiddle Row of Matrix1 is:\n";
	PrintMiddleRowOfMatrix(Matrix1, 3, 3);

	cout << "\nMiddle Col of Matrix1 is:\n";
	PrintMiddleColOfMatrix(Matrix1, 3, 3);

	system("pause>0");

}


