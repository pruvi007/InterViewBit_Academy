a = list( map(int,input().split()) )
n = len(a)
dp = [[0]*2]*n

dp[0][0],dp[0][1] = 1,1

for i in range(1,n):
    for j in range(0,i):
        d = a[i] - a[j]
        if d<0:
            dp[i][1] = max( dp[i][1],dp[j][0]+1 )
        elif d>0:
            dp[i][0] = max( dp[i][0],dp[j][1]+1 )
for r in dp:
    print(r)
