n = int(input())
a = list( map(int,input().split()) )
INF = 10**5+1
c = [ 0 for i in range(INF) ]
for i in range(n):
    c[a[i]] += 1
cnt = []
for i in range(INF):
    if c[i]>0:
        cnt.append([c[i],i])
print(cnt)
dp = []
dp[0],dp[1] = 0,cnt[0]
for i in range(2,len(cnt)):
    dp[i] = max( dp[i-1],cnt[i-1]+dp[i-2] )
print(dp[len(cnt)-1])
