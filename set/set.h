#ifndef __SET_H__
#define __SET_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../types.h"

typedef struct SetElement {
	void * info;
	size_t infoSize;
	void (*f_print)(FILE *, const void *);
}SetElement;

typedef struct Set {
	SetElement ** elements;
	int size; /* useful */
}Set;

STATUS newSet(Set ** set);
void freeSet(Set ** set);
BOOLEAN isInSet(const Set * set, const void * info, size_t infoSize);
size_t getSizeSet(const Set * set);
STATUS addSet(Set * set, const void * info, size_t infoSize, void (*f_print)(FILE *, const void *));
STATUS removeSet(Set * set, const void * info, size_t infoSize);
STATUS getSetElements(void ** infos, size_t ** infoSizes, const Set * set);
STATUS copySet(Set ** dst,const Set * src);
void printSet(FILE *fp, const Set * set);

/* Operations with sets */
BOOLEAN equalsSet(const Set * op1, const Set * op2);
STATUS unionSet(Set ** detination, const Set * op1, const Set * op2);
STATUS interSectionSet(Set ** detination, const Set * op1, const Set * op2);

/** Auxiliary functions **/
STATUS newSetElement(SetElement ** setElement,const  void * info, size_t infoSize, void (*f_print)(FILE *, const void *));
void freeSetElement(SetElement ** setElement);
int compareInfoSetElement(const SetElement * setElement, const void * info, size_t infoSize);
BOOLEAN equalsSetElement(const SetElement * setElement1, const SetElement * setElement2);
void printSetElement(FILE *fp, const SetElement * setElement);

#endif
