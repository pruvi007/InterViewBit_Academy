from sys import stdin,stdout
from collections import defaultdict
d,nbr = defaultdict(list),defaultdict(list)

# kahn's algorithm for topo sort
def topological(inDeg,n,d):
    q,topOrder = [],[]
    vis = [ False for i in range(n+1)]
    for i in range(1,n+1):
        if inDeg[i]==0:
            q.append(i)
            vis[i] = True
    while len(q)>0:
        top = q.pop(0)
        topOrder.append(top)
        for x in d[top]:
            inDeg[x]-=1
            if inDeg[x]==0:
                q.append(x)
                vis[x]=True
    return topOrder


n, m = map(int,stdin.readline().split())
E = []
inDeg = [ 0 for i in range(n+1)]
for i in range(m):
    x,y = map(int,stdin.readline().split())
    E.append([x,y])
    inDeg[y]+=1
    d[x].append(y)

order = topological(inDeg,n,d)
for k,v in zip(d.keys(),d.values()):
    for x in v:
        nbr[x].append(k)
# for k,v in zip(nbr.keys(),nbr.values()):
#     print(k,v)
dp = [ 0 for i in range(n+1) ]
for x in order:
    if len(nbr[x])>0:
        for near in nbr[x]:
            dp[x] = max(dp[x],dp[near]+1)

print(max(dp))
