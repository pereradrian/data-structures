#include <set.h>
/*
typedef struct Set {
	void ** elements;
	size_t infoSize;
	int setSize;
}Set;
*/
int newSet(Set ** set, size_t infoSize)
{
	if ( set == NULL ) {
		return ERR;
	}

	(*set) = (Set*)malloc(sizeof(Set));
	(*set)->elements=(Element**)malloc(sizeof(Element*));
	(*set)->elements[0]=NULL;
	(*set)->infoSize=infoSize;
	(*set)->setSize=0;
}

int newSetElement(Set ** set, size_t infoSize)
{
	
}
int isIn(Set * set, const void * info);
int sizeSet(const Set * set);
int sizeInfo(const Set * set);
int addSet(Set * set, const void * info);
int removeSet(Set * set, const void * info);
int getElementsSet(void ** elements,Set * set);
