mod  = 10**9 + 7
def subarrayOR(a):
	n = len(a)
	ans = 0
	# find the contribution of ith bit
	for i in range(32):
		bits = []
		for j in range(n):
			b = a[j] >> i
			if not(b&1):
				bits.append(j)

		total = (n*(n+1))/2
		remove,s = 0,1
		for j in range(1,len(bits)):
			if bits[j]-bits[j-1]==1 :
				s += 1
			else:
				remove += (s*(s+1))/2
				s = 1
		remove += (s*(s+1))/2
		if len(bits)==0:
			remove = 0
		total = total - remove
		ans += 2**i * total
		ans %= mod
	return ans%mod

a = list( map(int,input().split()) )
ans = subarrayOR(a)
print(int(ans))