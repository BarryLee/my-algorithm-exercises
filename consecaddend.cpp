#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector< vector<int> > consecaddend(int n)
{
    vector< vector<int> > vec;
    vector<int> iv;
    int i, j;

    for (i = 2; ((j = n/i) > i/2) || (j == i/2) && (i%2 == 0); i++)
        if (i%2) {
            if (n%i == 0) {
                j -= i/2;
                for (int k = 0; k != i; ++k)
                    iv.push_back(j++);
                vec.push_back(iv);
                iv.clear();
            }

        } else {
            if (n%i != 0 && 2*n%i == 0) {
                j -= i/2 - 1;
                for (int k = 0; k != i; ++k)
                    iv.push_back(j++); 
                vec.push_back(iv);
                iv.clear();
                //if (n/i == i/2) break;
            }
        }

    return vec;
}

int main(void)
{
    int x;
    vector< vector<int> > v;
    while (cin >> x) {
        v = consecaddend(x);
        for(vector< vector<int> >::iterator viter = v.begin(); viter != v.end(); ++viter) {
            for(vector<int>::iterator iter = viter->begin(); iter != viter->end(); ++iter)
                cout << *iter << " ";
            cout << endl;
        }
        v.clear();
    }

    return 0;
}
