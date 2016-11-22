/* NOCH NICHT AUSPROBIERT OBS STIMMT */
/* Exercise 08_2   */

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>
#include <math.h>

int gleichung(double *a, double *b, double *c, double *x1, double *x2);
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
  
	if (gleichung(&a, &b, &c, &x1, &x2)) {
    printf("x1 = %f\nx2 = %f\n", x1, x2);
  }
  else {
    printf("Keine Loesung.\n");
  }
}

int gleichung(double *a, double *b, double *c, double *x1, double *x2)
{
  double helper1 = b / (2 * a);
  double helper2 = helper1 * helper1 - c / a;
  
  if (helper2 < 0) {
    return 0;
  }
  else {
    *x1 = -helper1 + sqrt(helper2);
    *x2 = -helper1 - sqrt(helper2); 
  }
}
