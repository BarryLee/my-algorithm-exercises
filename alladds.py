
def alladds(n, prefix):
    if len(prefix) and str(n) >= prefix[-1]:
        print '%d +' % n,
        print ' + '.join(prefix)

    for i in range(1, n):
        if len(prefix) and str(i) < prefix[-1]:
            continue
        prefix.append(str(i))
        alladds(n-i, prefix)
        prefix.pop()

if __name__ == '__main__':
    alladds(5, [])
