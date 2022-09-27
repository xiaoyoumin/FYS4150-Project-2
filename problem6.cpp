
#include <iostream>
#include <string>
#include <armadillo>
#include <fstream>
#include <experimental/filesystem>

#include "JCB_rota_Algr/EigSym_JcbAgrm.h"
namespace fs = std::experimental::filesystem;

void write_to_file(arma::mat& matrix, std::string filename, int nvectors){
    //make the output directory if it doesn't exist yet
    fs::create_directories("./output");
    //open the file
    std::ofstream file;
    file.open("output/"+filename+".txt", std::ios::trunc);
    //make a header with the numer of columns and rows
    file << nvectors << "\t" << matrix.n_rows;
    //write the data
    for(int i=0; i<matrix.n_rows; i++)
    {
        for(int j=0; j<nvectors-1; j++)
        {   file << matrix[i,j] <<"\t";}
        file << matrix[i,nvectors-1] <<"\n";
    }
    file.close();
}

int calculate_eigenvectors(int n){
    //Do the calculations and write the results to a file
    arma::mat A;
    double h = 1/n;
    double h2 = 1/(h*h);
    A = create_tridiagonal(n,-h2,2*h2,-h2);
    double eps = 1E-8;
    arma::vec eigenvalues;
    arma::mat eigenvectors;
    int iterations;
    bool converged;

    void jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, n*n, iterations, converged);

    write_to_file(eigenvectors, "eigenvectors_" + string(n), 3);
    return 0;
}

int main(){
    //perform the cases for n = 10 and n = 100
    calculate_eigenvectors(10);
    calculate_eigenvectors(100);
    return 0;
}
