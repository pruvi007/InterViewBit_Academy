from sys import stdin, stdout
from collections import defaultdict

def getRoot(i,par):
    while i!=par[i]:
        i = par[i]
    return i

def find(a,b,par):
    return getRoot(a,par)==getRoot(b,par)

def doUnion(a,b,par,size):
    if find(a,b,par):
        return -1
    r1 = getRoot(a,par)
    r2 = getRoot(b,par)
    s1 = size[r1]
    s2 = size[r2]
    if s1 > s2:
        par[r2] = r1
        size[r1] += s2
    else:
        par[r1] = r2
        size[r2] += s1
    return 1

t = int(stdin.readline())
while t>0:
    n = int(stdin.readline())
    a = []
    for i in range(n):
        a.append( list(map(int,input().split())) )
    d = []
    for i in range(n):
        for j in range(n):
            if i!=j and a[i][j]>0:
                d.append( [a[i][j],i+1,j+1] )
    d = sorted(d)
    
    par = [ i+1 for i in range(n) ]
    par = [0] + par
    size = [ 1 for i in range(n)]
    size = [0] + size

    s = 0;
    for i in range(len(d)):
        x = doUnion(d[i][1],d[i][2],par,size);
        if x==1:
            s += d[i][0];
        
    stdout.write("{}\n".format(s))
    t-=1
