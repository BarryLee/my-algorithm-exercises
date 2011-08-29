#include <stdio.h>
#include <stdlib.h>

#define MAX(x, y) (x) > (y) ? (x) : (y)

int compute_longest(char *str, int start, int end, int d, int *L)
{
    int l;

    if (start > end)
        return 0;

    if ((l = *(L + start*d + end)) != -1)
        return l;

    if (str[start] == str[end]) {
        return *(L + start*d + end) = compute_longest(str, start+1, end-1, d, L) + 2;
    } else {
        return *(L + start*d + end) = MAX(compute_longest(str, start+1, end, d, L),\
                compute_longest(str, start, end-1, d, L));
    }
}

void build_palindrome(char *str, char *pal, int d, int *L)
{
    int i = 0, j = d-1;
    int this, left, down;
    int l = 0, r = *(L+(d-1)) - 1;

    while (i < j) {
        while ((*(L + i*d + j) == *(L + i*d + j-1)) && i < j)
            j--;
        *(pal + r--) = *(str + j);

        if (!(i < j)) break;

        while ((*(L + i*d + j) == *(L + (i+1)*d + j)) && i < j)
            i++;
        *(pal + l++) = *(str + i);

        i++, j--;
        if (i == j) {
            *(pal + l) = *(str + i);
            break;
        }
    }
    *(pal + *(L+(d-1))) = '\0';
}

void build_palindrome2(char *str, char *pal, int d, int **L)
{
    int i = 0, j = d-1;
    int l = 0, r = L[0][d-1] - 1;

    while (i < j) {
        while ((L[i][j] == L[i][j-1]) && i < j)
            j--;
        *(pal + r--) = *(str + j);

        if (!(i < j)) break;

        while ((L[i][j] == L[i+1][j]) && i < j)
            i++;
        *(pal + l++) = *(str + i);

        i++, j--;
        if (i == j) {
            *(pal + l) = *(str + i);
            break;
        }
    }
    *(pal + L[0][d-1]) = '\0';
}

void print_matrix(int d, int *L)
{
    int i,j;

    for (i = 0; i < d; i++) {
        for (j = 0; j < d; j++)
            printf("%-5d", *(L + i*d + j));
        printf("\n");
    }
}

void compute_longest2(char *str, int **L, int r, int c)
{
    if (r == c)
        return;

    if (str[r] == str[c]) {
        if (r+1 <= c-1)
            L[r][c] = L[r+1][c-1] + 2;
        else
            L[r][c] = 2;
    } else {
        L[r][c] = MAX(L[r+1][c], L[r][c-1]);
    }
}

int longest_palindrome_subseq2(char *str, int n, char *subseq)
{
    int **len;
    int max_len, i, j, k;

    if (!(n > 1))
        return n;

    len = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
        *(len + i) = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        len[i][i] = 1;

    for (i = 1; i < n; i++)
        for (j = 0; j < n-i; j++) {
            k = j+i;
            compute_longest2(str, len, j, k);
        }

    build_palindrome2(str, subseq, n, len);

    max_len = len[0][n-1];
    free(len);

    return max_len;
}

int longest_palindrome_subseq(char *str, int n, char *subseq)
{
    int *len;
    int max_len, i, j;

    if (!(n > 1))
        return n;

    len = (int *)malloc(sizeof(int) * n * n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            if (i == j)
                *(len + i*n + j) = 1;
            else
                *(len + i*n + j) = -1;
        }

    max_len = compute_longest(str, 0, n-1, n, len);

    /*print_matrix(n, len);*/

    /**subseq = (char *)malloc(sizeof(char) * (max_len+1));*/
    build_palindrome(str, subseq, n, len);

    free(len);

    return max_len;
}

int main(void)
{
    char *line = NULL, *subseq = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, stdin)) != -1) {
        printf("Got line of length %zu: \n", read);
        printf("%s", line);
        subseq = (char *)malloc(sizeof(char) * read);
        printf("has longest palindrome subseq of length %d: \n",\
                longest_palindrome_subseq2(line, (int)read-1, subseq));
        printf("%s\n", subseq);
        free(subseq);
    }

    free(line);

    return 0;
}

