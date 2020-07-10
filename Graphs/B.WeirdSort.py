from sys import stdin, stdout
t = int(stdin.readline())

def getRoot(i,par):
    while i!=par[i]:
        i = par[i]
    return i

def find(a,b,par):
    return getRoot(a,par)==getRoot(b,par)

def doUnion(a,b,par,size):
    if find(a,b,par):
        return False
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
    return True

while t>0:
    n,p = map(int,stdin.readline().split())
    a = list( map(int,stdin.readline().split()) )
    pos = list( map(int,stdin.readline().split()) )
    A = [ [a[i],i+1] for i in range(n) ]
    par = [ i for i in range(101)]
    size = [1 for i in range(101)]
    for i in range(p):
        x,y = pos[i],pos[i]+1
        doUnion( x,y,par,size )
    sort = "YES"
    b = sorted(A)
    for i in range(n):
        x,y = A[i][1],b[i][1]
        if not find(x,y,par):
            sort = "NO"
            break
    stdout.write("{}\n".format(sort))
    t-=1