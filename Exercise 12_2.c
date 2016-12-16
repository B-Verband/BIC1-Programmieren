/* Exercise 11_2 */

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>

int fibonacci(int n);

int main(void) {
	for (int i = 1; i <= 46; i++) {
		printf("%d\n", fibonacci(i));
	}
	return 0;
}
int fibonacci(int n) {
	if (n < 3) {
		return 1;
	}
	else {
		return fibonacci(n - 2) + fibonacci(n - 1);
	}
}
