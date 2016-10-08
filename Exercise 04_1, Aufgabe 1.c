/* Exercise 04_1, Aufgabe 1 */

/*
	Punkte: 12
	
	Aufgabe 1:
	Funktionen:
	Implementieren Sie folgende Formeln als Funktionen, wobei a und b vom Typ double sind
	und b zusätzlich als Konstante definiert wird.
		- result = a + b
		- result = b / a
		- result = a % b (Vergessen Sie nicht auf int zu typecasten)
		- result = a * a (Verwenden Sie die Funktion "Potenzieren" aus der <math.h> 
			Library! – siehe auch Referenzkarte)
		- Berücksichtigen Sie in der Funktion mit der Formel result = b / a, dass eine
			Division nur dann ausgeführt werden kann, wenn der Divisor ungleich Null ist!
	Main-Funktion:
		- Das Hauptprogramm liest mithilfe einer Schleifenkonstruktion genau 5x die Werte
			für a ein.
		- Innerhalb dieser Schleifenkonstruktion werden die Werte für a erfasst und alle
			Funktionen aufgerufen. (Überlegen Sie, welche Schleifenkonstruktion Sie hier
			auswählen müssen.)
		- Ein Zwischenspeichern der Werte von a ist daher nicht nötig.
		- Die Variable b wird als lokale Konstante mit dem Wert 5 in der main-Funktion
			vereinbart.
		- Jede Funktion soll mit einem beschreibenden Namen versehen werden.
		- Jede Funktion gibt bei ihrem Aufruf die Berechnungsformel und das Ergebnis aus.
			Der Rückgabewert ist somit void.
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>
#include <math.h>

void addieren(double a, double b);
void dividieren(double b, double a);
void modulo(double a, double b);
void zweier_potenz(double a);

int main(int argc, char* argv[])
{
	double a = 0.0;
	const double b = 5.0;

	for (int i = 1; i <= 5; i++) {
		printf("%d. Wert fuer a: ", i);
		scanf("%lf", &a);

		addieren(a, b);
		dividieren(b, a);
		modulo(a, b);
		zweier_potenz(a);
	}

	return 0;
}

void addieren(double a, double b)
{
	printf("\ta + b = %f\n", a + b);
}

void dividieren(double b, double a)
{
	if (!a) {
		printf("\tDivision b / a undefiniert, da a = 0\n");
		return;
	}
	printf("\tb / a = %f\n", b / a);
}

void modulo(double a, double b)
{
	printf("\ta %% b = %d\n", (int) a % (int) b);
}

void zweier_potenz(double a)
{
	printf("\ta ^ 2 = %f\n", pow(a, 2));
}
