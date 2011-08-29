#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXN 1000
#define MAXMAXN 1000000

inline void P(int arr[], int sz)              
{
    int i;
    for (i = 0; i < (sz); i++)
        printf("%d ", arr[i]);
    printf("\n");
}

inline void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int *x, int n, int *r)
{                                            
    int i, l = 0, u = n - 1;                   
    int m1 = 0, m2 = 0;                      
    int pivot = *(x+u);                     
                                              
    for (i = 0; i <= u; i++)                 
        if (*(x+i) < pivot) {                
            swap(x+i, x+m2);     
            swap(x+m1, x+m2);    
            m1++;                            
            m2++;                            
        } else if (*(x+i) == pivot) {        
            swap(x+i, x+m2);     
            m2++;                            
        }                                    
                                              
    r[0] = m1, r[1] = m2;                    
}

void sort(int *x, long n)               
{                                              
    if (n == 0)
        return;

    int r[2];                                  
                                                
    partition(x, n, r);                        
    if ( n-r[1] > r[0] ) {                     
        sort(x, r[0]);                         
        sort(x+r[1], n-r[1]);                  
    } else {                                   
        if ( n > r[1] )
            sort(x+r[1], n-r[1]);                  
        sort(x, r[0]);                         
    }                                          
                                                
    return;                                    
}

void test1(void)
{
    int c, a[MAXN], i=0, x;
    char trash[MAXN];

    do {
        for (i = 0; i < MAXN && (c = scanf("%d", a+i)) == 1;)
        {
            i++;
            if (getchar() == '\n')
            {
                printf("Input: \n");
                P(a, i);
                sort(a, i);
                printf("Output: \n");
                P(a, i);
                break;
            }
        }
        if (c == 0)
        {
            printf("input contains non-digits\n");
            scanf("%[^\n]", trash);
        }
    } while (c != EOF);
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int assert_equal(const int *a, const int *b, const int n)
{
    int i;
    
    for (i = 0; i < n; i++)
        if (*(a+i) != *(b+i) )
            return 0;
    return 1;
}

int test2(int n)
{
    long len;
    int i, a[MAXMAXN], b[MAXMAXN];
    clock_t t1, t2, dt1, dt2;
    /*srand( (unsigned int)time(NULL) );*/
    for (i = 0; i < n && i < MAXMAXN; i++)
        /*a[i] = rand();*/
        a[i] = 100;
    len = i;
    for (i = 0; i < len; i++)
        b[i] = a[i];
    t1 = clock();
    sort(a, len);
    t2 = clock();
    dt1 = t2 - t1;

    t1 = clock();
    qsort(b, len, sizeof(int), cmp);
    t2 = clock();
    dt2 = t2 - t1;

    if (!assert_equal(a, b, len))
    {
        printf("error\n");
        return -1;
    }
    else 
    {
        printf("sort took %10.30f\n", (double)dt1/CLOCKS_PER_SEC);
        printf("qsort took %10.30f\n", (double)dt2/CLOCKS_PER_SEC);
        return 0;
    }
}

void main(void)
{
    /*test1();*/
    test2(999999);
}




