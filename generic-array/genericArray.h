#ifndef __GENERIC_ARRAY_H__
#define __GENERIC_ARRAY_H__

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../types.h"

typedef struct GenericArray {
	uint8_t * infos; /* memory reserved*/
	size_t * sizes; /* array of sizes in bytes of each element */
	int sizeInBytes; /* size of the array in bytes */
	int sizeInElements; /* size of the array in elements */
}GenericArray;

STATUS newGenericArray(GenericArray ** genericArray);
STATUS addGenericArray(GenericArray * genericArray, const void * info, size_t size);
STATUS removeGenericArray(GenericArray * genericArray, const void * info, size_t size);
STATUS getGenericArray(void *** destination ,const GenericArray * genericArray, int index);
int getSizeInElementsGenericArray(GenericArray * genericArray);
int getSizeInBytesGenericArray(GenericArray * genericArray);
STATUS copyGenericArray(GenericArray ** destination, const GenericArray * origin);
void freeGenericArray( GenericArray ** genericArray);

#endif
