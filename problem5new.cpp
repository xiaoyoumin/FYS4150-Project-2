
#include <iostream>
#include <string>
#include <armadillo>
#include <fstream>
bool isZero(arma::mat A){
    A.diag(0)-=A.diag(0);
    bool a=A.is_zero(1e-6);
    return a;
}
double AvgNrTransformations(int N){
    double s=0;
    for (int i=0;i<=100;i++){
    arma::mat A = arma::mat(N, N).randn(); 
        while (not isZero(A)){
            s++;
            A = arma::symmatu(A); 
        } 
    }
    s=s/10;
    return s;
}
int main(){
    for (int i=0;i<=100;i+=10){
        std::cout<<AvgNrTransformations(i)<<endl;
    }
    return 0;
}
