#include <iostream>
#include <armadillo>    

using namespace arma;
using namespace std;

//add any other libraries we need

double offdiag(mat& A, int& p, int& q, int N); //declare+import our function from proble3.cpp

int main(){
    //we want to create and fill our matrices
}


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
                    a = abs(A(i,j));                     //updating our largest off value = a
                    k = i;                               //row number
                    l = j;                               //coloumn number
                    }
                }
            }
        } 

        
    cout << "matrix indicies: " << "("+to_string(k)+" , "+to_string(l)+")"<<endl;            //printing our largest off diagonal elements position 
    cout << "Largest value in matrix is: " << to_string(a)<<endl;         //printing out our largest off diagonal value

    return a;                                                //returns the value of the matrix element (largest off diagonal value)
    }


//including our jacobi rotate from task 4
void jacobi_rotate(mat& A, mat& R, int k, int l)
{
	double tau, t, s, c;
	double temp; //to preserve element in previous A and R
	int n = arma::size(A).n_rows;
	int i;

	tau = (A(l, l) - A(k, k)) / (2 * A(k, l));

	t = (-tau + sqrt(1 + pow(tau, 2))) > (-tau - sqrt(1 + pow(tau, 2))) ?
		-tau - sqrt(1 + pow(tau, 2)) : -tau + sqrt(1 + pow(tau, 2));
	c = 1 / sqrt(1 + pow(t, 2));
	s = c * t;
	
	temp = A(k, k);
	A(k, k) = A(k, k)*pow(c, 2) - 2 * A(k, l)*c*s + A(l, l)*pow(s, 2);
	A(l, l) = A(l, l)*pow(c, 2) + 2 * A(k, l)*c*s + temp*pow(s, 2);
	A(k, l) = 0;
	A(l, k) = 0;

	for (i = 0; i < n; i++)
	{
		if (i != k && i != l)
		{
			temp = A(i, k);
			A(i, k) = A(i, k)*c - A(i, l)*s;
			A(k, i) = A(i, k);
			A(i, l) = A(i, l)*c + temp*s;
			A(l, i) = A(i, l);
		}
			
		temp = R(i, k);
		R(i, k) = R(i, k)*c - R(i, l)*s;
		R(i, l) = R(i, l)*c + temp*s;
	}

//eigen value