#ifndef _Tester_H_
#define _Tester_H_

#include "EigSym_JcbAgrm.h"


void test_max_offdiag_symmetric(arma::mat A);
void AnalyticalSols(arma::vec& eigval, arma::mat& eigvec, double a, double d, int N);
void test_jacobi_eigensolver();

#endif


