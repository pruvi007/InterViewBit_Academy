from sys import stdin,stdout

n = int(stdin.readline())
a = list( map(float,stdin.readline().split()) )

"""
state dp[i][j] -> probability of i heads among first j coins
case 1 - the current coin is Head
we need i-1 heads from j-1 coins
case 2 - the current coin is Tail
we need i heads from j-1 coins
"""
dp = [ [0 for j in range(n+1)] for i in range(n+1)]
dp[0][0] = 1

for i in range(1,n+1):
    dp[0][i] = (1-a[i-1])*dp[0][i-1]
for i in range(1,n+1):
    head,tail = a[i-1],1-a[i-1]
    for n_heads in range(1,i+1):
        dp[n_heads][i] = head*dp[n_heads-1][i-1] + tail*dp[n_heads][i-1]

for r in dp:
    print(r)
ans = 0
for i in range(n//2+1,n+1):
    ans += dp[i][n]
print(ans)
