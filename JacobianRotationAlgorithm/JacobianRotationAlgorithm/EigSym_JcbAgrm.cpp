#include "EigSym_JcbAgrm.h"
#include <iostream>
#include <cmath>

using namespace std;



EigSym_JcbAgrm::EigSym_JcbAgrm(mat A, int n)
{
	if (sym_check(A))
		this->A = A;
	else this->A = 0.0;
	this->n = n;
}

bool EigSym_JcbAgrm::sym_check(mat A)
{
	int i, j;

	for (i = 0; i < n-1; i++)
		for (j = i + 1; j < n; j++)
			if (A(i, j) != A(j, i))
				return false;

	return true;
}



mat EigSym_JcbAgrm::get_A()
{
	return A;
}



void EigSym_JcbAgrm::set_A(mat A)
{
	if(sym_check(A))
		this->A = A;
	else this->A = 0.0;
}

int EigSym_JcbAgrm::get_n()
{
	return n;
}

void EigSym_JcbAgrm::set_n(int n)
{
	this->n = n;
}



double EigSym_JcbAgrm::max_offdiag_symmetric(int& k, int &l)
{
	int i, j;
	double max=0;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (abs(A(i, j)) > max)
			{
				max = A(i, j);
				k = i; //row index
				l = j; //col index
			}
	return max;
}