#include <iostream>
#include <iomanip>
#include "D:\MyCPP_Libs\MyRandomUtility.h"
#include "D:\MyCPP_Libs\MyInputsLib.h"


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

short ReadInvalidNumber()
{
	int Number;
	cout << "Enter the number to countin matrix? " << endl;
	cin >> Number;

	while (cin.fail())
	{
		// user didn't input a number
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalid Number, Enter a valid one: " << endl;

		cin >> Number;
	}
	return Number;
}
short CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols, short Number)
{
	int Count = 0;
	for (short i = 0; i < Rows; i++)
		{
		for (short j = 0; j < Cols; j++)
		{
			if (Matrix[i][j] == Number)
			{
				Count++;
			}
		}
	}
	return Count;
}


int main()
{

	srand((unsigned)time(NULL)); // random seed

	int Matrix1[3][3];

	Fill2DArrayWithRandomNumbers(Matrix1, 3, 3);
	cout << "\nMatrix1:\n";

	Print2DArray(Matrix1, 3, 3);

	int Number = ReadInvalidNumber();		
	int Count = CountNumberInMatrix(Matrix1, 3, 3, Number);
	cout << "\nThe number " << Number << " appears " << Count << " times in the matrix." << endl;

	return 0;

}


