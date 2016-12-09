/* Exercise 11_1 */

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>
#include <stdlib.h>

int *allocate_int_array(int length);
void fill_with_fibonacci_sequence(int *data, int length);

int main(int argc, char* argv[])
{
	int i = 0, n = 0;
	int *data = NULL;

	printf("n = ");
	scanf("%d", &n);

	data = allocate_int_array(n);
	fill_with_fibonacci_sequence(data, n);

	printf("Die ersten %d Fibonacci-Zahlen:\n", n);
	for (i = 0; i < n; i++)
	{
		printf("F_%d = %d\n", i + 1, data[i]);
	}

	return 0;
}

int *allocate_int_array(int length)
{
	int *zeiger = malloc(length * sizeof(int));
	if (zeiger && length > 0) return zeiger;
	return NULL;
}

void fill_with_fibonacci_sequence(int *data, int length)
{
	data[0] = 1;
	if (length == 1) return;

	data[1] = 1;
	if (length == 2) return;

	int i = 1;
	while (i++ < length) {
		data[i] = data[i - 2] + data[i - 1];
	}
}
