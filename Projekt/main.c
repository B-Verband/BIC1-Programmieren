/*
	Es sollen die Informationen Matrikelnummer (Ganze Zahl) und Nachname (char array)
	gespeichert werden, wobei über den Schlüssel Matrikelnummer ein rascher Zugriff
	erfolgen soll. Es kann immer nur eine Studentin bzw. Student mit derselben
	Matrikelnummer gespeichert werden.

	Die Aufgabenstellung ist mittels einer Hash-Tabelle mit äußerer Verkettung zu
	lösen, d.h. alle Elemente die denselben Index belegen (Kollisionen) werden an
	diesem Index mittels einer einfach verketteten Liste abgespeichert. Zur Lösung
	des Problems führen Sie auch ein Literaturstudium durch. Es reicht aus eine Hash-
	Tabelle mit fixer Größe zu implementieren, überlegen Sie sich aber eine sinnvolle
	Größe die ausgehend von der zu erwartenden Anzahl von Datensätzen relativ wenige
	Kollisionen hervorrufen wird. Dokumentieren Sie auch Ihre Überlegungen dazu.
	Mindestens eine Funktion ist mithilfe der Rekursion zu lösen.

	Folgende Funktionen sind zu implementieren:
		- Eintragen von Datensätzen (28 Punkte)
			o Daten erfassen (scanf) und in die Datenstruktur einfügen
		- Löschen von Datensätzen (28 Punkte)
			o Matrikelnummer erfassen und die Daten aus der Datenstruktur löschen
		- Suchen von Datensätzen (28 Punkte)
			o Matrikelnummer erfassen und den Namen ausgeben.

	Bauen Sie ein Menüsystem, um die einzelnen Programmfunktionen auszuführen. (6 Punkte)

	Datenstruktur: (10 Punkte)
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include "projekt.h"

int main(void)
{
	node_t *hashtable[HASHTABLE_MAX];

	initHashtable(hashtable, HASHTABLE_MAX);
	fillHashtable(hashtable, HASHTABLE_MAX);
	menu(hashtable, HASHTABLE_MAX);
	destroy(hashtable, HASHTABLE_MAX);

	return 0;
}
