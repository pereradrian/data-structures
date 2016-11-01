
#include "genericArray.h"

typedef struct Struct {
	void * att1;
	void * att2;
	char * att3;
	int * att4;
	char att5;
	int att6;
	struct Piece * att7;
} Struct;

void printArray( GenericArray * array );
int main() {

	GenericArray * array1 = NULL; 
	GenericArray * array2 = NULL; 
	int integer1 = 1;
	int integer2 = 2;
	int integer22 = 2;
	int integer3 = 3;
	int integer4 = 4;
	int * values[4] = { NULL, NULL, NULL, NULL};
	char ** values2[4] = { NULL, NULL, NULL, NULL};
	Struct * values3[4] = { NULL, NULL, NULL, NULL};

	char * string1 = "string1";
	char * string2 = "string2";
	char * string22 = "string22";
	char * string3 = "string3";
	char * string4 = "string4";

	Struct struct1;
	Struct struct2;
	Struct struct22;
	Struct struct3;
	Struct struct4;

	

	/* First only integers */
	printf("\n\n\n\nTest integers:\n\n\n\n");
	newGenericArray(&array1);
	printArray(array1);
	addGenericArray(array1, &integer2, sizeof(int));
	addGenericArray(array1, &integer2, sizeof(int));
	addGenericArray(array1, &integer1, sizeof(int));
	addGenericArray(array1, &integer2, sizeof(int));
	addGenericArray(array1, &integer2, sizeof(int));
	addGenericArray(array1, &integer2, sizeof(int));
	addGenericArray(array1, &integer2, sizeof(int));
	printArray(array1);
	removeGenericArray(array1, &integer1, sizeof(int));
	printArray(array1);
	removeGenericArray(array1, &integer22, sizeof(int));
	printArray(array1);	
	freeGenericArray(&array1);

	newGenericArray(&array1);
	addGenericArray(array1, &integer1, sizeof(int));
	addGenericArray(array1, &integer2, sizeof(int));
	addGenericArray(array1, &integer3, sizeof(int));
	addGenericArray(array1, &integer4, sizeof(int));

 	getGenericArray((void ***)&values[0] ,array1, 0);
 	getGenericArray((void ***)&values[1] ,array1, 1);
 	getGenericArray((void ***)&values[2] ,array1, 2);
 	getGenericArray((void ***)&values[3] ,array1, 3);

	printf("%d,%d,%d,%d\n",*values[0],*values[1],*values[2],*values[3]);

 	free(values[0]);
 	free(values[1]);
 	free(values[2]);
 	free(values[3]);
	freeGenericArray(&array1);

	newGenericArray(&array1);
	addGenericArray(array1, &integer1, sizeof(int));
	addGenericArray(array1, &integer2, sizeof(int));
	addGenericArray(array1, &integer3, sizeof(int));
	addGenericArray(array1, &integer4, sizeof(int));
	addGenericArray(array1, &integer4, sizeof(int));
	addGenericArray(array1, &integer4, sizeof(int));
	addGenericArray(array1, &integer4, sizeof(int));
	copyGenericArray(&array2,array1);

	printArray(array1);
	printArray(array2);

	freeGenericArray(&array1);
	freeGenericArray(&array2);

	/* Strings */
	printf("\n\n\n\nTest strings:\n\n\n\n");
	newGenericArray(&array1);
	printArray(array1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string2, strlen(string2)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	printArray(array1);
	removeGenericArray(array1, &string2, strlen(string2)+1);
	printArray(array1);
	addGenericArray(array1, &string2, strlen(string2)+1);
	removeGenericArray(array1, &string22, strlen(string22)+1);
	printArray(array1);	
	freeGenericArray(&array1);

	newGenericArray(&array1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string2, strlen(string2)+1);
	addGenericArray(array1, &string3, strlen(string3)+1);
	addGenericArray(array1, &string4, strlen(string4)+1);

 	getGenericArray((void ***)&values2[0] ,array1, 0);
 	getGenericArray((void ***)&values2[1] ,array1, 1);
 	getGenericArray((void ***)&values2[2] ,array1, 2);
 	getGenericArray((void ***)&values2[3] ,array1, 3);

	printf("%s,%s,%s,%s\n",*values2[0],*values2[1],*values2[2],*values2[3]);

 	free(values2[0]);
 	free(values2[1]);
 	free(values2[2]);
 	free(values2[3]);
	freeGenericArray(&array1);

	newGenericArray(&array1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	addGenericArray(array1, &string1, strlen(string1)+1);
	copyGenericArray(&array2,array1);

	printArray(array1);
	printArray(array2);

	freeGenericArray(&array1);
	freeGenericArray(&array2);


	/* Structures */
	printf("\n\n\n\nTest structures:\n\n\n\n");

	struct2.att1=1;
	struct2.att2=2;
	struct2.att3=3;
	struct2.att4=4;
	struct2.att5=5;
	struct2.att6=6;
	struct2.att7=7;

	newGenericArray(&array1);
	printArray(array1);
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct2, sizeof(Struct));	
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	printArray(array1);
	removeGenericArray(array1, &struct2, sizeof(Struct));
	printArray(array1);
	addGenericArray(array1, &struct2, sizeof(Struct));
	removeGenericArray(array1, &struct22, sizeof(Struct));
	printArray(array1);	
	freeGenericArray(&array1);

	newGenericArray(&array1);
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct2, sizeof(Struct));
	addGenericArray(array1, &struct3, sizeof(Struct));
	addGenericArray(array1, &struct4, sizeof(Struct));

 	getGenericArray((void ***)&values3[0] ,array1, 0);
 	getGenericArray((void ***)&values3[1] ,array1, 1);
 	getGenericArray((void ***)&values3[2] ,array1, 2);
 	getGenericArray((void ***)&values3[3] ,array1, 3);


	printf("%p,%p,%p,%p,%p,%p,%p",values3[2]->att1,values3[2]->att2,
values3[2]->att3,values3[2]->att4,values3[2]->att5,values3[2]->att6,values3[2]->att7);

 	free(values3[0]);
 	free(values3[1]);
 	free(values3[2]);
 	free(values3[3]);
	freeGenericArray(&array1);

	newGenericArray(&array1);
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	addGenericArray(array1, &struct1, sizeof(Struct));
	copyGenericArray(&array2,array1);

	printArray(array1);
	printArray(array2);

	freeGenericArray(&array1);
	freeGenericArray(&array2);
	
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

void printArray( GenericArray * array )
{
	if (!array) {
		return;
	}
	int i=0, offset = 0;
	printf("*************\n");
	printf("Elements:\t%d\n",array->sizeInElements);
	printf("Size:\t%d\n",array->sizeInBytes);
	printf("Set:\n");
	for (i=0; i<array->sizeInElements;i++) {
		printf("[%p,%ld]\n",array->infos+offset,array->sizes[i]);
		offset+=array->sizes[i];
	}
	printf("\n*************\n");
	fflush(stdout);

	return;	
}
