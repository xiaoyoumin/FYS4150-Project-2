#ifndef _EigSym_JcbAgrm_H_
#define _EigSym_JcbAgrm_H_

#include <armadillo>

void sym_check(arma::mat A, int n);
double max_offdiag_symmetric(const arma::mat A, int& k, int &l); //question 3a
arma::mat create_tridiagonal(int n, double a, double d, double e);
void jacobi_eigensolver(const arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors,
	const int maxiter, int& iterations, bool& converged);
void jacobi_rotate(arma::mat& A, arma::mat& R, int k, int l);




#endif 