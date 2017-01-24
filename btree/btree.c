#include "btree.h"

Bnode * newBnode(void * info, size_t size)
{
	Bnode  * bnode = NULL;

	bnode = (Bnode*)malloc(sizeof(Bnode));
	bnode->info = malloc(size);
	memcpy(bnode->info, info, size);
	bnode->size = size;

	return bnode;
}

void freeBnode(Bnode * bnode)
{
	if ( bnode == NULL) {
		return;
	}

	free(bnode->info);
	free(bnode);

	return;
}

Btree * newBTree(int compare(Bnode *, Bnode *))
{
	Btree * btree = NULL;

	btree = (Btree*)malloc(sizeof(Btree));
	btree->root = NULL;
	btree ->compare = compare;
	
	return btree;  
}

void freeBtree( Btree * btree);
Btree * addBtree(void * info, size_t size);
Btree * removeBtree(void * info, size_t size);
Bnode * findBtree(void * info, size_t size);

GenericArray * getAllDepthFirstBtree(Btree btree);
GenericArray * getAllBreadthFirstBtree(Btree btree);
