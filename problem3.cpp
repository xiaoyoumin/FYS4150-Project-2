#include <iostream>
#include <armadillo>    //include our armadillo package and armadillo matricy form text file A.txt

using namespace arma;
using namespace std;

// has return type double
// takes an Armadillo matrix as input
// takes references to two integers as input
// identifies the largest off-diagonal element (in absolute value) in the matrix, under the assumption of a symmetric matrix
// writes the matrix indices for this element to the two integer references
// returns the value of this matrix element


double max_offdiag_symmetric(const arma::mat& A, int& k, int &l)        //to create a return type double taking in matrix A and int k, l
{
 
    int rows = A.n_rows;                                // rows  
    int cols =  A.n_cols;                               // coloumns
    
    if (rows!= cols){                                   //checking if dimensions match
        std::cout << "Dimensions are not equal!";
        }

    int a = 0;

    for (int i = 0; i < rows; i++) {                     //nested for loop to iterate through matrix location
        for (int j = 0; j < cols; j++){
            if (i!= j){                                  //making sure its off-diagonal element
                if (abs(A(i,j)) > a ){                   
                    double a = abs(A(i,j));              //updating our largest off value = a
                    int k = i;                            //
                    int l = j; 
                    }
                }
            }
        } 

        
    cout << "position is :" << "(\\l , \\k)";
    cout << "Largest value in matrix is: " << a;         //printing out our largest off diagonal value
    return a;                                            //returning the value to whomever called the function (double data type)
    }