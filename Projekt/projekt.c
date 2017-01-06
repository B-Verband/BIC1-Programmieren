#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projekt.h"

void initHashtable(node_t *hashtable[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		hashtable[i] = NULL;
	}
}

void fillHashtable(node_t *hashtable[], int size)
{
	insert(hashtable, size, 7, "Ronaldo");
	insert(hashtable, size, 10, "Messi");
	insert(hashtable, size, 9, "Ibrahimovic");
	insert(hashtable, size, 8, "Iniesta");
	insert(hashtable, size, 1, "Higuita");
}

void menu(node_t *hashtable[], int size)
{
	int option = 0;
	unsigned int matrikelnummer = 0;
	char nachname[NACHNAME_MAX];
	status_t status;

	while (option < 1 || option > 5)
	{
		printf("1...Neue StudentIn hinzufuegen\n");
		printf("2...SudentIn loeschen\n");
		printf("3...StudentIn suchen\n");
		printf("4...Hashtabelle ausgeben\n");
		printf("5...Programm beenden\n");
		printf("Option: ");
		scanf("%d", &option);
		printf("\n");
		switch (option) {
		case 1:
			/* Eingabe */
			printf("Neue Matrikelnummer eingeben: "); scanf("%d", &matrikelnummer);
			printf("Namen eingeben: "); scanf("%s", nachname);
			/* Hinzufügen */
			status = insert(hashtable, size, matrikelnummer, nachname);
			/* Ausgabe */
			if (status == INSERTED)
				printf("StudentIn eingefuegt.\n");
			else if (status == ALREADY_EXISTS)
				printf("Matrikelnummer existiert bereits.\n");
			break;
		case 2:
			/* Eingabe */
			printf("Zu loeschende Matrikelnummer eingeben: "); scanf("%d", &matrikelnummer);
			/* Löschen */
			status = delete(hashtable, size, matrikelnummer);
			/* Ausgabe */
			if (status == DELETED)
				printf("StudentIn geloescht.\n");
			else if (status == NOT_FOUND)
				printf("Matrikelnummer existiert nicht.\n");
			break;
		case 3:
			/* Eingabe */
			printf("Gesuchte Matrikelnummer eingeben: "); scanf("%d", &matrikelnummer);
			/* Suchen */
			status = search(hashtable, size, matrikelnummer, nachname);
			/* Ausgabe */
			if (status == FOUND)
				printf("StudentIn: %s\n", nachname);
			else if (status == NOT_FOUND)
				printf("Matrikelnummer existiert nicht.\n");
			break;
		case 4:
			print(hashtable, size);
			break;
		case 5:
			break;
		default:
			printf("Falsche Eingabe, eine der Optionen waehlen. \n");
			break;
		}
		printf("\n");
		if (option != 5) option = 0;
	}
}

/* http://stackoverflow.com/questions/664014/what-integer-hash-function-are-good-that-accepts-an-integer-hash-key */
int hash(int size, unsigned int key)
{
	key = ((key >> 16) ^ key) * 0x45d9f3b;
	key = ((key >> 16) ^ key) * 0x45d9f3b;
	key = (key >> 16) ^ key;

	return key % size;
}

node_t *createNode(int matrikelnummer, char *nachname)
{
	node_t *new = malloc(sizeof(node_t));
	if (new == NULL) return MALLOC_ERROR;

	new->data.matrikelnummer = matrikelnummer;
	strcpy(new->data.nachname, nachname);
	new->next = NULL;

	return new;
}

status_t insert(node_t *hashtable[], int size, unsigned int matrikelnummer, char *nachname)
{
	int index = hash(size, matrikelnummer);
	node_t *new = createNode(matrikelnummer, nachname);

	if (hashtable[index] == NULL)
	{
		hashtable[index] = new;
		return INSERTED;
	}
	else
	{
		return insertToList(hashtable[index], new);
	}
}

status_t insertToList(node_t *node, node_t *new)
{
	if (node->data.matrikelnummer == new->data.matrikelnummer)
	{
		free(new);
		return ALREADY_EXISTS;
	}

	if (node->next == NULL)
	{
		node->next = new;
		return INSERTED;
	}
	else
	{
		return insertToList(node->next, new);
	}
}

status_t delete(node_t *hashtable[], int size, unsigned int matrikelnummer)
{
	int index = hash(size, matrikelnummer);
	node_t **previous = NULL;

	if (hashtable[index] == NULL)
	{
		return NOT_FOUND;
	}
	else
	{
		previous = &hashtable[index];
		return deleteFromList(previous, hashtable[index], matrikelnummer);
	}
}

status_t deleteFromList(node_t **previous, node_t *node, unsigned int matrikelnummer)
{
	if (node->data.matrikelnummer == matrikelnummer)
	{
		if (node->next == NULL) {
			*previous = NULL;
		}
		else
		{
			*previous = node->next;
		}
		free(node);
		return DELETED;
	}
	else
	{
		if (node->next == NULL)
		{
			return NOT_FOUND;
		}
		else
		{
			previous = &(node->next);
			return deleteFromList(previous, node->next, matrikelnummer);
		}
	}
}

status_t search(node_t *hashtable[], int size, unsigned int matrikelnummer, char *nachname)
{
	int index = hash(size, matrikelnummer);

	return searchInList(hashtable[index], matrikelnummer, nachname);
}

status_t searchInList(node_t *node, unsigned int matrikelnummer, char *nachname)
{
	if (node == NULL)
	{
		return NOT_FOUND;
	}
	else if (node->data.matrikelnummer == matrikelnummer)
	{
		strcpy(nachname, node->data.nachname);
		return FOUND;
	}
	return searchInList(node->next, matrikelnummer, nachname);
}

void print(node_t *hashtable[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		printf("%d (%p zeigt auf %p)\n", i, &hashtable[i], hashtable[i]);
		printList(hashtable[i]);
	}
}

void printList(node_t *node)
{
	if (node != NULL)
	{
		printf(
			"   Name: %13s \t\tMatr.-Nr.: %4d \t\t(next: %p)\n",
			node->data.nachname,
			node->data.matrikelnummer,
			node->next
		);
		printList(node->next);
	}
}

void destroy(node_t *hashtable[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		destroyList(hashtable[i]);
	}
}

void destroyList(node_t *node)
{
	if (node != NULL)
	{
		destroyList(node->next);
		free(node);
	}
}
