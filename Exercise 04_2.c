/* Exercise 04_2 */

/*
	Punkte: 12

	Aufgabe:
	Was ist die Summe aller natürlichen Zahlen unter 1000 welche Vielfache von 3 oder 5 sind?

	Beispiel: Wenn wir alle natürlichen Zahlen unter 10 auflisten die Vielfache von 3 oder 5
	sind, dann erhalten wir 3, 5, 6 und 9. Die Summe dieser Vielfachen ist 23.

	Berechne die Summe aller Vielfachen von 3 oder 5 unter 1000.
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>

int main(int argc, char* argv[])
{
	int summe = 0;
	
	for (int i = 1; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			summe = summe + i;
		}
	}

	printf("%d\n", summe);

	return 0;
}
