#include <stdio.h>
#include "inorderwalk.h"

#define MAXN 100

int main(void)
{
    int j, i, ch, a[MAXN];
    tree *t;

    i = 0;
    while ((ch = getchar()) != EOF && ch != '\n' && i < MAXN)
        a[i++] = ch - '0';

    t = buildtree(a, i);
    inorderwalk(t);

    return 0;
}
