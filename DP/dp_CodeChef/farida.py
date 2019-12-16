t = int(input())
for z in range(t):
	n = int(input())
	a = list( map(int,input().split()) )
	dp = [0]*n
	if n==1:
		print("Case {}: {}".format(z+1,a[0]) )
	else:
		dp[0] = a[0]
		dp[1] = max(a[0],a[1])
		for i in range(2,n):
			dp[i] = max( dp[i-1],dp[i-2]+a[i] )

		print("Case {}: {}".format(z+1,dp[n-1]) )
	
