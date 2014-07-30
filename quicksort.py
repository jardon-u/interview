import random
import time
import timeit

def is_sorted(l):
    for i in xrange(1, len(l)-1):
        if l[i] < l[i-1]:
            print i, ':', l[i], "<", l[i-1]
            return False
    return True

def quick_sort(l, i, j):
    if i >= j:
        return
    pivot = l[j]
    ipivot = i-1
    for k in xrange(i,j):
        if l[k] <= pivot:
            ipivot = ipivot + 1
            l[ipivot], l[k] = l[k], l[ipivot]
    ipivot = ipivot + 1
    l[ipivot], l[j] = l[j], l[ipivot]
    quick_sort(l, i, ipivot-1)
    quick_sort(l, ipivot+1, j)

l = [ random.randint(0,1000) for i in xrange(0,100000) ]

#l = [5,7,8,9,5,4,5,6,8,4,3,3]

t = time.time()
quick_sort(l, 0, len(l)-1)
print time.time() - t

t = time.time()
l.sort()
print time.time() - t

#print l
print is_sorted(l)

