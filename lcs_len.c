/* Determine the length of longest common subsequence
 * with O(n) extra space.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lcs_len(char *a, int na, char *b, int nb)
{
    int i, j, ns, nl;
    int *z;
    char *shorter, *longer;

    i = j = 0;
    if (na <= nb)
    {
        ns = na, nl = nb;
        shorter = a, longer = b;
    } else {
        ns = nb, nl = na;
        shorter = b, longer = a;
    }
    z = (int *)malloc(sizeof(int) * (ns+1)); 

    for (i = 0; i <= ns; i++)
        z[i] = 0;

    for (i = 0; i < nl; i++)
        for (j = 0; j < ns; j++)
            if (longer[i] == shorter[j])
                z[j+1] = z[j] <= z[j+1] ? z[j] + 1 : z[j+1] + 1;
            else 
                z[j+1] = z[j] >= z[j+1] ? z[j] : z[j+1];

    i = z[ns];
    free(z);
    return i;
}
    
/*
 * test
 */
int main(void)
{
    char *A = "ACCGGTCGAGTGCGCGGAAGCCGGCCGAA";
    char *B = "GTCGTTCGGAATGCCGTTGCTCTGTAAA";
    int na = strlen(A);
    int nb = strlen(B);

    printf("%d\n", lcs_len(A, na, B, nb));

    return 0;
}
