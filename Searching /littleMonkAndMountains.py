'''
    handle - pruvi007
    questionName - 
    Contest - 
    Topic - 
    Platform - 
'''
from sys import stdin, stdout
from collections import defaultdict

def main():
    n,q = map(int,stdin.readline().split())
    a = []
    for i in range(n):
        l,r = map(int,stdin.readline().split())
        a.append([l,r])
    a = sorted(a)
    dp = [0 for i in range(n)]
    dp[0] = a[0][1]-a[0][0]+1
    for i in range(1,n):
        dp[i] = dp[i-1] + (a[i][1]-a[i][0]+1)
    # print(dp)
    v = [[a[0][0],dp[0]]]
    for i in range(1,n):
        v.append( [dp[i-1],dp[i]] )
    # print(v)
    for i in range(q):
        x = int(stdin.readline())
        low,high = 0,n-1
        block = -1
        while low<=high:
            mid = (low+high)//2
            if v[mid][0]<=x and v[mid][1]>=x :
                block = mid
                break
            elif v[mid][0]< x and v[mid][1]<x:
                low = mid+1
            else:
                high = mid-1
        # print(x,block)
        if x<=dp[0]:
            stdout.write("{}\n".format(a[0][0]+x-1))
        else:
            rem = abs(x-dp[block-1])
            ans = a[block][0]+rem-1
            stdout.write("{}\n".format(ans))
    

main()