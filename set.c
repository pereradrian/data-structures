#include <set.h>
/*
typedef struct SetElement {
	void * info;
	size_t infoSize;
}SetElement;

typedef struct Set {
	Element ** elements;
	size_t infoSize;
	int size;
}Set;
*/
int newSet(Set ** set, size_t infoSize)
{
	if ( set == NULL ) {
		return ERR;
	}
}
void freeSet(Set ** set);
int isIn(Set * set, const void * info);
int getSetSize(const Set * set);
int getSetInfoSize(const Set * set);
int addSet(Set * set, const void * info);
int removeSet(Set * set, const void * info);
int getElementsSet(void ** elements, const Set * set);
int compareSets(const Set * set1, const Set * set2);

/* Operations with sets */
int setUnion(Set ** detination, const Set * op1, const Set * op2);
int setIntersection(Set ** detination, const Set * op1, const Set * op2);

/** Auxiliar functions **/
int newSetElement(SetElement ** setElement, void * info, size_t infoSize);
