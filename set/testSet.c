#include "set.h"

void printInt(FILE *fp, const void* integer);

int main() {

	Set * set =NULL;
	Set * set2 =NULL;
	Set * set3 =NULL;
	int value1 =1;
	int value2 =2;
	int value3 =3;
	int value4 =4;
	int value5 =5;
	int value6 =6;
	int value7 =7;
	int value8 =8;
	int value9 =9;
	int * arrayIntegers =NULL;
	size_t * arraySizes =NULL;

	/*Empty set tests  */
	printf("Empty set tests:\n");
	newSet(&set);
	printSet(stdout,set);
	freeSet(&set);

	/* General test for int types only */
	printf("Integer set tests:\n");
	newSet(&set);

	/* Insertion */
	printf("Empty set size:%ld\n",getSizeSet(set));
	addSet(set,(void *)&value1,sizeof(int),&printInt);
	addSet(set,(void *)&value2,sizeof(int),&printInt);
	addSet(set,(void *)&value3,sizeof(int),&printInt);
	addSet(set,(void *)&value4,sizeof(int),&printInt);
	printSet(stdout,set);

	/* Avoiding repetitions */
	printf("New set size set size:%ld\n",getSizeSet(set));
	printf("Adding repeated elements:\n");
	printSet(stdout,set);
	addSet(set,(void *)&value1,sizeof(int),&printInt);
	printSet(stdout,set);

	/* Deletion */
	printf("Deleting element 1:\n");
	printSet(stdout,set);
	removeSet(set, (void *)&value1, sizeof(int));
	printSet(stdout,set);

	printf("Deleting element 1 again:\n");
	printSet(stdout,set);
	removeSet(set, (void *)&value1, sizeof(int));
	printSet(stdout,set);

	printf("Deleting element 2:\n");
	printSet(stdout,set);
	removeSet(set, (void *)&value2, sizeof(int));
	printSet(stdout,set);

	printf("Deleting element 3:\n");
	printSet(stdout,set);
	removeSet(set, (void *)&value3, sizeof(int));
	printSet(stdout,set);

	printf("Deleting element 4:\n");
	printSet(stdout,set);
	removeSet(set, (void *)&value4, sizeof(int));
	printSet(stdout,set);

	printf("Deleting element 1 again:\n");
	printSet(stdout,set);
	removeSet(set, (void *)&value4, sizeof(int));
	printSet(stdout,set);

	/* Copiying set */
	printf("Copying a set:\n");
	addSet(set,(void *)&value1,sizeof(int),&printInt);
	addSet(set,(void *)&value2,sizeof(int),&printInt);
	addSet(set,(void *)&value3,sizeof(int),&printInt);
	addSet(set,(void *)&value4,sizeof(int),&printInt);
	printSet(stdout,set);
	copySet(&set2,set);
	printSet(stdout,set2);
	
	freeSet(&set);	
	freeSet(&set2);

	/* Union set */
	printf("Union of sets:\n");
	newSet(&set);
	newSet(&set2);
	addSet(set,(void *)&value1,sizeof(int),&printInt);
	addSet(set2,(void *)&value2,sizeof(int),&printInt);
	addSet(set,(void *)&value3,sizeof(int),&printInt);
	addSet(set2,(void *)&value4,sizeof(int),&printInt);
	addSet(set,(void *)&value5,sizeof(int),&printInt);
	addSet(set2,(void *)&value6,sizeof(int),&printInt);
	addSet(set,(void *)&value7,sizeof(int),&printInt);
	addSet(set2,(void *)&value8,sizeof(int),&printInt);
	addSet(set,(void *)&value9,sizeof(int),&printInt);

	printf("Set 1:\n");
	printSet(stdout,set);
	printf("Set 2:\n");
	printSet(stdout,set2);
	unionSet(&set3,set,set2);
	printf("Result:\n");
	printSet(stdout,set3);
	
	freeSet(&set);	
	freeSet(&set2);
	freeSet(&set3);

	/* Intersection set */
	printf("Intersection of sets:\n");
	newSet(&set);
	newSet(&set2);
	addSet(set,(void *)&value1,sizeof(int),&printInt);
	addSet(set2,(void *)&value2,sizeof(int),&printInt);
	addSet(set,(void *)&value3,sizeof(int),&printInt);
	addSet(set2,(void *)&value4,sizeof(int),&printInt);
	addSet(set,(void *)&value5,sizeof(int),&printInt);
	addSet(set2,(void *)&value6,sizeof(int),&printInt);
	addSet(set,(void *)&value7,sizeof(int),&printInt);
	addSet(set2,(void *)&value8,sizeof(int),&printInt);
	addSet(set,(void *)&value9,sizeof(int),&printInt);

	printf("Set 1:\n");
	printSet(stdout,set);
	printf("Set 2:\n");
	printSet(stdout,set2);
	intersectionSet(&set3,set,set2);
	printf("Result (Empty set):\n");
	printSet(stdout,set3);
	
	freeSet(&set);	
	freeSet(&set2);
	freeSet(&set3);

	/* Intersection set */
	printf("Intersection of sets II:\n");
	newSet(&set);
	newSet(&set2);
	addSet(set,(void *)&value1,sizeof(int),&printInt);
	addSet(set2,(void *)&value2,sizeof(int),&printInt);
	addSet(set,(void *)&value3,sizeof(int),&printInt);
	addSet(set2,(void *)&value4,sizeof(int),&printInt);
	addSet(set,(void *)&value5,sizeof(int),&printInt);
	addSet(set2,(void *)&value6,sizeof(int),&printInt);
	addSet(set,(void *)&value7,sizeof(int),&printInt);
	addSet(set2,(void *)&value8,sizeof(int),&printInt);
	addSet(set,(void *)&value9,sizeof(int),&printInt);

	addSet(set,(void *)&value2,sizeof(int),&printInt);
	addSet(set,(void *)&value4,sizeof(int),&printInt);
	addSet(set,(void *)&value6,sizeof(int),&printInt);
	addSet(set,(void *)&value8,sizeof(int),&printInt);

	printf("Set 1:\n");
	printSet(stdout,set);
	printf("Set 2:\n");
	printSet(stdout,set2);
	intersectionSet(&set3,set,set2);
	printf("Result (Even numbers):\n");
	printSet(stdout,set3);
	
	freeSet(&set);	
	freeSet(&set2);
	freeSet(&set3);

	/* Getting the array of infos */
	printf("Getting the array:\n");
	newSet(&set);
	addSet(set,(void *)&value1,sizeof(int),&printInt);
	addSet(set,(void *)&value2,sizeof(int),&printInt);
	addSet(set,(void *)&value3,sizeof(int),&printInt);
	addSet(set,(void *)&value4,sizeof(int),&printInt);
	addSet(set,(void *)&value5,sizeof(int),&printInt);
	addSet(set,(void *)&value6,sizeof(int),&printInt);
	addSet(set,(void *)&value7,sizeof(int),&printInt);
	addSet(set,(void *)&value8,sizeof(int),&printInt);
	printSet(stdout,set);
	
	/* Obtain the infos */
	getSetElements((void***)&arrayIntegers, &arraySizes, set);

	freeSet(&set);	
	
	


	printf("The End\n");
	fflush(stdout);

	return 0;	
}


