/* Exercise 03_2 */

/*
	Punkte: 12

	Aufgabe:
	
	Implementieren Sie ein Programm, das den Kapitalwert berechnet. Erfassen Sie die
	entsprechenden Parameter in der main-Funktion und implementieren Sie beide Formeln
	in einer eigenen Funktion und geben in der Funktion das Ergebnis direkt aus.

	Anmerkung: Bei der Erfassung des Rückflusses können Sie immer von einem konstanten
	Rückfluss ausgehen. = Rt ist immer ein Wert über die gesamte Zeitdauer!

	Der Kapitalwert (englisch: net present value[NPV] = Net-Present-Value oder
	Nettogegenwartswert[seltener:NGW]; auch: Barwert[aller Zahlungen]) ist eine
	betriebswirtschaftliche Kennziffer der dynamischen Investitionsrechnung. Durch
	Abzinsung auf den Beginn der Investition werden Zahlungen, die zu beliebigen
	Zeitpunkten anfallen, vergleichbar gemacht.

	Der Kapitalwert einer Investition ist die Summe der Barwerte aller durch diese
	Investition verursachten Zahlungen (Ein- und Auszahlungen). Voraussetzung ist jedoch,
	dass zwischenzeitliche kumulierte Überschüsse sofort zum Kalkulationszinssatz angelegt
	werden.

	Der Kapitalwert ist abhängig vom Kalkulationszinssatz und basiert auf der Annahme des
	vollkommenen Kapitalmarktes.

	Allgemeine Implementierung:

	Der Kapitalwert berechnet sich, wie folgt:
	
	C0 = -I + [Summenzeichen mit oben T und unten t=1] (Rt) * (1+i) ^ -t + L * (1+i) ^ -T

	- C0: Kapitalwert
	- I: Investition
	- T: Betrachtungsdauer (in Perioden)
	- Rt: Rückfluss (Cashflow) in Periode t, wobei 
		Rt = EWt - At (Ertragswert - Anschaffungsausgaben) darstellt.
	- L: Liquidationserlös / Resterlös
	- i: Kalkulationszinssatz

	Spezielle Implementierung:

	Fallen während der Nutzungsdauer pro Periode stets gleiche Zahlungen an,
	kann der Kapitalwert auch einfach mithilfe der Rentenbarwertformel ermittelt werden 
	
	C0 = -I + Rt * ((1+i) ^ T - 1) / ((1+i) ^ T * i ) + L * (1+i) ^ -T

	- RT: Rückfluss pro Periode

	Für das Potenzieren ist eine entsprechende Bibliotheksfunktion auszuwählen - Siehe
	Referenzkarte!

	Quelle: http ://de.wikipedia.org/wiki/Kapitalwert
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>
#include <math.h>

void kapitalwert_allgemein(int t, double inv, double rt, double i, double l);
void kapitalwert_speziell(int t, double inv, double rt, double i, double l);

int main(int argc, char* argv[])
{
	int
		t = 0;
	double
		inv = 0.0,
		ewt = 0.0,
		at = 0.0,
		i = 0.0,
		l = 0.0,
		rt = 0.0;

	printf("Investition: ");
	scanf("%lf", &inv);
	printf("Betrachtungsdauer in Perioden: ");
	scanf("%d", &t);
	printf("Ertragswert (gilt fuer alle Perioden): ");
	scanf("%lf", &ewt);
	printf("Anschaffungsausgaben (gilt fuer alle Perioden): ");
	scanf("%lf", &at);
	printf("Kalkulationszinssatz in Prozent: ");
	scanf("%lf", &i);
	printf("Liquidationserloes: ");
	scanf("%lf", &l);

	i = i / 100;
	rt = ewt - at;

	kapitalwert_allgemein(t, inv, rt, i, l);
	kapitalwert_speziell(t, inv, rt, i, l);

	return 0;
}

void kapitalwert_allgemein(int t, double inv, double rt, double i, double l)
{
	double helper = 0.0;

	for (int x = 1; x <= t; x++) {
		helper = helper + rt * pow(1 + i, -x);
	}

	printf(
		"\nKapitalwert allgemeine Implementierung: %f\n",
		-inv + helper + l * pow(1 + i, -t)
	);
}

void kapitalwert_speziell(int t, double inv, double rt, double i, double l)
{
	printf(
		"Kapitalwert spezielle Implementierung: %f\n\n",
		-inv + rt * (pow(1 + i, t) - 1) / (pow(1 + i, t) * i) + l * pow(1 + i, -t)
	);
}
