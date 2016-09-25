#include <stdio.h>

int funktion_verdopple(int i);
int funktion_potenziere(int i);

int main(int argc, char* argv[])
{
    int ergebnis;
    int array[10] = {1,2,3,4,5};
    int a = 5;
    int b = 8;
    int c = 3;

    ergebnis = array[1];
    printf("Ergebnis_1 ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:2\n\n");
    // Ergebnis_1 ist:2
    //		der Wert des Datenelements mit dem Index eins ist "2" (Index beginnt mit 0, nicht mit 1):
    //			array[0] = 1
    //			array[1] = 2
    //			array[2] = 3
    //			...

    ergebnis = array[9];
    printf("Ergebnis_2 ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:0\n\n");
    // Ergebnis_1 ist:0
    //		wenn ein Array bei der Definition:
    //			int array[10]
    //		auch initialisiert wird:
    //			 = {1,2,3,4,5}
    //		dann werden alle Datenelemente, für die man keinen Wert angibt,
    //		vom Compiler automatisch auf "0" gesetzt:
    //			array[5] = 0
    //			array[6] = 0
    //			array[7] = 0
    //			array[8] = 0
    //			array[9] = 0

    ergebnis = array[0];
    printf("Ergebnis_3 ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:1\n\n");
    // Ergebnis_1 ist:1
    //		der Wert des Datenelements mit dem Index null ist "1"

    ergebnis = a == b;
    printf("Ergebnis_4 ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:0\n\n");
    // Ergebnis_1 ist:0
    //		Relationsoperatoren (==, !=, <, >=, etc.) werden vor Zuweisungsoperatoren
    //		ausgewertet; als erstes wird also die Relation "a == b" ausgewertet: sie ist 
    //		falsch und ergibt 0; dann wird 0 der Variablen ergebnis zugewiesen

    ergebnis = a = b;
    printf("Ergebnis_5a ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:8\n\n");
    // Ergebnis_1 ist:8
    //		- Zuweisungen werden von rechts nach links ausgewertet: also wird als erstes
    //		der Variablen "a" der Wert von "b", also "8", zugewiesen
    //		- als zweites wird der Variablen "ergebnis" der Wert des Ausdrucks "a = b" zugewiesen
    //		- der Wert des Ausdrucks "a = b" ist der Wert von "a" (was auch der Wert von "b" ist), also wieder "8"
    //		http://stackoverflow.com/questions/16567622/what-is-the-result-of-an-assignment-expression-in-c
    printf("Ergebnis_5b ist:%d\n", a);
    printf("Ergebnis_1 ist:8\n\n");
    // Ergebnis_1 ist:8
    //		siehe darüber

    ergebnis = 25 + 8 * 25 || 8 > 6 && 12 < 20;
    printf("Ergebnis_6 ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:1\n\n");
    // Ergebnis_1 ist:1
    //		von allen Operatoren, die vorkommen, hat * den höchsten Rang, also:
    //			25 + (8 * 25) || 8 > 6 && 12 < 20
    //			25 + 200 || 8 > 6 && 12 < 20
    //		dann kommt +
    //			225 || 8 > 6 && 12 < 20
    //		dann < und >
    //			225 || 1 && 1
    //		dann &&
    //			225 || 1	Anmerkung: es wird vom Computer nur 225 ausgewertet; da das schon "wahr" ergibt, kann das Oder-Statement 
    //					gar nicht mehr falsch werden; der Wert "1" wird deswegen gar nicht mehr ausgewertet (S. 10)
    //		dann ||
    //			1

    ergebnis = (a = !funktion_verdopple(c)) && (b = funktion_potenziere(c));
    printf("Ergebnis_7a ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:0\n\n");
    // Ergebnis_1 ist:0
    //		der Operator für Funktionsaufrufe: () wird laut Rangtabelle als erstes
    //		ausgewertet; wenn mehrere vorkommen laut Tabelle von links nach rechts,
    //		also wird als erstes ausgewertet:
    //			funktion_verdopple(c)		-> ergibt 6
    //		dann:
    //			funktion_potenziere(c)		-> ergibt 9
    //		das ergibt:
    //			ergebnis = (a = !6) && (b = 9);
    //		als nächstes wird die Negation ! ausgewertet: alle Werte außer der Wert "0"
    //		sind wahr -> also ist die Negation von "6" falsch (und "falsch" ist in C dasselbe wie "0"):
    //			ergebnis = (a = 0) && (b = 9);
    //		als nächstes käme &&, wegen den Klammern werden aber zuerst die beiden
    //		Zuweisungen ausgewertet: wie im Link oben steht, ergibt die Auswertung einer
    //		Zuweisung den neuen Wert, der der Variablen zugewiesen worden ist:
    //			ergebnis = 0 && 9;	Anmerkung: es wird wieder nur der linke Wert "0" ausgewertet

    printf("Ergebnis_7b ist:%d\n", a);
    printf("Ergebnis_1 ist:0\n\n");
    // Ergebnis_1 ist:0
    //		ist immer noch null..., siehe darüber
    printf("Ergebnis_7c ist:%d\n", b);
    printf("Ergebnis_1 ist:8\n\n");
    // Ergebnis_1 ist:8
    //		ist immer noch neun..., siehe darüber

    ergebnis = (a = funktion_verdopple(c)) && (b = funktion_potenziere(c));
    printf("Ergebnis_8a ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:1\n\n");
    // Ergebnis_1 ist:1
    //		genau wie darüber, nur dass "6" nicht negiert wird
    printf("Ergebnis_8b ist:%d\n", a);
    printf("Ergebnis_1 ist:6\n\n");
    // Ergebnis_1 ist:6
    printf("Ergebnis_8c ist:%d\n", b);
    printf("Ergebnis_1 ist:8\n\n");
    // Ergebnis_1 ist:8

    ergebnis = 1 + 3 * 2;
    printf("Ergebnis_9 ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:7\n\n");
    // Ergebnis_1 ist:7
    //		Punkt vor Strich

    ergebnis = (1 + 3) * 2;
    printf("Ergebnis_10 ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:8\n\n");
    // Ergebnis_1 ist:8

    ergebnis = 5 - 2 - 3;
    printf("Ergebnis_11 ist:%d\n", ergebnis);
    printf("Ergebnis_1 ist:0\n\n");
    // Ergebnis_1 ist:0
    //		laut Rangtabelle von links nach rechts

    ergebnis = 5 - -(2 - 3);
    printf("Ergebnis_12 ist:%d\n", ergebnis); 
    printf("Ergebnis_1 ist:4\n\n");
    // Ergebnis_1 ist:4
    //		zuerst Klammer:
    //			5 - -(-1)
    //		dann unäres Minus:
    //			5 - (-(-1))
    //		ergibt:
    //			5 - 1

    return 0;
}

int funktion_verdopple(int i)
{
    return 2 * i;
}
int funktion_potenziere(int i)
{
    return i*i;
}
