#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#define STRESS_TEST_SIZE 100000

void populateSequence(PtList list, int maxValue); /* populates with [0, maxValue] */
bool testSequence(PtList list);
void shuffle(PtList list); /* randomly shuffle elements */

void testRankBasedAccess(PtList list);
void stressTest(PtList list);

int main(int argc, char** argv) {
	PtList list = listCreate();
	
	testRankBasedAccess(list);
	stressTest(list);
	
	listDestroy(&list);

	return (EXIT_SUCCESS);
}

void testRankBasedAccess(PtList list) {
	listClear(list); //ensure empty

	printf("Populating sequence 0 to 10...\n");
	populateSequence(list, 10);
	printf("\n--- Initial list ---\n");
	listPrint(list);

	printf("Testing sequence...\n");
	bool test = testSequence(list);

	printf("Rank based access test = %s \n", (test ? "OK" : "FAILED") );	
}

void stressTest(PtList list) {
	listClear(list); //ensure empty

	printf("\nStress testing with %d elements... \n", STRESS_TEST_SIZE);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

	populateSequence(list, STRESS_TEST_SIZE);

	/* Shuffle */
	shuffle(list);

	end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("-- Time taken: %lf seconds \n", cpu_time_used);
}

void populateSequence(PtList list, int maxValue) {
	/* Populate with values*/
	for(int i=0; i <= maxValue; i++) {
		listAdd(list, i, i); // put 0 at 0, 1 at 1, ...
	}
}

bool testSequence(PtList list) {
	int n;
	listSize(list, &n);
	int elem;
	for(int i=0; i < n; i++) {
		listGet(list, i, &elem);

		if(elem != i) return false;
	}

	return true;
}

void shuffle(PtList list) {
	srand(time(NULL));

	int n;
	listSize(list, &n);
	int elem1, elem2;	
	for(int i=0; i < n; i++) {
		int randIndex = rand() % n;
		
		listGet(list, randIndex, &elem1);
		listSet(list, i, elem1, &elem2);
		listSet(list, randIndex, elem2, &elem1);
	}
}