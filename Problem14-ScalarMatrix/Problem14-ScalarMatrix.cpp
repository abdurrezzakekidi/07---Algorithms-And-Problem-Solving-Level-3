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

bool IsScalarMatrix(int Matrix[3][3], short Rows, short Cols)
{
	int FirstDiagonalELement = Matrix[0][0];

	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			// Check if the diagonal elements are equal to the first diagonal element
			if (i == j && Matrix[i][j] !=FirstDiagonalELement)
			{
				return false;	
			}
			//
			else if (i != j && Matrix[i][j] != 0)
			{
				return false;
			}
		}
	}
	return true;
}



int main()
{


	int ScalarMatrix[3][3] =
	{
		{9, 0, 0},
		{0, 9, 0},
		{0, 0, 9}
	};

	int notScalarMatrix[3][3] =
	{
		{1, 0, 0},
		{0, 5, 0},
		{0, 0, 5}
	};


	//Print2DArray(ScalarMatrix, 3, 3);

	if (IsScalarMatrix(ScalarMatrix, 3, 3))
	{
		cout << "\nYES: Matrix is Scalar\n";
	}
	else
	{
		cout << "\nNo: Matrix is NOT Scalar\n";
	}



	return 0;



}


