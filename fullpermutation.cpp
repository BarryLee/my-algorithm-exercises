/* Find all permutations of an array.
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_perm(const vector<int> &v)
{
    for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

bool next_perm(vector<int> &perm)
{
    vector<int>::reverse_iterator riter = perm.rbegin();

    while (riter+1 != perm.rend() && *riter < *(riter+1))
        riter++;

    if (riter + 1 == perm.rend())
        return false;

    riter++; 
    vector<int>::reverse_iterator right_most = perm.rbegin();
    for (; *right_most < *riter; right_most++)
        ;

    *riter ^= *right_most;
    *right_most ^= *riter;
    *riter ^= *right_most;

    sort(riter.base(), perm.end());

    return true;
}

int main()
{
    int a[] = {1,3,2,4,5,6,7,8,9,10};
    int sz = sizeof(a)/sizeof(int);

    int p_count = 0;
    //vector< vector<int> > perms;    
    sort(a, a+sz);

    //for (int *iter = a; iter != a+sz; iter++)
        //cout << *iter << " ";
    //cout << endl;

    vector<int> last_perm(a, a+sz);
    //print_perm(last_perm);
    p_count++;

    while (next_perm(last_perm)) {
        //print_perm(last_perm);
        p_count++;
    }

    cout << "total: " << p_count << endl;
    return 0;
}
