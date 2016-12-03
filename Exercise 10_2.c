/* Exercise 10_2 */

/*
	Punkte: 12

	Aufgabe:
	Ergänzen Sie die fehlenden Teile des vorgegebenen Programms. Schreiben sie eine Funktion
	int stringlength(char* s) welche die Länge eines Strings ermittelt (analog zur
	Bibliotheksfunktion strlen). Greifen sie dabei ausschließlich auf Pointerarithmetik zurück
	und verwenden sie nicht den []-Operator! Bei einem NULL-Argument soll als Ergebnis 0
	zurückgeliefert werden.

	Beachten Sie, dass im Sourcecode-Zip-File im Verzeichnis Exerciseder entsprechende Master
	gespeichert ist!
*/

/********************************* Master.c *********************************/
/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>
#include <string.h>
#include "test.h"

int stringlength(char* s);

int main(int argc, char* argv[])
{
	test("empty string", stringlength("") == 0);
	test("'A'", stringlength("A") == 1);
	test("'012'", stringlength("012") == 3);
	test("'Das ist ein Test!'", stringlength("Das ist ein Test!") == 17);
	test("NULL", stringlength(NULL) == 0);

	return 0;
}

int stringlength(char* s)
{
	unsigned int laenge = 0;

	/* s ist Nullpointer */
	if (s == NULL) return 0;
	/* s ist String */
	while (*s != '\0') {
		laenge++;
		s++;
	}
	return laenge;
}

/********************************* test.h *********************************/
#ifndef TEST_H
#define TEST_H

void test(const char * message, int assertion);

#endif

/********************************* test.c *********************************/
#include <stdio.h>
#include "test.h"

void test(const char * message, int assertion)
{
	printf("%s : %s\n", assertion ? "OK    " : "FAILED", message);
}
