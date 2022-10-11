#include <iostream>
#include <math.h>

int main() {
	double a, b, c;
	double x1, x2;
	std::cin >> a >> b >> c;
	double D = b*b - 4*a*c;
	if (D < 0) {
		std::cout << "No real roots\n";
		return 0;
	}
	else {
		x1 = (-b + sqrt(D)) / (2*a);
		x2 = (-b - sqrt(D)) / (2*a);
	}
	if (x1 == x2)
		std::cout << "Two equal real roots: " << x1 << "\n";
	else
		std::cout << "Two real roots:\n" << "root1: " << x1 << "\n" << "root2: " << x2 << "\n";
	return 0;
}
