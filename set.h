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

int newSet(Set ** set, size_t infoSize);
int newSetElement(SetElement ** setElement, void * info);
int isIn(Set * set, const void * info);
int sizeSet(const Set * set);
int sizeInfo(const Set * set);
int addSet(Set * set, const void * info);
int removeSet(Set * set, const void * info);
int getElementsSet(void ** elements,Set * set);

/* TODO add a function to compare two elements in the class? */
#endif
