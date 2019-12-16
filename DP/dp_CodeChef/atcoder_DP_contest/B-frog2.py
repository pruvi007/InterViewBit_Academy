from sys import stdin, stdout

n,k = map(int,stdin.readline().split())
a = list( map(int,stdin.readline().split() ) )
INF = 10**10
dp = [ INF for i in range(n) ]
dp[0] = 0
if n==1:
    stdout.write(str(dp[0]))
else:
    dp[1] = abs(a[1]-a[0])
    for i in range(2,n):
        j = i-1
        M = INF
        while j>=(i-k):
            if j<0:
                break
            dp[i] = min( dp[i],dp[j]+abs(a[i]-a[j]) )
            j-=1

    stdout.write(str(dp[n-1]))
