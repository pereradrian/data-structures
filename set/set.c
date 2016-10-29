#include "set.h"
/*
typedef struct SetElement {
	void * info;
	size_t infoSize;
	void (*printSetElement)(FILE *, const void *);
}SetElement;

typedef struct Set {
	SetElement ** elements;
	int size;
}Set;
*/
STATUS newSet(Set ** set)
{
	if ( set == NULL ) {
		return ERR;
	}

	/* Allocating memory for the set */
	(*set)=(Set*)malloc(sizeof(Set));
	if ( (*set) ==NULL ) {
		return ERR;
	}
		
	/* Initialization of the empty set */
	(*set)->elements=NULL;
	(*set)->size=0;
	
	return OK;
}

void freeSet(Set ** set)
{
	int i=0;
	int size =0;
	SetElement ** elements =NULL;

	if ( (*set)==NULL ) {
		return;
	}

	if ( set == NULL ) {
		return;
	}

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	/* TODO check how faster is it! */
	elements=(*set)->elements;
	size=(*set)->size;

	/* The memory is aligned so we can iterate over the array  */
	for (i=0; i<size; i++) {
		freeSetElement(&(elements[i]));
	}

	/* free(ptr) does nothing while ptr == NULL*/
	free(elements);
	
	/* free the set (*set)=NULL; is convenient*/
	free((*set));
	(*set)=NULL;
	
	return;
}
BOOLEAN isIn(const Set * set, const void * info, size_t infoSize)
{
	int i=0;
	int size =0;
	SetElement ** elements =NULL;

	if ( set ==NULL ) {
		return ERR;
	}

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements=set->elements;
	size=set->size;

	/* Iterate over the array checking if the info is in any element */
	for (i=0 ; i<size ; i++) {
		if (compareInfoElement(elements[i],info,infoSize) == TRUE) {
			return TRUE;
		}
	}
	
	return FALSE;
}

size_t getSetSize(const Set * set)
{
	return set->size;
}
STATUS addSet(Set * set, const void * info, size_t infoSize, void (*f_print)(FILE *, const void *))
{
	int i=0;
	int size =0;
	SetElement ** elements =NULL;

	if ( set ==NULL ) {
		return ERR;
	}

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements=set->elements;
	size=set->size;

	/* Iterate over the array checking if the info is in any element */
	for (i=0 ; i<size ; i++) {
		if (compareInfoElement(elements[i],info,infoSize) == TRUE) {
			return OTHER;
		}
	}

	/* If the element is not in the set, we insert it at the end of it */
	/* Resize the vector */
	set->elements=(SetElement **)realloc(elements,(size+1)*sizeof(SetElement*));
	if ( set->elements == NULL ) {
		return ERR;
	}

	/* Create the new element */
	newSetElement(&(set->elements[size+1]),info,infoSize,f_print);
	/* Update the set size */
	set->size=size+1;
	
	return OK;

}

STATUS removeSet(Set * set, const void * info, size_t infoSize)
{
	int i=0;
	int size =0;
	SetElement ** elements =NULL;

	if ( set ==NULL ) {
		return ERR;
	}

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements=set->elements;
	size=set->size;

	/* Iterate over the array checking if the info is in any element */
	for (i=0 ; i<size ; i++) {
		if (compareInfoElement(elements[i],info,infoSize) == TRUE) {
			freeSetElement(&(elements[i]));
			return OK;
		}
	}

	/* The element was missing */
	return OTHER;
}

STATUS getElementsSet(void ** infos, size_t ** infoSizes, const Set * set)
{
	int i=0;
	int size =0;
	int infosSize =0;
	SetElement ** elements =NULL;

	/* I enjoy so much implementing this function and messing with memory */

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements=set->elements;
	size=set->size;

	/* First thing is to create the array of sizes */
	(*infoSizes)=(size_t*)malloc(sizeof(size_t)*size);
	if ( (*infoSizes)==NULL ) {
		return ERR;
	}	

	/* Iterate over the array obtaining the info and the size of each element */
	for (i=0 ; i<size ; i++) {
		/* Recalculate the size of the info array and alocate new size*/
		infosSize+=elements[i]->infoSize;
		(*infos)=realloc((*infos),infosSize);
		if ( (*infos) ==NULL ) {
			free(infoSizes);
			return ERR;
		}

		/* Copy the information */
		memcpy(infos+infosSize-elements[i]->infoSize,elements[i],elements[i]->infoSize);
	}

	return OK;
}

