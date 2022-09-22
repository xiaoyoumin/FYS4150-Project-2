#ifndef _Tester_H_
#define _Tester_H_

#include "EigSym_JcbAgrm.h"

class Tester
{
public:
	static void test_max_offdiag_symmetric(mat A);
	static void check_eig_match_anly(mat A);
	static void calc_anly_Sol(vec &eigval, mat &eigvec, double a, double d, mat A, int N);
	//static bool test_JCB_eig_sym();
};

#endif


