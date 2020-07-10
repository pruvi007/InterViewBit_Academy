'''
    handle - pruvi007
    questionName - 
    Contest - 
    Topic - 
    Platform - 
'''
from sys import stdin, stdout
from collections import defaultdict

def BS(a,x,low,high,k):
    ans = -1
    while low<=high:
        mid = (low+high)//2
        d = a[mid]-x
        if d<=k:
            ans = mid
            low = mid+1
        else:
            high = mid-1
    return ans

def getSmall(a,mid):
    c = 0
    for i in range(len(a)):
        right = BS(a,a[i],i+1,len(a)-1,mid)
        # print(a[i],right)
        if right!=-1:
            c += right - i
    return c
def main():
    n,k = map(int,stdin.readline().split())
    a = list( map(int,stdin.readline().split()) )
    a = sorted(a)
    # max difference
    high = a[n-1]-a[0]
    # min difference
    low = a[n-1]
    for i in range(1,n):
        d = a[i]-a[i-1]
        low = min(low,d)
    # print(a)
    ans = -1
    while low<=high:
        mid = (low+high)//2
        # print("mid: ",mid)
        small = getSmall(a,mid)
        # print(small)
        if small<k:
            low = mid+1
        else:
            ans = mid
            high = mid-1
    stdout.write("{}\n".format(ans))
    

main()