#include <iostream>

//unsafe

int main() {
	int x = 5;
	int y = 9;

	(&y)[-1] = y;
	y = x;
	x = (&y)[-1];

	std::cout << x << "\n" << y << "\n";
}
