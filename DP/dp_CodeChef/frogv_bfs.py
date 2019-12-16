def findThem(a,cur,k):
    l = []
    for i in range(len(a)):
        if abs(cur-a[i][0])<=k and cur-a[i][0]!=0:
            l.append(a[i][1])
    return l

def bfs(a,x,y,k):
    q = []
    q.append(a[x-1])
    vis = [False]*len(a)
    vis[x-1] = True
    while len(q)>0:
        top = q.pop(0)
        if top[1] == y:
            return "Yes"
        possibleFrogs = findThem(a,top[0],k)
        for pos in possibleFrogs:
            if vis[pos-1]==False:
                q.append(a[pos-1])
                vis[pos-1] = True
    return "No"



n,k,p = map(int,input().split())
a = list( map(int,input().split()) )
frog = [ [a[i],i+1] for i in range(len(a)) ]
frog = sorted(frog)
# print(frog)

for i in range(p):
    x,y = map(int,input().split())
    ans = bfs(frog,x,y,k)
    print(ans)
