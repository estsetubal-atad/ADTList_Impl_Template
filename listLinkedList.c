/**
 * @file listLinkedList.c
 * 
 * @brief Provides an implementation of the ADT List with a 
 * doubly-linked list with sentinels as the underlying 
 * data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node* PtNode;

typedef struct node {
	ListElem element;
	PtNode next, prev;
} Node;

typedef struct listImpl {
	PtNode header, trailer;
	int size;
} ListImpl;


static PtNode nodeAtRank(PtList list, int rank) {
	
	int currentRank = 0;
	PtNode currentNode = list->header->next;
	while (currentNode != NULL) { 

		if (currentRank == rank) return currentNode;

		currentRank++;
		currentNode = currentNode->next;
	}

	/* may be optimized if rank > size/2 by starting at trailer */

	return NULL;
}


PtList listCreate() {
		
	// TODO

	return NULL;
}

int listDestroy(PtList *ptList) {
	// TODO

	*ptList = NULL;

	return LIST_OK;
}

int listAdd(PtList list, int rank, ListElem elem) {
	if (list == NULL) return LIST_NULL;
	// TODO validate ranks

	// TODO

	return LIST_OK;
}

int listRemove(PtList list, int rank, ListElem *ptElem) {
	if (list == NULL) return LIST_NULL;
	// TODO validate empty and validate ranks

	// TODO

	return LIST_OK;
}

int listGet(PtList list, int rank, ListElem *ptElem) {
	if (list == NULL) return LIST_NULL;
	// TODO validate empty and validate ranks

	// TODO

	return LIST_OK;
}

int listSet(PtList list, int rank, ListElem elem, ListElem *ptOldElem) {
	if (list == NULL) return LIST_NULL;
	// TODO validate empty and validate ranks

	// TODO

	return LIST_OK;
}

int listSize(PtList list, int *ptSize) {
	if (list == NULL) return LIST_NULL;

	// TODO

	return LIST_OK;
}

bool listIsEmpty(PtList list) {
	if (list == NULL) return 1;

	return (true /* TODO */);
}

int listClear(PtList list) {
	if (list == NULL) return LIST_NULL;

	// TODO

	return LIST_OK;
}

void listPrint(PtList list) {
	if (list == NULL) {
		printf("(LIST NULL)\n");
	}
	else if (listIsEmpty(list)) {
		printf("(LIST EMPTY)\n");
	}
	else {
		printf("List contents (by rank): \n");
		// TODO
	}
	printf("\n");
}

