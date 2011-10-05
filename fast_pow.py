
def pow1(base,exp):
    if exp == 0:
        return 1
    if exp & 1 == 0:
        t = pow1(base, exp/2)
        return t * t
    else:
        return base * pow1(base, exp-1)

def pow2_iter(r, base, exp):
    print '%s %s %s' % (r,base,exp)
    if exp == 0:
        return r
    if exp & 1 == 0:
        return pow2_iter(r, base*base, exp/2)
    else:
        return pow2_iter(r*base, base, exp-1)

def pow2(base, exp):
    return pow2_iter(1, base, exp)

if __name__ == '__main__':
    from time import time
    print time()
    print pow1(2,44444)
    print pow1(2,55555)
    print time()
    print time()
    print pow2(2,44444)
    print pow2(2,55555)
    print time()
