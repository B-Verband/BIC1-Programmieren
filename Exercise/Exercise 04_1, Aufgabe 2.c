/* Exercise 04_1, Aufgabe 2 */

/*
	Frage 1:
	Versuchen Sie eine sehr kleine Zahl (0.0000000000001) (Datentyp double) zu einer sehr großen Zahl
	(100000000000000) (Datentyp double) zu addieren. Welche Schlüsse können Sie daraus ziehen. Was 
	bedeutet dies für die Praxis?

	Frage 2:
	Vereinfachen Sie die Ausdrücke mithilfe des Dekrement- bzw. Inkrementoperators bzw. 
	Befehlsabkürzung.
		a = a + 1; result = a + z;
		Lösung: (Richtiges ankreuzen!)
			result = ++a + z;
			result = a++ + z;
			result = a-- + z;
			result = --a + z;
		result = a + z; a = a - 1;
		Lösung:
			result = ++a + z;
			result = a++ + z;
			result = a-- + z;
			result = --a + z;
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>

int main(int argc, char* argv[])
{
	/* Frage 1 */
	double kl_zahl = 0.0000000000001;
	double gr_zahl = 100000000000000;

	printf("%f\n", kl_zahl);
	printf("%f\n", gr_zahl);
	printf("%f\n", kl_zahl + gr_zahl);
	/* Schlüsse: funktioniert nicht */
	/* bedeutet für die Praxis: ??? */


	/* Frage 2 */
	int a = 2;
	int z = 4;
	int result = 0;

	result = (a + 1) + z;
	printf("%d\n", result);

	/* Richtige Lösung: zuerst erhöhen, dann auswerten */
	result = ++a + z; 
	printf("%d\n", result);

	result = (a - 1) + z;
	printf("%d\n", result);

	/* Richtige Lösung: zuerst erhöhen, dann auswerten */
	result = --a + z;
	printf("%d\n", result);
	
	return 0;
}
