/* Exercise 08_1 */

/*
	Punkte: 12
	
	Aufgabe Teil 1:
		Entwickeln Sie ein Modul mit Headerfile und Sourcefile, das folgende globale Eigenschaften
		(= Gültigkeitsbereich: gesamtes Programm, Sichtbarkeit: im beliebigen Quelltext) aufweist:
			- Funktion, die das Volumen eines Quaders berechnet und zurückgibt. (V = a * b * c)
				Verwenden Sie die interne Funktion Fläche!
			- Funktion, die das Volumen eines Würfels berechnet und zurückgibt. (V = a * a * a)
				Verwenden Sie dazu die interne Funktion Fläche! 
			- Funktion, die die Oberfläche des Quaders berechnet und zurückgibt. (F = 2*(ab+bc+ca))
				Verwenden Sie zur Berechnung in der Funktion jedoch nicht direkt die Formel, sondern 
				implementieren Sie diese Formel als Makro und verwenden das Makro in der Funktion.
			- Stellen Sie die Zahl PI global zur Verfügung
		und folgende interne Funktion, die nur in diesem Modul verwendet werden kann 
		(= Gültigkeitsbereich der Funktion: gesamtes Programm, Sichtbarkeitsbereich der Funktion:
		im gleichen Quelltext/nur in diesem Modul) hat:
			- Interne Funktion, die die Fläche eines Rechtecks berechnet (A = a * b)
				Zählen Sie die Anzahl der Aufrufe mit und geben Sie bei jedem Aufruf aus, wie oft
				diese Funktion bereits aufgerufen wurde. Achtung keine globale Variable verwenden!
	Aufgabe Teil 2:
		Erstellen Sie ein sinnvolles und vollständiges Programm, welches alle Funktionen und Variablen
		(außer natürlich die Funktion Fläche) des Moduls im Hauptprogramm verwendet.

		(Um neue Files dem Projekt zuordnen zu können, müssen Sie wie folgt vorgehen:
			- Datei
			- Neues Element hinzufügen
				- Fügen Sie eine C++ Datei hinzu
				- Fügen Sie eine Headerdatei hinzu
		)
*/

/*************************************** aufrufend.c ***************************************/
/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>
#include "modul.h"

int main(int argc, char* argv[])
{
	double
		a = 3.0,
		b = 4.0,
		c = 5.0;

	printf("Volumen des Quaders: %f\n", quadervolumen(a, b, c));
	printf("Volumen des Wuerfels: %f\n", wuerfelvolumen(a));
	printf("Flaeche des Quaders: %f\n", quaderoberflaeche(a, b, c));
	printf("Pi: %f\n", PI);
}

/*************************************** modul.h ***************************************/
#ifndef MODUL_H
#define MODUL_H

extern const double PI;

double quadervolumen(double a, double b, double c);
double wuerfelvolumen(double a);
double quaderoberflaeche(double a, double b, double c);

#endif

/*************************************** modul.c ***************************************/
#include "modul.h"

#define QUADEROBERFLAECHE(a, b, c) (2*((a)*(b)+(b)*(c)+(c)*(a)))

const double PI = 3.14159;

static double rechteckflaeche(double a, double b)
{
	static int aufrufe = 0;
	printf("Die Funktion 'rechteckflaeche' wurde %d Mal aufgerufen.\n", ++aufrufe);
	return a * b;
}

double quadervolumen(double a, double b, double c)
{
	return rechteckflaeche(a, b) * c;
}

double wuerfelvolumen(double a)
{
	return rechteckflaeche(a, a) * a;
}

double quaderoberflaeche(double a, double b, double c)
{
	return QUADEROBERFLAECHE(a, b, c);
}
