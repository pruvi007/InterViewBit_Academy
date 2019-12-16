def find(a,x):
	l,r = 0,len(a)-1
	ans = -1
	# print(a)
	while l<=r:
		mid = (l+r)//2
		if a[mid] >= x:
			ans = a[mid]
			r = mid-1
		else:
			l = mid+1
	return ans

def levelOrder(adj,src,n,value):
	level,sorted_level = 0,[]
	temp = [(src,level)]
	vis = [0 for i in range(0,n+1)]
	vis[src] = 1

	while len(temp)>0:
		size = len(temp)
		local_level = []
		for i in range(size):
			x = temp.pop(0)
			vis[x[0]] = 1
			ind = x[0]-1

			local_level.append(value[x[0]-1])

			val,l = x[0],x[1]
			for i in range(len(adj[val])):
				# print(adj[val][i])
				if vis[adj[val][i]] == 0:
					temp.append((adj[val][i],l+1))
		sorted_level.append(sorted(local_level))
		# print()
	return sorted_level

n,m = map(int,input().split())
adj = [[] for i in range(n+1)]
edge = []
for i in range(m):
	x,y = map(int,input().split())
	adj[x].append(y)
	adj[y].append(x)
val = list( map(int,input().split()) )

# print(adj)
sorted_level = levelOrder(adj,1,n,val)
print(sorted_level)
h = len(sorted_level)
q = int(input())
answer = []
for i in range(q):
	l,x = map(int,input().split())
	level = l%(h+1)
	ans = find(sorted_level[level],x)
	answer.apped(ans)
print(ans)




