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

BOOLEAN isInSet(const Set * set, const void * info, size_t infoSize)
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
		if (compareInfoSetElement(elements[i],info,infoSize) == 0) {
			return TRUE;
		}
	}
	
	return FALSE;
}

size_t getSizeSet(const Set * set)
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
		if (compareInfoSetElement(elements[i],info,infoSize) == 0) {
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
	newSetElement(&(set->elements[size]),info,infoSize,f_print);
	/* Update the set size */
	set->size=size+1;
	
	return OK;

}

/* Same as add, but does not check if the element is already in the set */
STATUS insertSet(Set * set, const void * info, size_t infoSize, void (*f_print)(FILE *, const void *))
{
	int size =0;
	SetElement ** elements =NULL;

	if ( set ==NULL ) {
		return ERR;
	}

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements=set->elements;
	size=set->size;

	/* Resize the vector */
	set->elements=(SetElement **)realloc(elements,(size+1)*sizeof(SetElement*));
	if ( set->elements == NULL ) {
		return ERR;
	}

	/* Create the new element */
	newSetElement(&(set->elements[size]),info,infoSize,f_print);
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
	for ( ; i<size ; i++) {
		if (compareInfoSetElement(elements[i],info,infoSize) == 0) {
			/* free the removed element */
			freeSetElement(&(elements[i]));
			/* Keep the memory aligned*/
			/* Shift each element one position to the left */
			for (;i<size-1;i++) {
				elements[i]=elements[i+1];
			}
			/* Update the structure */
			set->size=size-1;
			return OK;
		}
	}

	/* The element was missing */
	return OTHER;
}

STATUS getSetElements(void *** infos, size_t ** infoSizes, const Set * set)
{
	int i=0;
	int size =0;
	int infosSize =0;
	int offset =0;
	SetElement ** elements =NULL;
	void ** infoOffset =NULL;

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
		offset=elements[i]->infoSize;
		infosSize+=offset;
		
		printf("%d,%d\t",offset,infosSize);	
		(*infos)=(void**)realloc((*infos),infosSize);
		if ( (*infos) == NULL ) {
			free((*infoSizes));
			return ERR;
		}

		/* Copy the information */
		infoOffset = (*infos)+infosSize-offset;
		infoOffset =malloc(elements[i]->infoSize);
		memcpy( infoOffset, elements[i]->info, elements[i]->infoSize);
		printf("(%d)\n",*(int*)(infoOffset));
	}

	return OK;
}

STATUS copySet(Set ** dst,const Set * src)
{
	int i=0;
	int size =0;
	SetElement ** elements =NULL;

	if ( dst == NULL || src == NULL ) {
		return ERR;
	}

	/* Create, and allocate the destination array */
	newSet(dst);

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements=src->elements;
	size=src->size;

	/* Alloc space for the vector */
	(*dst)->elements=(SetElement **)malloc(size*sizeof(SetElement*));

	/* Iterate over the first array inserting each element*/
	for ( ; i<size ; i++) {
		if ( (*dst)->elements == NULL ) {
			return ERR;
		}
		/* Create the new element */
		newSetElement(&((*dst)->elements[i]),elements[i]->info,elements[i]->infoSize,elements[i]->f_print);
	}

	/* Update the set size */
	(*dst)->size=size;

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

BOOLEAN equalsSet(const Set * op1, const Set * op2)
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
		if (isInSet(op2,elements1[i]->info,elements1[i]->infoSize) == FALSE) {
			return FALSE;
		}
	}
	
	return TRUE;
}

STATUS unionSet(Set ** destination, const Set * op1, const Set * op2)
{
	int i=0;
	int size =0;
	SetElement ** elements =NULL;

	if ( destination == NULL || op1 == NULL || op2 == NULL ) {
		return ERR;
	}

	/* Create, and allocate the destination array */
	newSet(destination);

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	elements=op1->elements;
	size=op1->size;

	/* Iterate over the first array inserting each element*/
	for (i=0 ; i<size ; i++) {
		/* Insert the new element */
		insertSet((*destination), elements[i]->info, elements[i]->infoSize, elements[i]->f_print);
	}

	elements=op2->elements;
	size=op2->size;

	/* Iterate over the second array adding each element*/
	for (i=0 ; i<size ; i++) {
		addSet((*destination), elements[i]->info, elements[i]->infoSize, elements[i]->f_print);
	}

	return OK;
}

/* intersection uses insert, because the destination set is empty */
STATUS intersectionSet(Set ** destination, const Set * op1, const Set * op2)
{
	int i=0;
	int size =0;
	SetElement ** elements =NULL;

	if ( destination == NULL || op1 == NULL || op2 == NULL ) {
		return ERR;
	}

	/* Create, and allocate the destination array */
	newSet(destination);

	/* Code otimization */
	/* Needs a little bit of extra memory, but is faster */
	size=op1->size;
	elements=op1->elements;

	/* Iterate over the first array adding each element if is in the second */
	for (i=0 ; i<size ; i++) {
		if (isInSet(op2,elements[i]->info,elements[i]->infoSize) == TRUE) {
			/* Insert the new element */
			insertSet((*destination), elements[i]->info, elements[i]->infoSize, elements[i]->f_print);
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

int compareInfoSetElement(const SetElement * setElement, const void * info, size_t infoSize)
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

BOOLEAN equalsSetElement(const SetElement * setElement1, const SetElement * setElement2)
{
	if ( compareInfoSetElement(setElement1, setElement2->info,setElement2->infoSize) == 0) {
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

