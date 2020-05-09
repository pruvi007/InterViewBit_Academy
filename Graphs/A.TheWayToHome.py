from sys import stdin, stdout 
n,d = map(int,stdin.readline().split())
s = stdin.readline().split('\n')[0]
INF = 10**10
dp = [ INF for i in range(n) ]
dp[0] = 0
for i in range(n):
    if s[i]=='1':
        for j in range(i-1,max(i-d-1,-1),-1):
            if s[j]=='1':
                dp[i] = min(dp[j]+1,dp[i])
# print(dp)
ans = dp[n-1]
if dp[n-1]==INF:
    ans = -1
stdout.write("{}\n".format(ans))
