/* Exercise 06_1 */

/*
    Punkte: 12
    Schreiben Sie ein Programm, welches die Einkommensteuer berechnet. In der main-
    Funktion wird das Bruttoeinkommen erfasst und eine Funktion berechnet die
    Einkommensteuer. Das Ergebnis der Funktion wird als return Wert der main-
    Funktion zurückgeliefert und dort ausgegeben.
    
    bis	11.000,00     0
    bis 25.000,00     (Einkommen - 11.000,0) x 5.110 / 14.000
    bis 60.000,00     (((Einkommen - 25.000,0) x 15.125) / 35.000) + 5.110,0
    über 60.000,00    ((Einkommen - 60.000,0) x 0,5) + 20.235,0
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>

double einkommenssteuer(double jahresbruttoeinkommen);

int main(int argc, char* argv[])
{
    double jahresbruttoeinkommen = 0.0;

    printf("Jahresbruttoeinkommen in Euro: ");
    scanf("%lf", &jahresbruttoeinkommen);

    printf("Einkommenssteuer: %f Euro\n", einkommenssteuer(jahresbruttoeinkommen));
}

double einkommenssteuer(double jahresbruttoeinkommen)
{
    if (jahresbruttoeinkommen <= 11000)
    {
        return 0;
    }
    else if (jahresbruttoeinkommen <= 25000)
    {
        return ((jahresbruttoeinkommen - 11000) * 5110) / 14000;
    }
    else if (jahresbruttoeinkommen <= 60000)
    {
        return (((jahresbruttoeinkommen - 25000) * 15125) / 35000) + 5110;
    }
    else
    {
        return ((jahresbruttoeinkommen - 60000) * 0.5) + 20235;
    }
}
