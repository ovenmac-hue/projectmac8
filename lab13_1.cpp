#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double S[],int N,double M[]){
    double sum = 0.0;
    double sum2 = 0.0;
    double allx = 1.0;
    double ally = 0.0;
    double max = S[0];
    double min = S[0];

    for(int i = 0; i < N; i++){
        sum += S[i];
        sum2 += S[i] * S[i];
        allx *= S[i];
        ally += 1.0 / S[i];
        if(S[i] > max) max = S[i];
        if(S[i] < min) min = S[i];
    }

    M[0] = sum / N;
    M[1] = sqrt((sum2 / N) - (M[0]* M[0]));
    M[2] = pow(allx, 1.0 / N);
    M[3] = N / ally;
    M[4] = max;
    M[5] = min;
}
