/* Exercise 02_2 */

/* 
 *		Exercise 02_2 (Punkte: 12)
 *		In der main-Funktion werden vier reelle Zahlen (a, b, c, d) eingelesen. Implementieren Sie
 *		folgende Prüffunktionen und geben Sie das Ergebnis in der main-Funktion zurück.
 *
 *		Liste Prüffunktionen, die bei Erfolg 1 bei Misserfolg 0 zurückliefern. 
 *			- Prüfen Sie ob a kleiner b ist
 *			- Prüfen Sie ob a kleiner gleich b und ob b kleiner gleich c ist
 *			- Prüfen Sie ob a größer b und c größer d ist
 *			- Prüfen Sie ob a kleiner c oder b größer d ist
 *			- Prüfen Sie ob d ungleich 0 ist, wenn ungleich 0, dann 0 zurückgeben sonst 1.
 *
 *		Beispielfunktion ad 1. Prüffunktion
 *			int a_kleiner_b(double a, double b) {
 *				int ergebnis = 0;
 *				ergebnis = a < b;
 *				return ergebnis;
 *			}
 */

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>

int a_kleiner_b(double a, double b);
int a_kleinergleich_b_und_b_kleinergleich_c(double a, double b, double c);
int a_groesser_b_und_c_groesser_d(double a, double b, double c, double d);
int a_kleiner_c_oder_b_groesser_d(double a, double b, double c, double d);
int a_gleich_0(double a);

int main(int argc, char* argv[])
{
	double a, b, c, d;

	printf("reelle Zahl a: ");
	scanf("%lf", &a);

	printf("reelle Zahl b: ");
	scanf("%lf", &b);

	printf("reelle Zahl c: ");
	scanf("%lf", &c);

	printf("reelle Zahl d: ");
	scanf("%lf", &d);
	
	printf("\na < b = %d\n", a_kleiner_b(a, b));
	printf("a <= b && b <= c = %d\n", a_kleinergleich_b_und_b_kleinergleich_c(a, b, c));
	printf("a > b && c > d = %d\n", a_groesser_b_und_c_groesser_d(a, b, c, d));
	printf("a < c || b > d = %d\n", a_kleiner_c_oder_b_groesser_d(a, b, c, d));
	printf("d == 0 = %d\n\n", a_gleich_0(d));

	return 0;
}

int a_kleiner_b(double a, double b)
{
	return a < b;
}

int a_kleinergleich_b_und_b_kleinergleich_c(double a, double b, double c)
{
	return a <= b && b <= c;
}

int a_groesser_b_und_c_groesser_d(double a, double b, double c, double d)
{
	return a > b && c > d;
}

int a_kleiner_c_oder_b_groesser_d(double a, double b, double c, double d)
{
	return a < c || b > d;
}

int a_gleich_0(double a)
{
	return a == 0;
}
