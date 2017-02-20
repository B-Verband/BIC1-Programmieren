/* Exercise 09_2 */

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>
#include <math.h>

typedef struct v3d {
	double x;
	double y;
	double z;
} v3d;

v3d add(v3d a, v3d b);
v3d subtract(v3d a, v3d b);
double length(v3d v);
double dot(v3d a, v3d b);

int main(int argc, char* argv[])
{
	v3d a = { 2.2, 3.3, 4.4 };
	v3d b = { 1.1, 2.2, 3.3 };
	v3d summe = add(a, b);
	v3d differenz = subtract(a, b);

	printf("        %f\na =     %f\n        %f\n\n", a.x, a.y, a.z);
	printf("        %f\nb =     %f\n        %f\n\n", b.x, b.y, b.z);

	printf("        %f\na + b = %f\n        %f\n\n", summe.x, summe.y, summe.z);

	printf("        %f\na - b = %f\n        %f\n\n", differenz.x, differenz.y, differenz.z);

	printf("|a| = %f\n\n", length(a));
	printf("|b| = %f\n\n", length(b));

	printf("a * b = %f\n\n", dot(a, b));
}

v3d add(v3d a, v3d b)
{
	v3d ergebnis;
	ergebnis.x = a.x + b.x;
	ergebnis.y = a.y + b.y;
	ergebnis.z = a.z + b.z;
	return ergebnis;
}
v3d subtract(v3d a, v3d b)
{
	v3d ergebnis;
	ergebnis.x = a.x - b.x;
	ergebnis.y = a.y - b.y;
	ergebnis.z = a.z - b.z;
	return ergebnis;
}
double length(v3d v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}
double dot(v3d a, v3d b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}
