// ReduceTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include "ReduceLib.h"
#include <Windows.h>

typedef double (*funcAdd)(double, double);
typedef double (*funcMult)(double, double);
int main()
{
	HINSTANCE hDLL;
	funcAdd Add;
	funcMult Multiply;

	const wchar_t* libName = L"ReduceLib";

	hDLL = LoadLibraryEx(libName, NULL, NULL);   // Handle to DLL

	if (hDLL != NULL) {
		Add = (funcAdd)GetProcAddress(hDLL, "Add");
		Multiply = (funcMult)GetProcAddress(hDLL, "Multiply");
		if (Add != NULL) {
			std::cout << "10 + 10 = " << Add(10, 10) << std::endl;
		}
		else
			std::cout << "Did not load Add correctly." << std::endl;
		if (Multiply != NULL) {
			std::cout << "50 * 10 = " << Multiply(50, 10) << std::endl;
		}
		else
			std::cout << "Did not load Multiply correctly." << std::endl;


	}
	else {
		std::cout << "Library cannot be loaded!" << std::endl;
	}

	std::cin.get();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
