#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
#include <fstream>

#include <armadillo>    //include our armadillo package and armadillo matricy form text file A.txt
mat A;
A.load("A.txt");

using namespace arma;
using namespace std;

int main(mat){
    int rows =  sizeof ary / sizeof mat[0]; // 2 rows  
    int cols = sizeof mat[0] / sizeof(int); // 5 cols
    int a = 0
    for (int i = 0; i < rows; i++) { 
        i = i;
        for (int j = 0; j < cols; j++) {
            j = j;
            if (i == j) {
                if(int mat[i][j] > a);
                    int a = mat[i][j]
                    } ;
        }
     }
    cout << "Largest value in matrix is: " << a;
    return a
}

int rows =  sizeof ary / sizeof mat[0]; // 2 rows  
int cols = sizeof mat[0] / sizeof(int); // 5 cols