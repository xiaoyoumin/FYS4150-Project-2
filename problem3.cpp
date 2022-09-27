#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <fstream>

#include <armadillo>    //include our armadillo package and armadillo matricy form text file A.txt


using namespace arma;
using namespace std;

int main(){
    
    mat A;
    A.load("A.txt");

    int rows =  sizeof ary / sizeof mat[0]; // rows  
    int cols = sizeof mat[0] / sizeof(int); // cols
    float a = 0
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < cols; j++) {
            if (i == j) {
                if(int mat[i][j] > a);
                    a = mat[i][j]
                    } ;
        }
     }
    cout << "Largest value in matrix is: " << a;
    return a
}
