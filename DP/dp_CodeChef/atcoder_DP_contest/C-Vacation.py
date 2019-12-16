from sys import stdin,stdout

n = int(stdin.readline())
a = []
for i in range(n):
    x,y,z = map(int,stdin.readline().split())
    a.append([x,y,z])
dp = [[0,0,0] for i in range(n)]
dp[0] =  [a[0][0],a[0][1],a[0][2]] 
for i in range(1,n):
    dp[i][0] = a[i][0] + max( dp[i-1][1],dp[i-1][2] )
    dp[i][1] = a[i][1] + max( dp[i-1][0],dp[i-1][2] )
    dp[i][2] = a[i][2] + max( dp[i-1][0],dp[i-1][1] )
ans = max(dp[n-1])
stdout.write(str(ans))
