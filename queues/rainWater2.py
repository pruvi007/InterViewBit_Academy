
import heapq

def safe(n,m,r,c,visit):
	return 0<=r<=n-1 and 0<=c<=m-1 and (r,c) not in visit

def trapWater2(a):
	n,m = len(a),len(a[0])
	heap, visit = [],set()

	# now insert border elements inside the heap
	# 1st row and last row
	for i in range(m):
		heap.append( (a[0][i],0,i) )
		visit.add( (0,i) )
	for i in range(m):
		heap.append( (a[n-1][i],n-1,i) )
		visit.add( (n-1,i) )

	# 1st column and last column
	for i in range(n):
		heap.append( (a[i][0],i,0) )
		visit.add( (i,0) )
	for i in range(n):
		heap.append( (a[i][m-1],i,m-1) )
		visit.add( (i,m-1) )

	# print(heap)
	# start bfs with heapq
	heapq.heapify(heap)
	d = [ [0,1],[0,-1],[1,0],[-1,0] ]
	ans = 0
	while heap:
		h,x,y = heapq.heappop(heap)
		for dx,dy in d:
			r = x + dx
			c = y + dy
			# if the new cell is valid
			if safe(n,m,r,c,visit):
				# if h is greater than the current cell then add diff to ans and push the greater cell back again
				ans = ans  + max(0, h-a[r][c])
				new_item = ( max(h,a[r][c]),r,c )
				heapq.heappush(heap,new_item)
				visit.add((r,c))
	return ans



n,m = map(int,input().split())
a = []
for i in range(n):
	a.append( list(map(int,input().split())) )
water = trapWater2(a)
print(water)

