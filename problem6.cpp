
#include <iostream>
#include <string>
#include <armadillo>
#include <fstream>
#include <filesystem>


void write_to_file(arma::mat mat&, std::string& filename, int nvectors){
    std::filesystem::create_directories("./output")
    std::ofstream file("output/"filename+".txt", ios::trunc);
    file << nvectors << "\t" << mat.n_rows()
    for(i=0; i<n_step+1; i++)
    {
        x[i] = i*h;
        file << x[i] <<"\t" << v[i] <<"\n";
    }
}



//Pseudo code

//import the algorithm
??
EigSym_JcbAgrm A = EigSym_JcbAgrm(mat A, int n)
A.jacobi_eigensolver(const arma::mat& A, double eps, arma::vec& eigenvalues, arma::mat& eigenvectors, 
                        const int maxiter, int& iterations, bool& converged);
??
//Calculate the plot for n = 10 and n = 100

//Write the results to two files

