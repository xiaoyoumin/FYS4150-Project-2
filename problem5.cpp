#include <iostream>
#include <armadillo>    

using namespace arma;
using namespace std;

//add any other libraries we need

double offdiag(mat& A, int& p, int& q, int N); //declare+import our function from proble3.cpp


//including our task 3 function
double max_offdiag_symmetric(arma::mat A, int &k, int &l)        //to create a return type double taking in matrix A and int k, l
{
 
    int rows = A.n_rows;                                // rows  
    int cols =  A.n_cols;                               // coloumns
    
    if (rows!= cols){                                   //checking if dimensions match
        std::cout << "Dimensions are not equal!, not an identity matrix!";
        }

    double a = 0;

    for (int i = 0; i < rows; i++) {                     //nested for loop to iterate through matrix location
        for (int j = 0; j < cols; j++){
            if (i!= j){                                  //making sure its off-diagonal element
                if (abs(A(i,j)) > a ){                   
                    a = abs(A(i,j));              //updating our largest off value = a
                    k = i;                           //row number
                    l = j;                           //coloumn number
                    }
                }
            }
        } 

        
    cout << "matrix indicies: " << "("+to_string(k)+" , "+to_string(l)+")"<<endl;            //printing our largest off diagonal elements position 
    cout << "Largest value in matrix is: " << to_string(a)<<endl;         //printing out our largest off diagonal value

    return a;                                                //returns the value of the matrix element (largest off diagonal value)
    }
