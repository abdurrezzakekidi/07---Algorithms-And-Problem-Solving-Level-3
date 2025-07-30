#include <iostream>
#include <iomanip>

using namespace std;

void Fill2DArrayWithOrderedNumbers(int array[3][3], short rows, short columns)
{
	short Counter = 0;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < columns; j++)
		{
			Counter++;
			array[i][j] = Counter;
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
void Print2DArrayTransposed(int array[3][3], short rows, short columns)
{
	for (short i = 0; i < columns; i++)
	{
		for (short j = 0; j < rows; j++)
		{
			cout << setw(3) << array[j][i] << " ";
		}
		cout << endl;
	}
}
int main()
{

	srand((unsigned)time(NULL)); // random seed

	int arr[3][3];


	Fill2DArrayWithOrderedNumbers(arr, 3, 3);

	cout << "\nThe following is a 3x3 Ordered matrix:\n";
	Print2DArray(arr, 3, 3);

	cout << "\n\nThe following is the transposed matrix:\n";
	Print2DArrayTransposed(arr, 3, 3);
}


