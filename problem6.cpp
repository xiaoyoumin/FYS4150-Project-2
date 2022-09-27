
#include <iostream>
#include <string>
#include <armadillo>
#include <fstream>
#include <experimental/filesystem>

#include "JCB_rota_Algr\EigSym_JcbAgrm.h"
namespace fs = std::experimental::filesystem;


int calculate_eigenvectors(int n) {
	//Do the calculations and write the results to a file
	//arma::mat A;
	double h = 1.0 / n;
	double h2 = 1.0 / (h*h);
	arma::mat A = create_tridiagonal(n-1, -1.0 / pow(h, 2), 2.0 / pow(h, 2), -1.0 / pow(h, 2));
	double eps = pow(10, -8);
	arma::vec eigenvalues;
	arma::mat eigenvectors;
	int iterations;
	bool converged;
	//A.print();
	jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, n*n*n, iterations, converged);
	//eigenvectors.print("eigenvectors:");
	//eigenvalues.print("eigenvalues:");
	//std::cout << eigenvalues.index_min();
	arma::mat out;
	arma::vec eigv(3);

	out.insert_cols(0, eigenvectors.col(eigenvalues.index_min()));
	eigv(0) = eigenvalues.min();
	eigenvalues(eigenvalues.index_min()) = n * n*n;

	out.insert_cols(1, eigenvectors.col(eigenvalues.index_min()));
	eigv(1) = eigenvalues.min();
	eigenvalues(eigenvalues.index_min()) = n * n*n;

	out.insert_cols(2, eigenvectors.col(eigenvalues.index_min()));
	eigv(2) = eigenvalues.min();
	eigenvalues(eigenvalues.index_min()) = n * n*n;

	out.save("eigenvectors_" + std::to_string(n) + ".txt", arma::raw_ascii);
	eigv.save("eigenvalues_" + std::to_string(n) + ".txt", arma::raw_ascii);

	return 0;
}

int main() {
	//perform the cases for n = 10 and n = 100
	calculate_eigenvectors(10);
	calculate_eigenvectors(100);
	return 0;
}
