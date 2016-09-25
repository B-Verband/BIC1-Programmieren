/* Exercise 01_2 */

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>

double flaeche_rechtwinkeliges_dreieck(double a, double b);
double volumen_keil(double a, double b, double c);

int main(int argc, char* argv[])
{
	double a, b, c;

	printf("Seite a des Keils: ");
	scanf("%lf", &a);
	printf("Seite b des Keils: ");
	scanf("%lf", &b);
	printf("Seite c des Keils: ");
	scanf("%lf", &c);
	
	printf("Volumen des Keils: %.1f\n", volumen_keil(a, b, c));

	return 0;
}

double flaeche_rechtwinkeliges_dreieck(double a, double b)
{
	return a * b / 2;
}

double volumen_keil(double a, double b, double c)
{
	return flaeche_rechtwinkeliges_dreieck(a, b) * c;
}
