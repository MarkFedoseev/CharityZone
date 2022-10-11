#include <iostream>

int main() {
	
	long long int x = 5;
	long long int y = 9;

	asm (
		"sub 8, %rsp\n\t"

	);

	/*
	asm(
		"movq %0, %%rdx\n\t"
		"movq %1, %0\n\t"
		"movq %%rdx, %1"
		: "=a"(x)
		: "a"(y)
		: "rdx"
	);
	*/

	std::cout << x << "\n" << y;

	return 0;
}
