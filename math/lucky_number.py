#!/bin/python3
import sys

# https://www.geeksforgeeks.org/lucky-numbers/ -> has mistake in algorithm:
# it removes each 2nd, each 3rd, each 4th, each 5th but
# must remove each Xth there Xth first not crossed element in previous iteration


def isLuckyNumber(n):
    #
    if n==1:
        return True
    if n&1==0:
        return False

    sieve  =list(range(1,n+1,2))
    idx=1
    while idx<len(sieve):
        m=sieve[idx]
        if m>len(sieve):
            break
        #last is n
        if len(sieve)%m==0:
            return False
        sieve=[v for i,v in enumerate(sieve) if (i+1)%m!=0]
        idx+=1
    return True

def getLuckyNumbers(nmax):
    #
    if nmax<3:
        return [1]

    sieve  =list(range(1,nmax+1,2))
    idx=1
    while idx<len(sieve):
        m=sieve[idx]
        if m>len(sieve):
            break
        sieve=[v for i,v in enumerate(sieve) if (i+1)%m!=0]
        idx+=1
    return sieve

# Driver Code 
if __name__ == "__main__":
    print([i for i in range(1,100) if isLuckyNumber(i)])
    print(getLuckyNumbers(100))