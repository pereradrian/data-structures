
#include "./genericArray.h"

/*
typedef struct GenericArray {
	void ** infos;
	size_t * sizes;
	int size;
}GenericArray;
*/
STATUS newGenericArray(GenericArray ** genericArray)
{
	if ( genericArray == NULL) {
		return ERR;
	}

	(*genericArray)=(GenericArray*)malloc(sizeof(GenericArray));
	if ( (*genericArray) == NULL) {
		return ERR;
	}

	(*genericArray)->infos=NULL;
	(*genericArray)->sizes=NULL;
	(*genericArray)->sizeInBytes=0;
	(*genericArray)->sizeInElements=0;

	return OK;
}

STATUS addGenericArray(GenericArray * genericArray, const void * info, size_t size)
{
	/* Realloc the arrays */
	genericArray->infos=(uint8_t*)realloc(genericArray->infos,genericArray->sizeInBytes+size);
	if ( genericArray->infos == NULL) {
		return ERR;
	}

	genericArray->sizes=(size_t*)realloc(genericArray->sizes,(genericArray->sizeInElements+1)*sizeof(size_t));
	if ( genericArray->sizes == NULL) {
		return ERR;
	}

	/* Copy the new element */
	memcpy(genericArray->infos+genericArray->sizeInBytes, info, size);
	genericArray->sizes[genericArray->sizeInElements]=size;
	genericArray->sizeInBytes+=size;
	genericArray->sizeInElements++;

	return OK;
}

STATUS removeGenericArray(GenericArray * genericArray, const void * info, size_t size)
{

	if ( genericArray == NULL || info == NULL ) {
		return ERR;
	}

	int index=0;
	int offset=0;
	uint8_t * infos = 0;
	size_t * sizes = NULL;
		

	/* Code optimixation */
	infos = genericArray->infos;
	sizes = genericArray->sizes;

	/* Look for the element in the hole array */
	for ( ; offset<genericArray->sizeInBytes && index < genericArray->sizeInElements ; index++ ) {
		/* If the element is found shift the vector and realloc with smaller size*/
		if (sizes[index] == size) {
			if ( memcmp(infos+offset, info, size) == 0 && sizes[index] == size ) {
				/* Copy the entire array left but the element to remove */
				memmove(infos+offset, infos+offset+size, genericArray->sizeInBytes - size - offset);
				genericArray->infos = realloc(infos, genericArray->sizeInBytes - size );

				/* Update the array information */
				genericArray->sizeInBytes-=size;
				genericArray->sizeInElements--;
			
				return OK;	
			}
		}
		offset += sizes[index];
	}
	
	return OTHER;
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

