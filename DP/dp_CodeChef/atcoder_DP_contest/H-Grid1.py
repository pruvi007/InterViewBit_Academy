from sys import stdin,stdout

n,m = map(int,stdin.readline().split())
grid = []
for i in range(n):
    row = input()
    grid.append(row)
dp = [ [0 for j in range(m)] for i in range(n) ]
for i in range(m):
    if grid[0][i]=='#':
        break
    dp[0][i] = 1
for i in range(n):
    if grid[i][0]=='#':
        break
    dp[i][0] = 1
for i in range(1,n):
    for j in range(1,m):
        if grid[i][j]=='#':
            dp[i][j] = 0
        else:
            dp[i][j] = dp[i-1][j] + dp[i][j-1]
        dp[i][j] %= 10**9+7
print(dp[n-1][m-1])
