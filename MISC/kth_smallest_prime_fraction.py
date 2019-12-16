import heapq

def kth_smallest(a,n,k):
	q = []
	
	for i in range(1,n):
		heapq.heappush(q,(a[0]/a[i],0,i) )
	
	

	c = 0
	ans = []
	while len(q)>0:
		x = heapq.heappop(q)
		c+=1
		print(x)
		if c==k:
			ans = [a[x[1]],a[x[2]]]
			break
		val = a[x[1]+1]/a[x[2]]
		heapq.heappush( q,(val,x[1]+1,x[2]) )
	return ans




n,k = map(int,input().split())
a = list( map(int,input().split()) )

ans = kth_smallest(a,n,k)
print(ans)