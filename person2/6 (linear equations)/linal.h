#ifndef LINAL
#define LINAL

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

double** alloc2d(int n1, int n2); // выделяет память{}
void free2d(double** a, int n1, int n2); // освобождает память
double vabs(double* a, int n); // длина вектора
double scal_prod(double* a, double* b, int n); // скалярное произведение
//void fill(double** a, int n1, int n2, double x); // заполняет матрицу значениями x
// n1 , n2 − dimensions o f mat r ix a ; r e turns c = a∗b
void matrix_prod(double** a, double** b, double** c, int n1, int n2, int n3); // вычисляет произведение матриц
void show2d(double** a, int n1, int n2); // вывод матрицы

//=========================================================

void fill2d(double** a, int n1, int n2, double x);
void sum2d(double** a, double** b, double** c, int n1, int n2);
void diff2d(double** a, double** b, double** c, int n1, int n2);
void fill2drandom(double** a, int n1, int n2);
void fill_vec(double* vec, int n, double x);
void fill_vec_random(double* vec, int n);

//=========================================================

double**  alloc2d(int n1, int n2) {
    double** matrix = (double**)malloc(sizeof(double*)*n1);
    for (int i = 0; i < n1; i++)
        matrix[i] = (double*)malloc(sizeof(double)*n2);
    return matrix;
}
void realloc2d(double*** a, int n1, int n2) {
    *a = (double**)realloc(*a, )
}

double* alloc_vec(int n) {
    return (double*)malloc(sizeof(double)*n);
}

void sum2d(double** a, double** b, double** c, int n1, int n2) {
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            c[i][j] = a[i][j] + b[i][j];
}
void diff2d(double** a, double** b, double** c, int n1, int n2) {
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            c[i][j] = a[i][j] - b[i][j];
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

void fill2d(double** a, int n1, int n2, double x) {
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            a[i][j] = x;
}
void fill2drandom(double** a, int n1, int n2) {
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            a[i][j] = (double)rand();
}

void copy2d(double** src, double** dst, int n1, int n2) {
    for (int i = 0 ; i < n1; i++)
        for (int j = 0; j < n2; j++)
            dst[i][j] = src[i][j];
}

void matrix_prod_scalar(double** a, double C, int n1, int n2) {
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
            a[i][j] *= C;
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

void matrix_mergeRight(double*** a, double** b, int an1, int an2, int bn2) {
    if ((double**)realloc(*a, ))
    double** tmpA = alloc2d(an1, an2 + bn2);
    copy2d(a, tmpA, an1, an2);
    for (int i = 0; i < an1; i++)
        for (int j = an2, h = 0; j < an2 + bn2; j++, h++)
            tmpA[i][j] = b[i][h];
    free2d(a, an1, an2);
    a = 
}

void show2d(double** a, int n1, int n2) {
    for(int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++)
            printf("%f ", a[i][j]);
        printf("\n");
    }
}

void fill_vec(double* vec, int n, double x) {
    for (int i = 0; i < n; i++)
        vec[i] = x;
}
void fill_vec_random(double* vec, int n) {
    for (int i = 0; i < n; i++)
        vec[i] = (double)rand();
}

void copy_vec(double* src, double* dst, int n) {
    for (int i = 0; i < n; i++)
        dst[i] = src[i];
}

void vector_prod_scalar(double* vec, double C, int n) {
    for (int i = 0; i < n; i++)
        vec[i] += C;
}

void sum_vec(double* vec1, double* vec2, double* vec_res, int n) {
    for (int i = 0; i < n; i++)
        vec_res[i] = vec1[i] + vec2[i];
}

void diff_vec(double* vec1, double* vec2, double* vec_res, int n) {
    for (int i = 0; i < n; i++)
        vec_res[i] = vec1[i] - vec2[i];
}

#endif