void printSet(FILE *fp, const Set * set)
{

	int i=0;
	int size =0;
	SetElement ** elements =NULL;

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements=set->elements;
	size=set->size;

	fprintf(fp,"\n{\n");
	
	/* Iterate over the array obtaining the info and the size of each element */
	for (i=0 ; i<size ; i++) {
		printSetElement(fp,elements[i]);
	}

	fprintf(fp,"\n}\n");
	fflush(fp);

	return;
}

BOOLEAN setsEqual(const Set * op1, const Set * op2)
{
	int i=0;
	int size1 =0;
	SetElement ** elements1 =NULL;

	if ( op1 ==NULL || op2==NULL ) {
		return TRUE;
	}

	/* First case ( comparing by cardinality )*/
	if ( op1->size != op2->size ) {
		return FALSE;
	}

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements1=op1->elements;
	size1=op1->size;

	/* Iterate over the array checking if all elements of set 1 are in the set 2*/
	for (i=0 ; i<size1 ; i++) {
		/* If one element */
		if (isIn(op2,elements1[i]->info,elements1[i]->infoSize) == FALSE) {
			return FALSE;
		}
	}
	
	return TRUE;
}

STATUS setUnion(Set ** detination, const Set * op1, const Set * op2)
{
	int i=0;
	int size =0;
	SetElement ** elements =NULL;

	if ( detination == NULL || op1 == NULL || op2 == NULL ) {
		return ERR;
	}

	/* Create, and allocate the destination array */
	newSet(detination);

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements=op1->elements;
	size=op1->size;

	/* Iterate over the first array adding each element*/
	for (i=0 ; i<size ; i++) {
		addSet((*detination), elements[i]->info, elements[i]->infoSize, elements[i]->f_print);
	}

	elements=op2->elements;
	size=op2->size;

	/* Iterate over the second array adding each element*/
	for (i=0 ; i<size ; i++) {
		addSet((*detination), elements[i]->info, elements[i]->infoSize, elements[i]->f_print);
	}

	return OK;
}

STATUS setIntersection(Set ** detination, const Set * op1, const Set * op2)
{
	int i=0,j=0;
	int size1 =0, size2 =0;
	SetElement ** elements1 =NULL, ** elements2 =NULL;

	if ( detination == NULL || op1 == NULL || op2 == NULL ) {
		return ERR;
	}

	/* Create, and allocate the destination array */
	newSet(detination);

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements1=op1->elements;
	size1=op1->size;
	elements2=op2->elements;
	size2=op2->size;

	/* Iterate over the first array adding each element if is in the second */
	for (i=0 ; i<size1 ; i++) {
		for (j=0; j<size2 ; j++) {
			if (elementsEqual(elements1[i], elements2[j]) == TRUE) {
				addSet((*detination), elements1[i]->info, elements1[i]->infoSize,elements1[i]->f_print);
			}
		}
	}
	
	return OK;
}

/** Auxiliary functions **/
STATUS newSetElement(SetElement ** setElement,const  void * info, size_t infoSize, void (*f_print)(FILE *, const void *))
{
	if ( setElement == NULL ) {
		return ERR;
	}

	/* Allocating memory for the element */
	(*setElement)=(SetElement*)malloc(sizeof(SetElement));
	if ( (*setElement) ==NULL ) {
		return ERR;
	}
		
	/* Initialization of the element */
	(*setElement)->info=(void*)malloc(infoSize);
	memcpy((*setElement)->info, info, infoSize);
	(*setElement)->infoSize=infoSize;
	(*setElement)->f_print=f_print;
	
	return OK;
}
void freeSetElement(SetElement ** setElement)
{

	if ( (*setElement)==NULL ) {
		return;
	}

	if ( setElement == NULL ) {
		return;
	}

	/* free the info and the setElement, (*set)=NULL; is convenient*/
	free((*setElement)->info);
	free((*setElement));
	(*setElement)=NULL;
	
	return;
}

int compareInfoElement(const SetElement * setElement, const void * info, size_t infoSize)
{
	if ( setElement == NULL || info == NULL) {
		return 0;
	}
	
	if ( setElement->infoSize < infoSize ) {
		return -1;
	} else if ( infoSize < setElement->infoSize ) {
		return 1;
	}

	return memcmp(setElement->info, info, infoSize);
}

BOOLEAN elementsEqual(const SetElement * setElement1, const SetElement * setElement2)
{
	if ( compareInfoElement(setElement1, setElement2->info,setElement2->infoSize) == 0) {
		return TRUE;
	}
	return TRUE;
}

void printSetElement(FILE *fp, const SetElement * setElement)
{
	if (setElement->f_print != NULL) {
		setElement->f_print(fp,setElement->info);
	} else {
		fprintf(fp,"(%p,%ld)",setElement->info,setElement->infoSize);
	}
	fflush(stdout);

	return;
}

