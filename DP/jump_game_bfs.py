
INF = 10**6 + 1
n = int(input())
a = list( map(int,input().split()) )
q = []
# any tuple in queue holds info - (jump distance, currInd, minDistanceToReachThatCell)
q.append( [a[0],0,0] )
vis = [ False for i in range(n) ]
vis[0] = True
while len(q)>0:
    x = q.pop(0)
    jump,cur,d = x[0],x[1],x[2]
    if cur >= n-1:
        print(d)
        break
    for i in range(cur+1,cur+jump+1):
        if i>=n:
            break
        if vis[i]==False:
            q.append( [a[i],i,d+1] )
            vis[i] = True
