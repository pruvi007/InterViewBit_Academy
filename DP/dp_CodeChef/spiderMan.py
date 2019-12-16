# this returns list of indices from where it can reach to index j
def getPowerIndices(j):
	l,k = [],0
	j = j-1
	while j>0:
		l.append(j)
		k += 1
		j = i - 2**k
	return l

INF = 10**18
n = int(input())
a = list( map(int,input().split()) )
dp = [INF]*(n+1)

# if only 1 building would have been there
dp[1] = 0
for i in range(2,n+1):
	ind = getPowerIndices(i)
	M,Mi = INF,0
	# take the minimum from all possible positions
	for x in ind:
		dp[i] = min(dp[i],dp[x] + abs(a[i-1]-a[x-1]))
print(dp[n])


