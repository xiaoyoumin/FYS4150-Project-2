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


double max_offdiag_symmetric(const arma::mat& A, int &k, int &l)        //to create a return type double taking in matrix A and int k, l
{
 
    int rows = A.n_rows;                                // rows  
    int cols =  A.n_cols;                               // coloumns
    
    if (rows!= cols){                                   //checking if dimensions match
        std::cout << "Dimensions are not equal!, not an identity matrix!";
        }

    int a = 0;

    for (int i = 0; i < rows; i++) {                     //nested for loop to iterate through matrix location
        for (int j = 0; j < cols; j++){
            if (i!= j){                                  //making sure its off-diagonal element
                if (abs(A(i,j)) > a ){                   
                    double a = abs(A(i,j));              //updating our largest off value = a
                    int k = i;                           //row number
                    int l = j;                           //coloumn number
                    }
                }
            }
        } 

        
    cout << "matrix indicies: " << "(\\k , \\l)";            //printing our largest off diagonal elements position 
    cout << "Largest value in matrix is: " << "\\a";         //printing out our largest off diagonal value

    return a;                                                //returns the value of the matrix element (largest off diagonal value)
    }



                                                                    
int main(){                                                 //testing with matrix A from task 3b yo

    mat A[] = {{1, 0, 0,0.5},
        {0, 1, -0.7, 0},
        {0, -0.7, 1, 0},
        {0.5, 0, 0, 1}
        }; 

    int k, l;

    double max = max_offdiag_symmetric(A, k, l);

    return 0;
}