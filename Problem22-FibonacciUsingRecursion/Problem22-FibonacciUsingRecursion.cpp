#include <iostream>
#include <iomanip>
//#include "D:\MyCPP_Libs\MyInputsLib.h"

using namespace std;

void PrintFibonacciUsingRecursion(short Number, int Prev1, int Prev2)
{
	int FebNumber = 0;

    if (Number > 0)
    {
        FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;
		std::cout << FebNumber << "    ";

        PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);
    }
    
}

int main()
{
	PrintFibonacciUsingRecursion(10, 0, 1);
    
}


