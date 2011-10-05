#include "big_num.h"
#include <iostream>

using namespace std;

const int B = 10000;

Big_num 
pow(Big_num a, Big_num base, int n)
{
    if (n == 0)
        return a;
    //if (n == 1)
        //return a;
    if (n % 2)
        return pow(a*base, base, n-1);
    else
        return pow(a, base * base, n/2);
}

Big_num
fac(int x)
{
    Big_num r(1, B);
    while (x != 1) 
        r *= Big_num(x--, B);

    return r;
}

int main()
{
    //string snum, snum2;
    //long lnum;
    //int inum;

    //cin >> snum;
    //Big_num sbn(snum, B);
    ////cout << sbn.length << " "
        ////<< sbn.digit_per_slot << " "
        ////<< endl;
    ////for (int i = 0; i != sbn.length; i++)
        ////cout << sbn.a[i];
    ////cout << endl;
    //cout << sbn << endl;

    //cin >> snum2;
    //Big_num sbn2(snum2, B);
    //cout << sbn2 << endl;

    //sbn *= sbn2;
    //cout << sbn << endl;
    //cout << sbn * sbn2 << endl;
    //cout << sbn << endl;

    cout << pow(Big_num(1,B), Big_num(2,B), 32) << endl;
    Big_num f = fac(10000);
    //for (int i = 0; i < 9; i++)
        //cout << f.a[i] << " ";
    //cout << endl << f << endl;

    return 0;
}   
