
#include "genericArray.h"

int main() {

	GenericArray * array1 = NULL; 
	int integer1 = 1;

	/* First only integers */
	newGenericArray(&array1);
	addGenericArray(array1, &integer1, sizeof(int));
	freeGenericArray(&array1);

	/* Strings */
	/* Structures */
	/* All together */
	return 0;
}
/*
STATUS newGenericArray(GenericArray ** genericArray);
STATUS addGenericArray(GenericArray * genericArray, const void * info, size_t size);
STATUS removeGenericArray(GenericArray * genericArray, const void * info, size_t size);
STATUS getGenericArray(void *** destination ,const GenericArray * genericArray, int index);
int getSizeInElementsGenericArray(GenericArray * genericArray);
int getSizeInBytesGenericArray(GenericArray * genericArray);
STATUS copyGenericArray(GenericArray ** destination, const GenericArray * origin);
void freeGenericArray( GenericArray ** genericArray);
*/
