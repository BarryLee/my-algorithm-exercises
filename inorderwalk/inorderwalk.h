#ifndef INORDERWALK_H
#define INORDERWALK_H
typedef struct tnode {
    struct tnode *p, *lc, *rc;
    int k;
} tree;

tree *newnode(int);

tree *buildtree(int[], int);

void bst_insert(tree*, int);

void inorderwalk(tree *t);
#endif
