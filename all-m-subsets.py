
p = False

def all_m_subsets(m, n, prefix):
    #print
    #print "m = %s, n = %s, p = %s" % (m,n,prefix)
    global p
    if m == 0:
        print
        p = True
        return 

    if m == n:
        for i in prefix:
            print i,
        i = n-1
        while i >= 0:
            print i,
            i -= 1
        print
        return

    if p:
        for i in prefix:
            print i,
        p = False
    print n-1,
    prefix.append(n-1)

    all_m_subsets(m-1, n-1, prefix)
    if len(prefix):
        prefix.pop()
    #if len(prefix) == 0:
        #p = False

    all_m_subsets(m, n-1, prefix)


if __name__ == '__main__':
    m = 4
    n = 10
    print range(n)
    all_m_subsets(m,n,[])
