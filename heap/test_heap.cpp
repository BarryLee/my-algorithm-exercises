#include "heap.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n, m;
    cout << "size: ";
    do {
        cin >> n;
    } while (!cin);
    cout << "max: ";
    do {
        cin >> m;
    } while (!cin);

    vector<int> vec;
    srand( (unsigned int)time(NULL) );
    for (int i=0; i != n; i++) {
        vec.push_back(rand()%m);   
    }

    for (vector<int>::iterator iter = vec.begin();
            iter != vec.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}
