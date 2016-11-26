/* Exercise 08_2 */

/*
	Punkte: 12

	Schreiben Sie eine Funktion, die die eine quadratische Gleichung ax^2 + bx + c = 0 löst.
	Wenn die Funktion erfolgreich durchgeführt wird, liefert die Funktion den Wert TRUE sonst
	den Wert FALSE zurück. Das Ergebnis wird mithilfe von pass-by-pointer an die aufrufende
	Funktion zurückgegeben.

	Erfassen Sie in der main-Funktion die Parameter, rufen Sie die Funktion auf und geben das
	Ergebnis, wenn möglich aus. Gibt es keine reelle Lösung, erfolgt eine kurze Fehlermeldung.
	Die Lösungen der allgemeinen quadratischen Gleichung lauten:
		x = (-b +- wurzel(b^2 - 4ac)) / 2a
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>
#include <math.h>

enum boolean { TRUE, FALSE };

int quadratische_gleichung(double a, double b, double c, double *x1, double *x2);

int main(int argc, char* argv[])
{
	double
		a = 0.0,
		b = 0.0,
		c = 0.0,
		x1 = 0.0,
		x2 = 0.0;

	printf("a: ");
	scanf("%lf", &a);
	printf("b: ");
	scanf("%lf", &b);
	printf("c: ");
	scanf("%lf", &c);

	if (quadratische_gleichung(a, b, c, &x1, &x2) == TRUE) {
		printf("x = %f", x1);
		if (x2 != 0) {
			printf(" oder %f", x2);
		}
	}
	else {
		printf("Kein Ergebnis.");
	}
	printf("\n");
}

int quadratische_gleichung(double a, double b, double c, double *x1, double *x2)
{
	if (!a) {
		return FALSE;
	}
	else {
		double diskriminante;

		diskriminante = b * b - 4 * a * c;

		if (diskriminante < 0) {
			return FALSE;
		}

		else {
			if (diskriminante == 0) {
				*x1 = -b / (2 * a);
			}
			else {
				*x1 = (-b + sqrt(diskriminante)) / (2 * a);
				*x2 = (-b - sqrt(diskriminante)) / (2 * a);
			}
			return TRUE;
		}
	}
}
