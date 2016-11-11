/* Exercise 07_1 */

/*
	Punkte: 12

	Aufgabe:
	Entwickeln Sie zwei Funktionen. Die eine Funktion erhöht den aufrufenden Parameter (reelle Zahl) um
	eins und die andere Funktion (reelle Zahl) erniedrigt den aufrufenden Wert um eins. Anwendung: „Call
	by pointer“

	Testen Sie diese beiden Funktionen mit entsprechenden Testfällen. 
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */#include <stdio.h>

void erhoehen(double *kommazahl);
void erniedern(double *kommazahl);

int main(int argc, char* argv[])
{
	double kommazahl = 0.0;

	printf("urspr. Wert: %f\n", kommazahl);
	erhoehen(&kommazahl);
	printf("erh. Wert: %f\n", kommazahl);
	erniedern(&kommazahl);
	printf("ern. Wert: %f\n", kommazahl);
}


void erhoehen(double *kommazahl)
{
	*kommazahl += 1;
}

void erniedern(double *kommazahl)
{
	*kommazahl -= 1;
}
