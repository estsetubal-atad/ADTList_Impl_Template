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
	ListElem* elements;
	int size; 
	int capacity;
} ListImpl;


static bool ensureCapacity(PtList list) {
	if (list->size == list->capacity) {
		int newCapacity = list->capacity * 2;
		ListElem* newArray = (ListElem*) realloc( list->elements, 
								newCapacity * sizeof(ListElem) );
		
		if(newArray == NULL) return false;

		list->elements = newArray;
		list->capacity = newCapacity;
	}
	
	return true;
}

PtList listCreate() {
	PtList list = (PtList)malloc(sizeof(ListImpl));
	if (list == NULL) return NULL;

	list->elements = (ListElem*)calloc(INITIAL_CAPACITY,
										sizeof(ListElem));

	if (list->elements == NULL) {
		free(list);
		return NULL;	
	}

	list->size = 0;
	list->capacity = INITIAL_CAPACITY;

	return list;
}

int listDestroy(PtList *ptList) {
	PtList list = *ptList;
	if (list == NULL) return LIST_NULL;

	free(list->elements);
	free(list);

	*ptList = NULL;

	return LIST_OK;
}

int listAdd(PtList list, int rank, ListElem elem) {
	if (list == NULL) return LIST_NULL;

	/* TODO: validations and implementation */

	return LIST_OK;
}

int listRemove(PtList list, int rank, ListElem *ptElem) {
	if (list == NULL) return LIST_NULL;

	/* TODO: validations and implementation */

	return LIST_OK;
}

int listGet(PtList list, int rank, ListElem *ptElem) {
	if (list == NULL) return LIST_NULL;
	
	/* TODO: validations and implementation */

	return LIST_OK;
}

int listSet(PtList list, int rank, ListElem elem, ListElem *ptOldElem) {
	if (list == NULL) return LIST_NULL;
	
	/* TODO: validations and implementation */

	return LIST_OK;
}

int listSize(PtList list, int *ptSize) {
	if (list == NULL) return LIST_NULL;

	*ptSize = list->size;

	return LIST_OK;
}

bool listIsEmpty(PtList list) {
	if (list == NULL) return 1;

	return (list->size == 0);
}

int listClear(PtList list) {
	if (list == NULL) return LIST_NULL;

	list->size = 0;

	/* TODO: Decrease allocated array if too large */

	return LIST_OK;
}
void listPrint(PtList list) {
	if (list == NULL) {
		printf("(List NULL)\n");
	}
	else if (list->size == 0) {
		printf("(List EMPTY)\n");
	}
	else {
		printf("List contents (by rank): \n");
		for(int rank = 0; rank < list->size; rank++) {
			printf("Rank %d: ", rank);
			listElemPrint(list->elements[rank]);
			printf("\n");
		}
	}
	printf("\n");
}