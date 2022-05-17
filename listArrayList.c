/**
 * @file listArrayList.c
 * 
 * @brief Provides an implementation of the ADT List with an array list
 * as the underlying data structure.
 * 
 * @author Bruno Silva (brunomnsilva@gmail.com)
 * @bug No known bugs.
 */

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 20

typedef struct listImpl {
	// TODO
} ListImpl;


static bool ensureCapacity(PtList list) {
	
	// TODO

	return false;
}

PtList listCreate() {
	// TODO

	return NULL;
}

int listDestroy(PtList *ptList) {
	// TODO

	return LIST_OK;
}

int listAdd(PtList list, int rank, ListElem elem) {
	if (list == NULL) return LIST_NULL;

	// TODO

	return LIST_OK;
}

int listRemove(PtList list, int rank, ListElem *ptElem) {
	if (list == NULL) return LIST_NULL;

	// TODO

	return LIST_OK;
}

int listGet(PtList list, int rank, ListElem *ptElem) {
	if (list == NULL) return LIST_NULL;
	
	// TODO

	return LIST_OK;
}

int listSet(PtList list, int rank, ListElem elem, ListElem *ptOldElem) {
	if (list == NULL) return LIST_NULL;
	
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
		printf("(List NULL)\n");
	}
	else if (listIsEmpty(list)) {
		printf("(List EMPTY)\n");
	}
	else {
		printf("List contents (by rank): \n");
		// TODO
	}
	printf("\n");
}