#ifndef _Tester_H_
#define _Tester_H_

#include "EigSym_JcbAgrm.h"


void test_max_offdiag_symmetric(arma::mat A);
//void check_eig_match_anly(arma::mat A);
//void calc_anly_Sol(vec &eigval, mat &eigvec, double a, double d, mat A, int N);
void test_jacobi_eigensolver();

#endif


