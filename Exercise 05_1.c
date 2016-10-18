/* Exercise 05_1 */

/*
	Punkte: 12
	 
	Was ist die kleinste Zahl die durch jede der Zahlen von 1 bis 20 teilbar ist?
 
	Beispiel: 60 ist die kleinste Zahl die durch alle Zahlen von 1 bis 5 ohne Rest teilbar ist. 2520 ist
	die kleinste Zahl die durch alle Zahlen von 1 bis 10 ohne Rest teilbar ist. 
 
	Finde die kleinste positive Zahl die durch alle Zahlen von 1 bis 20 ohne Rest teilbar ist. 
 
	Anmerkung: Lösen Sie das Beispiel einfach ohne Primfaktorenzerlegung etc., sondern nur mit Hilfe von
	einfachen Schleifenkonstruktionen!
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>

#define TEILER_MAX 20

int main(int argc, char* argv[])
{
	int getestete_zahl = TEILER_MAX;
	int teiler = 1;

	teiler = 1;
	while (teiler <= TEILER_MAX && getestete_zahl > 0)
	{
		if (getestete_zahl % teiler == 0)
		{
			teiler++;
		}
		else
		{
			getestete_zahl++;
			teiler = 1;
		}
	}

	printf("%d\n", getestete_zahl);

	return 0;
}
