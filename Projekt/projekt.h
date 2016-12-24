#ifndef PROJEKT_H
#define PROJEKT_H

	/* unsafe warning wird ausgeblendet */
	#define _CRT_SECURE_NO_WARNINGS

	/* Defines */
	#define HASHTABLE_MAX 50
	#define NACHNAME_MAX 13

	/* Structs und Enums */
	struct student {
		unsigned int matrikelnummer;
		char nachname[NACHNAME_MAX];
	};
	struct node {
		struct student data;
		struct node_t *next;
	};
	enum status { MALLOC_ERROR, FOUND, NOT_FOUND, INSERTED, ALREADY_EXISTS, DELETED };

	/* Typedefs */
	typedef struct node node_t;
	typedef enum status status_t;

	/* Funktionen */
	void initHashtable(node_t *hashtable[], int size);
	void fillHashtable(node_t *hashtable[], int size);
	void print(node_t *hashtable[], int size);
	void printList(node_t *node);
	void menu(node_t *hashtable[], int size);
	void destroy(node_t *hashtable[], int size);
	void destroyList(node_t *hashtable[]);
	int hash(int size, unsigned int key);
	status_t insert(node_t *hashtable[], int size, unsigned int matrikelnummer, char *nachname);
	status_t insertToList(node_t *node, node_t *new);
	status_t delete(node_t *hashtable[], int size, unsigned int matrikelnummer);
	status_t deleteFromList(node_t **previous, node_t *node, unsigned int matrikelnummer);
	status_t search(node_t *hashtable[], int size, unsigned int matrikelnummer, char *nachname);
	status_t searchInList(node_t *node, unsigned int matrikelnummer, char *nachname);

#endif
