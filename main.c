#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

#define STRESS_TEST_SIZE 100000

void populateSequence(PtList list, int n); /* populates with values [0, n[ */
bool testSequence(PtList list);
void shuffle(PtList list); /* randomly shuffle elements */

void testRankBasedAccess(PtList list);
void stressTest(PtList list);

int main(int argc, char** argv) {
	PtList list = listCreate();
	
	/* Check the access policy is respected */
	testRankBasedAccess(list);

	/* Check runtime for inserting and shuffling elements */
	stressTest(list);
	
	listDestroy(&list);

	return (EXIT_SUCCESS);
}

void testRankBasedAccess(PtList list) {
	listClear(list); //ensure empty

	
	populateSequence(list, 10);
	printf("\n--- Initial list ---\n");
	listPrint(list);

	printf("Testing sequence...\n");
	bool test = testSequence(list);

	printf("Rank based access test = %s \n", (test ? "[OK]" : "[FAILED]") );	
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

void stressTest(PtList list) {
	listClear(list); //ensure empty

	printf("\n-- Stress test with %d elements --\n", STRESS_TEST_SIZE);

    clock_t start, end;
    double cpu_time_used;

    start = clock();

	populateSequence(list, STRESS_TEST_SIZE);

	/* Shuffle */
	shuffle(list);

	end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("\t-- Time taken: %lf seconds \n", cpu_time_used);
}

void populateSequence(PtList list, int n) {
	/* Populate with n values*/
	printf("Populating sequence with %d elements...", n);

	int errorCode = 0;
	for(int i=0; i < n; i++) {
		errorCode = listAdd(list, i, i); // put 0 at 0, 1 at 1, ...
		if(errorCode != LIST_OK) {
			printf("[Stopped at %d-th element, due to error]", (i+1));
			break;
		}
	}

	printf("\n");
}


void shuffle(PtList list) {
	printf("Shuffling sequence... ");
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
	printf("[DONE] \n");
}