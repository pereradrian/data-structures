#include "set.h"

int main() {

	Set * set =NULL

	/*Empty set tests  */
	printf("Empty set tests:\n");
	newSet(&set);
	printSet(set);
	freeSet(&set);

	printf("The End\n");
	fflush(stdout);

	return 0;	
}

/*
STATUS newSet(Set ** set);
void freeSet(Set ** set);
BOOLEAN isIn(const Set * set, const void * info, size_t infoSize);
size_t getSetSize(const Set * set);
STATUS addSet(Set * set, const void * info, size_t infoSize, void (*f_print)(FILE *, const void *));
STATUS removeSet(Set * set, const void * info, size_t infoSize);
STATUS getElementsSet(void ** infos, size_t ** infoSizes, const Set * set);
void printSet(FILE *fp, const Set * set);
*/
/* Operations with sets */
/*
BOOLEAN setsEqual(const Set * op1, const Set * op2);
STATUS setUnion(Set ** detination, const Set * op1, const Set * op2);
STATUS setIntersection(Set ** detination, const Set * op1, const Set * op2);
*/
/** Auxiliary functions **/
/*
STATUS newSetElement(SetElement ** setElement,const  void * info, size_t infoSize, void (*f_print)(FILE *, const void *));
void freeSetElement(SetElement ** setElement);
int compareInfoElement(const SetElement * setElement, const void * info, size_t infoSize);
BOOLEAN elementsEqual(const SetElement * setElement1, const SetElement * setElement2);
void printSetElement(FILE *fp, const SetElement * setElement);
*/