void printInt(FILE *fp,const void* integer)
{
	fprintf(fp,"(%d)",*(int*)integer);
	fflush(fp);
}

/*
STATUS newSet(Set ** set);
void freeSet(Set ** set);
BOOLEAN isInSet(const Set * set, const void * info, size_t infoSize);
size_t getSizeSet(const Set * set);
STATUS addSet(Set * set, const void * info, size_t infoSize, void (*f_print)(FILE *, const void *));
STATUS insertSet(Set * set, const void * info, size_t infoSize, void (*f_print)(FILE *, const void *));
STATUS removeSet(Set * set, const void * info, size_t infoSize);
STATUS getSetElements(void ** infos, size_t ** infoSizes, const Set * set);
STATUS copySet(Set ** dst,const Set * src);
void printSet(FILE *fp, const Set * set);

BOOLEAN equalsSet(const Set * op1, const Set * op2);
STATUS unionSet(Set ** detination, const Set * op1, const Set * op2);
STATUS intersectionSet(Set ** detination, const Set * op1, const Set * op2);

STATUS newSetElement(SetElement ** setElement,const  void * info, size_t infoSize, void (*f_print)(FILE *, const void *));
void freeSetElement(SetElement ** setElement);
int compareInfoSetElement(const SetElement * setElement, const void * info, size_t infoSize);
BOOLEAN equalsSetElement(const SetElement * setElement1, const SetElement * setElement2);
void printSetElement(FILE *fp, const SetElement * setElement);
*/

