#ifndef __SET_H__
#define __SET_H__

typedef struct SetElement {
	void * info;
	size_t infoSize;
}SetElement;

typedef struct Set {
	Element ** elements;
	size_t infoSize;
	int size; /* useful */
}Set;

STATUS newSet(Set ** set, size_t infoSize);
void freeSet(Set ** set);
STATUS isIn(Set * set, const void * info);
size_t getSetSize(const Set * set);
size_t getSetInfoSize(const Set * set);
STATUS addSet(Set * set, const void * info);
STATUS removeSet(Set * set, const void * info);
STATUS getElementsSet(void ** elements, const Set * set);
int compareSets(const Set * set1, const Set * set2);

/* Operations with sets */
STATUS setUnion(Set ** detination, const Set * op1, const Set * op2);
STATUS setIntersection(Set ** detination, const Set * op1, const Set * op2);

/** Auxiliar functions **/
STATUS newSetElement(SetElement ** setElement, void * info, size_t infoSize);
void freeSetElement(SetElement ** setElement);

#endif
