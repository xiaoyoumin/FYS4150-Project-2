#ifndef _EigSym_JcbAgrm_H_
#define _EigSym_JcbAgrm_H_

#include <armadillo>

using namespace arma;

class EigSym_JcbAgrm
{
private:
	mat A;
	int n;

public:
	EigSym_JcbAgrm(mat A, int n);
	bool sym_check(mat A);
	mat get_A();
	void set_A(mat A);
	int get_n();
	void set_n(int n);
	double max_offdiag_symmetric(int& k, int &l); //question 3a
	

};



#endif 