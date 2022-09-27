#include<armadillo>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

arma::mat tridiag(arma::vec a, arma::vec b, arma::vec c) {
	arma::mat A(b.n_elem, b.n_elem, arma::fill::zeros);
	A.diag(0) = b;
	A.diag(-1) = a;
	A.diag(1) = c;
	return A;
}

int main()
{
	arma::vec a(5);
	a.ones();

	arma::vec b(6);
	b.ones();
	b = b * 2;

	arma::vec c(5);
	c.ones();
	c = c * 3;

	arma::mat A = tridiag(a, b, c);
	A.print("A=");

	/*
	for (int f = 0; f <= sqrt(A.n_elem) - 1; f++) {
		for (int i = 0; i <= sqrt(A.n_elem) - 1; i++) {
			cout << to_string(A(f, i)) + " ";
		}
		cout << endl;
	}
	*/
	arma::vec eigval;
	arma::mat eigvec;
	arma::eig_sym(eigval, eigvec, A);

	eigvec = normalise(eigvec);
	eigvec.print("correct normalized eigvecs from Armadillo:");
	cout << endl;
	eigval.print("eigvals:");
	cout << endl << endl;

}