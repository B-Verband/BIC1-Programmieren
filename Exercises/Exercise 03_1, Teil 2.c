/* Exercise 03_1, Teil 2 */

/*
	Punkte: 12

	Schreiben Sie eine Funktion, die die Summe von natürlichen Zahlen von
	eins bis 100 berechnet (for-Schleife) und rufen Sie diese Funktion vom
	Hauptprogramm auf. (Gaußsche Summenformel nicht erlaubt!, ohne der
	Datenstruktur Array lösen!)

	Erweiterung:
	Ergänzen Sie das bestehende Programm um eine weitere Funktion. Erfassen
	Sie in der main-Funktion die Anzahl der auszugebenden natürlichen Zahlen
	(Wertebereich somit 1 bis n) und entwickeln Sie eine neue Funktion, die
	diese Zahlen ausgibt (while-Schleife).

	Lösen Sie alle Aufgabenstellungen Aufgabe in einem Programm (Projekt)!
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>

int summe_nat_zahlen_1_bis_100();
void ausgabe_nat_zahlen(unsigned long anzahl);

int main(int argc, char* argv[])
{
	unsigned long anzahl = 0;

	printf(
		"Summe der natuerlichen Zahlen von 1 bis 100: %d\n",
		summe_nat_zahlen_1_bis_100()
	);

	printf("Anzahl der auszugebenden natuerlichen Zahlen: ");
	scanf("%lu", &anzahl);
	
	ausgabe_nat_zahlen(anzahl);
	
	return 0;
}

int summe_nat_zahlen_1_bis_100()
{
	int summe = 0;
	for (int i = 1; i <= 100; i++) {
		summe = summe + i;
	}
	return summe;
}

void ausgabe_nat_zahlen(unsigned long anzahl)
{
	unsigned long i = 1;
	while (i <= anzahl) {
		printf("%lu\n", i);
		i++;
	}
}
