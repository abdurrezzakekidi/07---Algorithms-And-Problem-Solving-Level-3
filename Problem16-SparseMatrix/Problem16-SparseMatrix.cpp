#include <iostream>
#include <iomanip>
#include <ctime>        

using namespace std;



void Print2DArray(int Matrix[3][3], short Rows, short Cols) {
    for (short i = 0; i < Rows; i++) {
        for (short j = 0; j < Cols; j++) {
            cout << setw(3) << Matrix[i][j] << " ";
        }
        cout << '\n';
    }
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

bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols) 
{
	short MatrixSize = Rows * Cols;

	return (CountNumberInMatrix(Matrix, Rows, Cols,0) >= (MatrixSize / 2));
}

int main() {
     

    int Matrix1[3][3] = {
        {10, 0, 3},
        {10, 0, 1},
        {10, 0, 1}
	};
    

    cout << "\nMatrix1:\n";
    Print2DArray(Matrix1, 3, 3);

    if (IsSparseMatrix(Matrix1, 3, 3))
        cout << "Yes: It is Sparse\n";
    else
        cout << "No: It's NOT Sparse\n";

    return 0;
}
