# In-place counting sort.

def countingsort(seq, k):
    """In-place counting sort.

    """
    c = [0] * k
    sn = len(seq)

    for i in range(sn):
        c[seq[i]] += 1

    ac = c[:]
    for i in range(1,k):
        ac[i] += ac[i-1]

    act = ac[:]
    i = sn - 1
    while i >= 0:
        elem = seq[i]
        # 该区间为排好序的序列中elem及所有相等的元素所处的位置
        if ac[elem] - c[elem] <= i <= ac[elem] - 1:
            act[elem] -= 1
            i -= 1
            continue
        # 交换两元素，在下一次循环继续检查该位置 
        seq[i] = seq[act[elem]-1]
        seq[act[elem]-1] = elem
        act[elem] -= 1

# test
if __name__ == '__main__':
    from random import randrange
    k = 25
    n = 30
    testinput = [randrange(k) for x in range(n)]

    countingsort(testinput, k)
    assert testinput == sorted(testinput)
