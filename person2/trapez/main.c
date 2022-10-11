#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f1(double x) {
    return x*x;
}
double f2(double x) {
    return 2*x*x + 5*x - 7;
}

typedef double (*finteg) (double);

double trapz(finteg f, double a, double b, int n) {
    double h = fabs(b - a) / n;
    double sum = (f(b) + f(a)) / 2;
    for (double x = a + h; x < b; x += h) {
        sum += f(x);
    }
    sum *= h;
    return sum;
}

double simpson(finteg f, double a, double b, int n) {
    double h = fabs(b - a) / n;
    double sum = 3./8 * (f(a) + f(b)) + 
                7./6 * (f(a + h) + f(b - h)) + 
                23./24 * (f(a + 2*h) + f(b - 2*h));
    for (double x = a + 3*h; x < b - 2*h; x += h) {
        sum += f(x);
    }
    sum *= h;
    return sum;
}

double trapz_adapt(finteg f, double a, double b, int n, double eps) {
    double h = fabs(b - a) / n;
    if (eps < 0) {
        a += h/2;
        eps = -eps;
    }
    double sum = (f(a) + f(b)) / 2;
    double q0 = f(a)*h;
    int counter = 1;
    for (double x = a + h; x < b; x += h) {
        q0 = f(x-h)*h;
        double q1 = f(x)*h;
        if (fabs(q0 - q1) < eps*q0) {
            sum += f(x);
            counter++;
        }
        else {
            //printf("%.15f\n", h);
            double prev = trapz_adapt(f, a, x, counter, -eps);
            prev = prev / h + f(a + h / 2) / 2 - f(x) / 2;
            sum += prev + f(x);
            h /= 2;
            counter *= 2;
            counter++;
        }
        //q0 = q1;
    }
    sum *= h;
    return sum;
}

double F(double x) {
    return 1./3*x*x*x;
}

int main(){
    finteg f = f1;
    double a = 1;
    double b = 2;
    int n = 10;
    double eps = 0.1;
    printf("trapz: %.10f\ntrapz_adapt: %.10f\nsimpson: %.10f\netalon: %.10f\n",
        trapz(f, a, b, n), trapz_adapt(f, a, b, n, eps), simpson(f, a, b, n), F(b) - F(a));
    return 0;
}