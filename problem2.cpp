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

bool eigvalTest(arma::vec eigval, double d, double a){
    int N=eigval.n_elem;
    for (int i=1; i<=eigval.n_elem;i++){
        if (abs(eigval(i-1)-(d+2*a*cos(i * M_PI/(N+1))))>1e-6){
            return false;
        }

    }
    return true;
}
bool eigvecTest(arma::mat eigvec, double d, double a){
    int N=eigvec.n_elem;
    for (int i=1; i<=eigvec.n_elem;i++){
        for (int f=1; i<=eigvec.n_elem;i++){
            if (abs(eigvec(f-1,i-1)-(sin(f* i * M_PI/(N+1))))>1e-6){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    double h=1;
    double ad=(-1/(h*h));
    double dd=(2/(h*h));

	arma::vec a(5);
	a.ones();
    a=a*ad;

	arma::vec d(6);
	d.ones();
	d = d * dd;

	arma::mat A = tridiag(a, d, a);
	A.print("A=");

    
	arma::vec eigval;
	arma::mat eigvec;
	arma::eig_sym(eigval, eigvec, A);

	eigvec = normalise(eigvec);
	eigvec.print("correct normalized eigvecs from Armadillo:");
	cout << endl;
	eigval.print("eigvals:");
	cout << endl << endl;

    cout<<"Eigval corresponds with analytical solution: ";
    cout<<to_string(eigvalTest(eigval, dd, ad))<<endl;
    cout<<"Eigvec corresponds with analytical solution: ";
    cout<<to_string(eigvecTest(eigvec, dd, ad))<<endl;


}
