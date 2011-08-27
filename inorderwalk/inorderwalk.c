/* In-order traverse a tree, with no explicit or implicit usage
 * of stacks. The tree node has a point to its parent.
 */
#include "inorderwalk.h"
#include <stdlib.h>
#include <stdio.h>

tree *newnode(int k)
{
    tree *node;

    node = (tree*)malloc(sizeof(tree));
    node->k = k;
    node->p = node->lc = node->rc = NULL;
    
    return node;
}

tree *buildtree(int a[], int n)
{
    tree *root;
    int i;

    if (n > 0)
        root = newnode(a[0]);
    else
        return NULL;

    for (i = 1; i < n; i++)
        bst_insert(root, a[i]);

    return root;
}

void bst_insert(tree *t, int k)
{
    tree *node;

    if (k <= t->k)
        if (t->lc == NULL)
        {
            node = newnode(k);
            t->lc = node;
            node->p = t;
        }
        else
            bst_insert(t->lc, k);
    else
        if (t->rc == NULL)
        {
            node = newnode(k);
            t->rc = node;
            node->p = t;
        }
        else
            bst_insert(t->rc, k);
}
            
void inorderwalk(tree *t)
{
    tree *node;
    
    node = t;
    do {
        while (node->lc != NULL)
            node = node->lc;

        printf("%d ", node->k);
        
        if (node->rc != NULL)
            node = node->rc;
        else
        {
            while (node->p)
            {
                if (node->p->rc == node)
                    node = node->p;
                else
                {
                    node = node->p;
                    printf("%d ", node->k);
                    if (node->rc)
                    {
                        node = node->rc;
                        break;
                    }
                }
            }
        }
            
    } while (node->p != NULL);
    printf("\n");
}

