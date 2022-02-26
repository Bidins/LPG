// create a recursive program that returns the summation of the number.
// example: somatorio(5) = 15 (5 + 4 + 3 + 2 + 1)

#include <stdio.h>

int somatorio(int num) {
	if (num == 0) {
		return 0;
	}
	return num + somatorio(num - 1);
}

int main(void) {
	printf("%d\n", somatorio(5));

	return 0;
}