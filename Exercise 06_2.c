/* Exercise 06_2 */

/*
	Punkte: 12

	Finde das einzige Pythagoreische Tripel, {a, b, c}, für das gilt a + b + c = 1000.

	Ein Pythagoreisches Tripel besteht aus 3 natürlichen Zahlen, a < b < c, für die gilt,
	a^2 + b^2 = c^2

	Zum Beispiel: 3^2 + 4^2 = 5^2 (hier ist a + b + c = 12) oder 5^2 + 12^2 = 13^2 (hier
	ist a + b + c = 30).

	Es existiert genau ein Pythagoreisches Tripel für das a + b + c = 1000 ist. Finde
	dieses Tripel.
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[])
{
	int 
		a = 0, 
		b = 0, 
		c = 0;

	a = 0;
	while (a <= 1000) {
		b = a + 1;
		while (a + b <= 1000) {
			c = b + 1;
			while (a + b + c <= 1000) {
				if (a + b + c == 1000 && pow(a, 2) + pow(b, 2) == pow(c, 2))  {
					printf("a: %d, b: %d, c: %d\n", a, b, c);
					return 0;
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
