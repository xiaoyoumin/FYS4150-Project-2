// JacobianRotationAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
//#include <armadillo>

#include "Tester.h"
//#include "EigSym_JcbAgrm.h"

using namespace std;
//using namespace arma;

int main()
{
	mat A = { {1,0,0,0.5},
			{0,1,-0.7,0},
			{0,-0.7,1,0},
			{0.5,1,0,1} };

	cout << det(A) << endl;
	//Tester::test_max_offdiag_symmetric(A);

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
