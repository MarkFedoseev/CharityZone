#include "linal.h"
#include "stdlib.h"
#include "time.h"




double**  alloc2d(int n1, int n2) {
    double** matrix = (double**)malloc(sizeof(double*)*n1);
    for (int i = 0; i < n1; i++)
        matrix[i] = (double*)malloc(sizeof(double)*n2);
    return matrix;
}

void free2d(double** a, int n1, int n2) {
    for (int i = 0; i < n1; i++)
        free(a[i]);
    free(a);
}

double vabs(double* a, int n) {
    double sum2 = 0;
    for (int i = 0; i < n; i++)
        sum2 += a[i]*a[i];
    return sqrt(sum2);
}

double scal_prod(double* a, double* b, int n){
    double res = 0;
    for (int i = 0; i < n; i++)
        res += a[i]*b[i];
    return res;
}

void fill(double** a, int n1, int n2, double x) {
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            a[i][j] = rand()%100/100.;
}

void matrix_prod(double** a, double** b, double** c, int n1, int n2, int n3) {
    double *temp_vec = (double *) malloc(sizeof(double) * n2);
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n3; j++) {
            for (int h = 0; h < n2; h++)
                temp_vec[h] = b[h][j];
            c[i][j] = scal_prod(a[i], temp_vec, n2);
        }
    }
    free(temp_vec);
}

void show2d(double** a, int n1, int n2) {
    for(int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++)
            printf("%f ", a[i][j]);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    double** matrix1 = alloc2d(2, 3);
    double** matrix2 = alloc2d(3, 1);
    double** matrix3 = alloc2d(2, 1);
    double vec1[3] = {1, 2, 3};
    double vec2[3] = {4,5, 6};

    printf("%f\n", vabs(vec1, 3));
    printf("%f\n", vabs(vec2, 3));
    printf("%f\n", scal_prod(vec1, vec2, 3));
    printf("\n");
    fill(matrix1, 2, 3, 0.1);
    fill(matrix2, 3, 1, 0.2);
    show2d(matrix1, 2, 3);
    printf("\n");
    show2d(matrix2, 3, 1);
    printf("\n\n");
    matrix_prod(matrix1, matrix2, matrix3, 2, 3, 1);
    show2d(matrix3, 2, 1);
    free2d(matrix1, 2, 3);
    free2d(matrix2, 3, 1);
    free2d(matrix3, 2, 1);
    return 0;
}