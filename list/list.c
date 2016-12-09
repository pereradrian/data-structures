
#include "./list.h"

/*
typedef struct List {
	uint8_t * infos;
	size_t size;
	int sizeInBytes;
	int sizeInElements;
	void (*compare)(uint8_t * info1, uint8_t * info2);
}List;
*/
/*
STATUS addList(List * list, const void * info, size_t size);
STATUS removeList(List * list, const void * info, size_t size);
STATUS getList(void *** destination ,const List * list, int index);
int getSizeInElementsList(List * list);
int getSizeInBytesList(List * list);
STATUS copyList(List ** destination, const List * origin);
void freeList(List ** list);
*/
STATUS newList(List ** list, size_t size, void (*compare)(uint8_t * info1, uint8_t * info2))
{
	if ( list == NULL) {
		return ERR;
	}

	(*list)=(GenericArray*)malloc(sizeof(List));
	if ( (*list) == NULL) {
		return ERR;
	}

	(*list)->infos=NULL;
	(*list)->size=size;
	(*list)->sizeInBytes=0;
	(*list)->sizeInElements=0;
	(*list)->compare=compare;

	return OK;
}

STATUS addList(List * list, const void * info, size_t size)
{
	int i = 0;
	int tamano = 0;
	void (*compare)(uint8_t * info1, uint8_t * info2);
	uint8_t * infos=NULL;

	if ( size != list->size ) {
		return ERR;
	}

	/* Realloc the array */
	list->infos=(uint8_t*)realloc(list->infos, list->sizeInBytes+size);
	if ( list->infos == NULL) {
		return ERR;
	}
	
	tamano = list->sizeInBytes;
	compare = list->compare;
	infos = list->infos;

	/* The list is empty */
	if ( tamano == 0 ) {
		mempcy(infos, info, size);
		genericArray->sizeInBytes=size;
		genericArray->sizeInElements=1;
		return OK;
	}

	/* Insert keeping the order */
	while ( i<tamano && compare(infos+i, info)<0) {	
		i+=size;
	}

	/* We found the apropiate place */
	memmove(infos+i, infos+i-size, tamano-i+size);
	memcpy(infos+i-size, info, size);

	return OK;
}

STATUS removeList(List * list, const void * info, size_t size)
{
	int index=0;
	int offset=0;
	uint8_t * infos = NULL;
	uint8_t * position = NULL;
	size_t sizeToMove = 0;
	
	if ( size != list->size ) {
		return ERR;
	}	

	if ( list == NULL || info == NULL ) {
		return ERR;
	}

	/* Code optimization */
	infos = genericArray->infos;

	/* Since the list is ordered and all elements have the same length, we can use bsearch */
	position = bsearch(info, infos, list->sizeInElements, genericArray->size, list->compare);
	if ( position == NULL ) {
		return OTHER;
	}
	
	/* Calculate the offset */
	sizeToMove = infos+list->sizeInBytes-position;
	memmove(position, position+size, sizeToMove-size);
	
}

/* returns the size copied */
int getGenericArray(void *** destination , const GenericArray * genericArray, int index)
{
	int	i=0;
	uint8_t * offset = 0;
	size_t *sizes =NULL;
	
	if ( destination  ==NULL || genericArray == NULL  || index < 0 ) {
		return -1;
	}
	
	if ( index > genericArray->sizeInElements ) {
		return -1;
	}

	/* Code optimization */
	sizes = genericArray->sizes;

	/* Allocate the element */
	(*destination)=malloc(sizes[index]);
	if ( (*destination) ==NULL ) {
		return -1;
	}


	/* Look for the offset of the element */
	for ( offset = genericArray->infos ; i<index ; i++) {
		offset+=sizes[i];
	}
	
	/* Copy the element */
	memcpy((*destination), offset, sizes[index]);

	return sizes[index];
}

int getSizeInElementsGenericArray(GenericArray * genericArray)
{
	return genericArray->sizeInElements;
}

int getSizeInBytesGenericArray(GenericArray * genericArray)
{
	return genericArray->sizeInBytes;
}

STATUS copyGenericArray(GenericArray ** destination, const GenericArray * origin)
{
	if ( destination == NULL || origin == NULL ) {
		return ERR;
	}

	/* Alloc destination */
	(*destination)=(GenericArray*)malloc(sizeof(GenericArray));
	if ( (*destination) == NULL) {
		return ERR;
	}

	/* Alloc destination arrays */
	(*destination)->infos=malloc(origin->sizeInBytes);
	(*destination)->sizes=malloc(origin->sizeInElements*(sizeof(size_t)));

	/* Copy hole arrays */
	memcpy((*destination)->infos,origin->infos, origin->sizeInBytes);
	memcpy((*destination)->sizes,origin->sizes, origin->sizeInElements*(sizeof(size_t)));
	(*destination)->sizeInBytes=origin->sizeInBytes;
	(*destination)->sizeInElements=origin->sizeInElements;

	return OK;
}

void freeGenericArray( GenericArray ** genericArray)
{

	if ( genericArray == NULL ) {
		return;
	}

	if ( (*genericArray) == NULL ) {
		return;
	}		

	/* Free both arrays */
	free((*genericArray)->infos);
	free((*genericArray)->sizes);
	free((*genericArray));
	
	(*genericArray)=NULL;
	
	return;
}

