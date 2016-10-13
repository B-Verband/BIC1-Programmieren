/* Exercise 05_2 */

/*
	 Punkte: 12
	 
	 Schreiben Sie ein Programm, das das kleine 1 x 1 ausgibt. Beachten Sie, dass auch die 1. Spalte
	 und die 1. Zeile ausgegeben werden. 

	 *	1	2	3	4	5	6	7	8	9	10
	 1	1	2	3	4	5	6	7	8	9	10
	 2	2	4	6	8	10	12	14	161	18	20
	 3	..............usw.....................
	 4	..............usw.....................
	 5	..............usw.....................
	 6	..............usw.....................
	 7	..............usw.....................
	 8	..............usw.....................
	 9	9	18	27	36	45	54	63	72	81	90
	 10	10	20	30	40	50	60	70	80	90	100
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>

#define ANZAHL 13

int main(int argc, char* argv[])
{
	int i = 0, j = 0;
	for (i = 0; i <= ANZAHL; i++)
	{
		/* Erste Zeile */
		if (i == 0) {
			printf("%4c", '*');
			for (j = 1; j <= ANZAHL; j++) {
				printf("%4d", (i + 1) * j);
			}
		}
		/* Restliche Zeilen */
		else {
			/* Erste Spalte */
			printf("%4d", i);
			/* Restliche Spalten */
			for (j = 1; j <= ANZAHL; j++) {
				printf("%4d", j * i);
			}
		}
		printf("\n");
	}

	return 0;
}
