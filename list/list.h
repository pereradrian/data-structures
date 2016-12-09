#ifndef __LIST_H__
#define __LIST_H__

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../types.h"

typedef struct List {
	uint8_t * infos; /* memory reserved*/
	size_t size; /* size in bytes of each element */
	int sizeInBytes; /* size of the list in bytes */
	int sizeInElements; /* size of the list in elements */
	void (*compare)(uint8_t * info1, uint8_t * info2); /* function to compare two elements */
}List;

STATUS newList(List ** list, size_t size, void (*compare)(uint8_t * info1, uint8_t * info2));
STATUS addList(List * list, const void * info, size_t size);
STATUS removeList(List * list, const void * info, size_t size);
STATUS getList(void *** destination ,const List * list, int index);
int getSizeInElementsList(List * list);
int getSizeInBytesList(List * list);
STATUS copyList(List ** destination, const List * origin);
void freeList(List ** list);

#endif
