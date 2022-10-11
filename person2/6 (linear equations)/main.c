#include "linal.h"

int main() {

    srand(time(NULL));

    int An1 = 3;
    int An2 = 3;
    int bn = 3;

    //Ax = b
    double** A = alloc2d(An1, An2);
    double* b = alloc_vec(bn);

    fill2drandom(A, An1, An2);
    fill_vec_random(b, bn);



    return 0;
}

double* gauss(double** A, double* b, int n1, int n2) {
    double* x = alloc_vec(n2);

    /*
    //to save A in main:

    double** tmpA = alloc2d(n1, n2);
    copy2d(A, tmpA, n1, n2);
    A = tmpA;

    */

    for (int i = 1; i < n1; i++) {
        A[i] = 
    }

    return x;
}