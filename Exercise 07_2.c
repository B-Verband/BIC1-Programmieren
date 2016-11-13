/* Exercise 07_2 */

/*
	Punkte: 12

	Schreiben sie eine Funktion void reverse(char s[]) die den angegebenen String s umdreht.

	Beispielanwendung:
	int main(int argc, char * argv[])
	{
		char text[] = "exercise";
		printf("%s\n", text);
		reverse(text);
		printf("%s\n", text);
		return 0;
	}

	Ausgabe:
		exercise
		esicrexe

	Erklärung:
	Arrays werden in C ausschließlich by pointer übergeben deshalb entfällt der Adress-
	Operator beim Aufruf reverse(text). Durch die Übergabe by pointer zeigt s in der Funktion 
	reverse(char s[]) nun ebenfalls auf den String "exercise". Analog zum entfallenen Adress-
	Operator beim Funktionsaufruf entfällt auch die Dereferenzierung beim Zugriff. Es kann 
	einfach mit s[i] auf das i-te Element des Arrays zugegriffen werden.
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS

/* Programmcode hier einfügen */
#include <stdio.h>
#include <math.h>

void reverse(char s[]);

int main(int argc, char* argv[])
{
	char text[] = "exercise";
	printf("%s\n", text);
	reverse(text);
	printf("%s\n", text);
	return 0;
}

void reverse(char string[])
{
	int length = strlen(string);
	char helper[100];

	int i = 0;
	for (i = 1; i <= length; i++) {
		helper[i - 1] = string[length - i];
	}
	helper[i - 1] = '\0';
	 
	strncpy(string, helper, length);
}
