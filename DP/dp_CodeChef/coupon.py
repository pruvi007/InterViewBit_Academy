t = int(input())
INF = 10**20
while t>0:
	n,m = map( int,input().split() )
	price,discount = [],[]
	for i in range(n):
		price.append([])
		discount.append([])
	for i in range(n):
		l = list( map(int,input().split()) )
		price[i] = (l)
	for i in range(n):
		l = list( map(int,input().split()) )
		discount[i] = (l)
	# print(price)
	# print(discount)
	dp = [[0]*m]*n
	# print(dp)

	# if only 1 itme to be bought then that would be min of all the prices
	ans = min(price[0])
	for i in range(m):
		val = (price[0][i])
		dp[0][i] = val

	
	for i in range(1,n):
		ans2 = INF
		for j in range(m):
			val = (price[i][j]-discount[i-1][j]) if  price[i][j]-discount[i-1][j]>= 0 else 0 
			dp[i][j] = min( dp[i-1][j]+val,ans+price[i][j] )
			ans2 = min(ans2,dp[i][j])
		ans = ans2
	M = dp[n-1][0]
	for r in dp:
		x = min(r)
		M = min(x,M)
	print(M)

	t-=1
