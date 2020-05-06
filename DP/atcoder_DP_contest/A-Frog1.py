n = int(input())
a = list( map(int,input().split()) )
dp = [ 0 for i in range(n) ]
dp[0] = 0
if n==1:
    print(dp[0])
else:
    dp[1] = abs( a[1]-a[0])
    for i in range(2,n):
        dp[i] = min( dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]) )
    print(dp[n-1])
