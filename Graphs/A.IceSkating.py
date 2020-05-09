from sys import stdin, stdout

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

n = int(stdin.readline())
points = []
l = 1
for i in range(n):
    x, y = map(int,stdin.readline().split())
    points.append( [x,y,l] )
    l+=1
par = [i for i in range(n+1)]
size = [1 for i in range(n+1)]

for i in range(n-1):
    for j in range(i+1,n):
        x1,y1 = points[i][0],points[i][1]
        x2,y2 = points[j][0],points[j][1]
        if x1==x2 or y1==y2:
            poss = doUnion(points[i][2],points[j][2],par,size)
comp = {}
for i in range(1,n+1):
    p = getRoot(i,par)
    comp[p] = 1
# print(comp)
stdout.write("{}\n".format(len(comp)-1))
