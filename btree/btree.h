#ifndef __BTREE_H__
#define __BTREE_H__

#include <stdlib.h>

#include "genericArray.h"

#define	INFO(t) t->info
#define	SIZE(t) t->size
#define	LEFT(t) t->left
#define RIGHT(t) t->right
#define FATHER(t) t->father
#define	ROOT(t) t->root

typedef struct Bnode {
	size_t size;
	void * info;
	struct Bnode * father;
	struct Bnode * left;
	struct Bnode * right;
} Bnode;

typedef struct Btree {
	void (*compare)(Bnode *, Bnode *);
	Bnode * root;
} Btree;

Bnode * newBnode(void * info, size_t size);
void freeBnode(Bnode * bnode);

Btree * newBTree(int compare(Bnode *, Bnode *));
void freeBtree( Btree * btree);

Btree * addBtree(void * info, size_t size);
Btree * removeBtree(void * info, size_t size);
Bnode * findBtree(void * info, size_t size);

GenericArray * getAllDepthFirstBtree(Btree btree);
GenericArray * getAllBreadthFirstBtree(Btree btree);

#endif
