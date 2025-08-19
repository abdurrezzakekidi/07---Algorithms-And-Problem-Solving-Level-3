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

bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols)
{
	for (short i = 0; i < Rows; i++)
	{
		for (short j = 0; j < Cols; j++)
		{
			if (i == j && Matrix[i][j] != 1)
			{
				return false;
				// Diagonal elements must be 1
			}

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


	int identityMatrix[3][3] =
	{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};

	int notIdentityMatrix[3][3] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	
	Print2DArray(identityMatrix, 3, 3);

	if (IsIdentityMatrix(identityMatrix, 3, 3))
	{
		cout << "\nMatrix1 is an Identity Matrix.\n";
	}
	else
	{
		cout << "\nMatrix1 is NOT an Identity Matrix.\n";
	}
	


	return 0;

	

}


