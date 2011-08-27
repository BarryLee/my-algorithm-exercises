/* Find the longest mono-increasing subsequence.
 */
#include <stdio.h>
#include <ctype.h>

#define P(arr, sz) {\
    int i;\
    for (i = 0; i < (sz); i++)\
        printf("%d ", arr[i]);\
    printf("\n");\
}

int find_subseq(int a[], int na, int r[])
{
    int i,j,max;
    int global_max = 1, global_max_idx = 0;

    if (na == 0)
        return 0;

    for (i = 0; i < na; i++)
        r[i] = 1;

    for (i = 1; i < na; i++)
    {
        max = 1;
        for (j = 0; j < i; j++)
        {
            if (a[j] <= a[i])
                if (r[j] + 1 > max)
                    max = r[j] + 1;
        }
        if (max > global_max)
        {
            global_max = max;
            global_max_idx = i;
        }
        r[i] = max;
    }

    return global_max_idx;
}

int find_slot(int aux[], int x, int l, int u)
{
    if (l >= u)
        if (aux[l] > x)
            return l;
        else
            return l+1;

    int m = (l + u) / 2;
    
    if (aux[m] == x)
        return m+1;
    else if (aux[m] > x)
        return find_slot(aux, x, l, m-1);
    else 
        return find_slot(aux, x, m+1, u);

}

/* A improved version with previous temp results sorted
 * and searched with binary searching.
 */
int find_subseq_improved(int a[], int na, int r[])
{
    int i,j,k;
    int global_max = 0, global_max_idx = -1;
    int aux[na+1];
    int inf = ~0U >> 1;

    if (na == 0)
        return 0;

    for (i = 0; i < na; i++)
        r[i] = 1;

    for (i = 0; i <= na; i++)
        aux[i] = inf;
    aux[1] = a[0];
    int last_inorder = 1;

    for (i = 1; i < na; i++)
    {
        /*P(aux, na+1);*/
        k = find_slot(aux, a[i], 1, last_inorder);
        r[i] = k;
        if (k > global_max)
        {
            global_max = k;
            global_max_idx = i;
        }

        if (aux[k] > a[i])
            aux[k] = a[i];
        if (k > last_inorder)
            last_inorder = k;
    }

    return global_max_idx;
}

void print_subsec(int a[], int r[], int max_idx)
{
    int i, last;

    printf("%d ", a[max_idx]);

    for (i = max_idx-1, last = r[max_idx]; i >= 0; i--)
        if ( last - r[i] == 1 )
        {
            printf("%d ", a[i]);
            last = r[i];
        }
    printf("\n");
}
        
#define MAXN 20
#define MAXD 3

int main(void)
{
    int ch, na, in, max_idx, temp;
    int a[MAXN], r[MAXN], buf[MAXD];
    
    while ( (ch = getchar()) != EOF )
    {
        na = 0;
        temp = 0;
        in = 0;

        do
        {
            if (isdigit(ch))
            {
                if (!in)
                    in = 1;
                temp = 10 * temp + (ch - '0');
            } 
            else if (isspace(ch))
            {
                if (in)
                {
                    a[na++] = temp;
                    temp = 0;
                    in = 0;
                }
                if (ch == '\n')
                    break;
            }
            else
            {
                printf("invalid input!\n");
            }
        } while ((ch = getchar()) != EOF);

        printf("Input: ");
        P(a, na);

        max_idx = find_subseq_improved(a, na, r);
        /*max_idx = find_subseq(a, na, r);*/
        P(r, na);
        print_subsec(a, r, max_idx);

        if (ch == EOF) break;
    }

    return 0;
}
