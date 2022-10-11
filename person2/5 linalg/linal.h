#ifndef LINAL
#define LINAL

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double** alloc2d(int n1, int n2); // выделяет память{}
void free2d(double** a, int n1, int n2); // освобождает память
double vabs(double* a, int n); // длина вектора
double scal_prod(double* a, double* b, int n); // скалярное произведение
void fill(double** a, int n1, int n2, double x); // заполняет матрицу значениями x
// n1 , n2 − dimensions o f mat r ix a ; r e turns c = a∗b
void matrix_prod(double** a, double** b, double** c, int n1, int n2, int n3); // вычисляет произведение матриц
void show2d(double** a, int n1, int n2); // вывод матрицы


#endif