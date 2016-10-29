#include "set.h"


void printInt(FILE *fp,void* integer);
int main() {

	Set * set =NULL;
	int value1 =1;
	int value2 =2;
	int value3 =3;
	int value4 =4;

	/*Empty set tests  */
	printf("Empty set tests:\n");
	newSet(&set);
	printSet(stdout,set);
	freeSet(&set);

	/* General test for int types only */
	printf("Integer set tests:\n");
	newSet(&set);
	printf("Empty set size:%ld\n",getSetSize(set));
	addSet(set,(void *)&value1,sizeof(int),printInt);
	addSet(set,(void *)&value2,sizeof(int),printInt);
	addSet(set,(void *)&value3,sizeof(int),printInt);
	addSet(set,(void *)&value4,sizeof(int),printInt);	
	printSet(stdout,set);
	
	freeSet(&set);

	

	printf("The End\n");
	fflush(stdout);

	return 0;	
}


void printInt(FILE *fp,void* integer)
{
	fprintf(fp,"(%d)",*(int*)integer);
	fflush(fp);
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

