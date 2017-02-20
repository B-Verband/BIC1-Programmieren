/* Exercise 10_1 */

/*
	unter Windows ausführen mit cmd: ins Projektverzeichnis wechseln, dort
 		>cd Debug
 		>Master.exe 4
*/

/* unsafe warning wird ausgeblendet */
#define _CRT_SECURE_NO_WARNINGS 

/* Programmcode hier einfügen */
#include <stdio.h>

int main(int argc, char* argv[])
{
	int summe = 0;
	
	if (argc == 2) {
		int i = 0;
		for (i = 1; i <= atoi(argv[1]); i++) summe += i;
		printf("Summe: %d\n", summe);
	}
	else {
		printf("Fehler\n");
	}
	return 0;
}
