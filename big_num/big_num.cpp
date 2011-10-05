#include "big_num.h"
#include <stdexcept>
#include <iostream>

using std::string;
using std::ostream;

void
Big_num::init(int _base)
{
    for (int i = 0; i != MAXD; i++) 
        a[i] = 0; 

    for (; _base > 1; _base /= 10, digit_per_slot++)
        if (_base % 10)
            throw std::runtime_error("base must be power of 10");
}

Big_num::Big_num(int _base): base(_base), length(0), digit_per_slot(0), sign(1)
{ 
    init(_base);
    //for (int i = 0; i != MAXD; i++) 
        //a[i] = 0; 

    //for (; _base; _base /= 10, digit_per_slot++)
        //if (_base % 10)
            //throw std::runtime_error("base must be power of 10");
}

Big_num::Big_num(long x, int _base): base(_base), length(0), digit_per_slot(0), sign(1) 
{
    //Big_num(_base);
    init(_base);
    if (x < 0) sign = -1, x = -x;
    while (x) {
        a[length++] = x % base;
        x /= base;
    }
}

Big_num::Big_num(const string &s, int _base): base(_base), length(0), digit_per_slot(0), sign(1) 
{
    //Big_num(_base);
    init(_base);
    int high_idx = 0;
    if (s[0] == '-') 
        sign = -1, high_idx = 1;

    for (int i = s.size()-1; i >= high_idx; i-=digit_per_slot) {
        int j = i-digit_per_slot+1;
        j = j >= high_idx ? j : high_idx;

        int tmp = 0;
        for (; i >= j; j++)
            tmp = 10 * tmp + (s[j]-'0');
        a[length++] = tmp;
    }
}

Big_num& Big_num::add(const Big_num &y)
{
    int carry = 0,
        i = 0;
    for (; i != y.length; i++) {
        int tmp = a[i] + y.a[i] + carry;
        a[i] = tmp % base;
        carry = tmp / base;
    }
    while (carry) {
        int tmp = a[i] + carry;
        a[i++] = tmp % base;
        carry = tmp / base;
    }
    length = i;
    return *this;
}

Big_num& Big_num::mul(const Big_num &y)
{
    *this = *this * y;
    return *this;
    //if (length < y.length) {
        //Big_num nb(y);
        //nb.mul(*this);
        //*this = nb;
        //return *this;
    //}

    //int carry = 0;
    //Big_num nb(base);

    //for (int i = 0; i != y.length; i++) {
        //int j = 0;
        //for (; j != length; j++) {
            //int tmp = y.a[i] * a[j] + carry + nb.a[i+j];
            //nb.a[i+j] = tmp % base;
            //carry = tmp / base;
        //}
        //while (carry) {
            //nb.a[i+j++] = carry;
            //carry /= base;
        //}
        //nb.length = i+j;
    //}
    //*this = nb;

    //return *this;
}

ostream&
Big_num::display(ostream &os) const
{
    if (sign < 0)
        os << '-';

    int i = length - 1;
    os << a[i--];

    for (; i >= 0; i--) {
        int j = digit_per_slot-1;
        for (int the_num = a[i]/10; the_num; the_num /= 10, j--)
            ;
        for (; j != 0; j--)
            os << '0';
        os << a[i];
    }

    return os;
}

ostream&
operator<<(ostream &os, const Big_num &n)
{
    return n.display(os);
}

//Big_num&
//Big_num::operator=(const Big_num &n)
//{
    //if (this == &n)
        //return *this;
//}

Big_num&
Big_num::operator+=(const Big_num &y)
{
    return add(y);
}

Big_num
operator+(const Big_num &x, const Big_num &y)
{
    Big_num nb(x);
    nb.add(y);
    return nb;
}

Big_num
operator*(const Big_num &x, const Big_num &y)
{
    if (x.base != y.base) {
        std::cerr << x.base << " " << y.base << std::endl;
        throw std::runtime_error("different base");
    }

    int i, j, carry = 0, base = x.base;

    Big_num nb(base);
    if (x.sign == y.sign)
        nb.sign = 1;
    else
        nb.sign = -1;

    for (i = 0; i != y.length; i++) {
        for (j = 0; j != x.length; j++) {
            int tmp = y.a[i] * x.a[j] + carry + nb.a[i+j];
            nb.a[i+j] = tmp % base;
            carry = tmp / base;
        }
        //while (carry) {
            //nb.a[i+j++] = carry;
            //carry /= base;
        //}
        if (carry) {
            nb.a[i+j] = carry;
            carry = 0;
        }
    }
    for (i = x.length + y.length; nb.a[i] == 0; i--)
        ;
    nb.length = i+1;

    return nb;
}
    
Big_num&
Big_num::operator*=(const Big_num &y)
{
    //*this = *this * y;
    //return *this;
    return mul(y);
}

