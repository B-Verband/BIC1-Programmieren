/* Exercise 02_1, Teil 2 */

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>

/*
 *	Schreiben Sie ein Programm (orientiert sich am Programm input_output_prinzip), das drei reelle
 *	Zahlen multipliziert.
 *
 *	Lösungsweg:
 *	Achtung : Sie dürfen kein Array verwenden.Die Lösung des Problems ist wie folgt auszuführen:
 *		- In der main-Funktion werden die Werte erfasst.
 *		- Die Berechnung wird mithilfe einer eigenen Funktion ausgeführt. (Formel: Ergebnis = a * b * c)
 *		- In der main-Funktion wird das Ergebnis ausgegeben.
 */

	double multiplikation_von_drei_reellen_Zahlen(double a, double b, double c);

	int main(int argc, char * argv[]){

		double a, b, c;

		printf("1. reelle Zahl: ");
		scanf("%lf", &a);

		printf("2. reelle Zahl: ");
		scanf("%lf", &b);

		printf("3. reelle Zahl: ");
		scanf("%lf", &c);

		printf("a * b * c = %.1f\n", multiplikation_von_drei_reellen_Zahlen(a, b, c));
		//	- zu %.1f	-> das .1 rundet die Kommazahl auf eine Nachkommastelle
		// 	- zur Ausertungsreihenfolge: laut Rangtabelle wird als erstes die Funktion ausgewertet; wenn die Eingaben z.B. 1, 2 und 3 sind, ergibt das:
		// 		printf("a * b * c = %.1f\n", 6.0);
	}

	double multiplikation_von_drei_reellen_Zahlen(double a, double b, double c)
	{
		return a * b * c;
	}
