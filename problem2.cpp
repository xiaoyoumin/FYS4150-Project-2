#include<armadillo>
#include<iostream>
#include<fstream>
#include<cmath>
#define _USE_MATH_DEFINES
#include<math.h>

using namespace std;

arma::mat tridiag(arma::vec a, arma::vec b, arma::vec c) {
	arma::mat A(b.n_elem, b.n_elem, arma::fill::zeros);
	A.diag(0) = b;
	A.diag(-1) = a;
	A.diag(1) = c;
	return A;
}

void eigvalTest(arma::vec& eigval, double d, double a, int N) {
	int n = N + 1;
	int i;
	for ( i = 1; i <= N; i++) {
		eigval(i - 1) = d + 2 * a*cos((i*M_PI) / n);

	}
}
void eigvecTest(arma::mat& eigvec, double d, double a, int N) {
	int n = N + 1;
	int i;
	for (i = 1; i <= N; i++) {
		for (int f = 1; f <= N; f++) {
			eigvec(i - 1, f - 1) = sin((i*f*M_PI) / n);
		}
	}
}

int main()
{
	double h = 1;
	double ad = (-1 / (h*h));
	double dd = (2 / (h*h));

	arma::vec a(5);
	a.ones();
	a = a * ad;

	arma::vec d(6);
	d.ones();
	d = d * dd;

	arma::mat A = tridiag(a, d, a);

	arma::vec eigval;
	arma::mat eigvec;
	arma::eig_sym(eigval, eigvec, A);

	eigvec = normalise(eigvec);
	eigvec.print("Armadillo eigvecs:");
	cout << endl;
	eigval.print("Armadillo eigvals:");
	cout << endl << endl;

	int N = 6;
	eigvalTest(eigval, 2.0, -1.0, N);
	eigvecTest(eigvec, 2.0, -1.0, N);

	eigvec = normalise(eigvec);
	eigvec.print("Analytical normalized eigvecs");
	cout << endl;
	eigval.print("Analytical eigvals:");
	cout << endl << endl;

}
