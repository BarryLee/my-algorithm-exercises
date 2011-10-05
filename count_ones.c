/*
 * Given number x, count the number of appearances of 1s in 1...x
 * e.g. 12: 1,2,...10,11,12 gives 5 ones.
 */
#include <stdio.h>

int count_ones_sub(int x, int scale, int remainder)
{
    if (!x)
        return 0;

    int d = x % 10, 
        t = x / 10, 
        n = 0;

    if (d > 1)
        n = scale;
    else if (d == 1)
        n = remainder + 1;
    else
        n = 0;

    return n + t*scale + count_ones_sub(x/10, scale*10, remainder+d*scale);
}

int count_ones(int x)
{
    return count_ones_sub(x, 1, 0);
}

int main()
{
    int x;
    while (scanf("%d", &x) != EOF)
        printf("%d\n", count_ones(x));

    return 0;
}
