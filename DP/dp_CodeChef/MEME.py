
def parent(par,x):
    while x!=par[x]:
        x = par[x]
    return x

def find(par,x,y):
    return parent(par,x) == parent(par,y)

def doUnion(par,size,x,y):
    if find(par,x,y):
        return
    p1,p2 = par[x],par[y]
    s1,s2 = size[p1],size[p2]
    if s1 > s2:
        par[p2] = p1
        size[p1] += s2
    else:
        par[p1] = p2
        size[p2] += s1
    return

dp = []
INF = 10**9
def solve(size_count,cost,pos,rem):
    if dp[pos][rem]!=-1:
        return dp[pos][rem]
    if rem <= 0:
        return 0
    if pos>=len(cost):
        return INF
    ans = INF
    a = solve( size_count,cost,pos+1,rem )
    b = cost[pos] + solve( size_count,cost,pos+1,rem-size_count[pos] )
    ans = min( ans,min(a,b) )
    dp[pos][rem] = ans
    return ans


n,m,k = map( int,input().split() )

par,size = [],[]
for i in range(n+1):
    par.append(i)
    size.append(1)
for i in range(m):
    x,y = map( int,input().split() )
    doUnion(par,size,x,y)
dp = [ [-1 for i in range(k+1)] for j in range(n+1) ]
s,M = set(),[INF for i in range(n+1)]
for i in range(1,n+1):
    s.add(par[i])
    M[par[i]] = min(M[par[i]],i)
# print(s)
# print(M)
size_count,cost = [],[]
for x in s:
    size_count.append(size[x])
    cost.append(M[x])
ans = solve(size_count,cost,0,k)
print(ans)
