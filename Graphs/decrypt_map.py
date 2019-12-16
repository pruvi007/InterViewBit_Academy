def dfs(x,vis,edge):
	vis[x] = 1
	print(x,end=' ')
	for i in range(len(edge[x])):
		if vis[ edge[x][i] ] == 0:
			dfs(edge[x][i],vis,edge)

n = int(input())
edge = [[] for i in range(n+1)]
for i in range(n-1):
	x,y = map(int,input().split())
	edge[x].append(y)

score = []
for i in range(1,n+1):
	vis = [0]*(n+1)
	dfs(i,vis,edge)
	c = 0
	for j in range(i+1,n+1):
		if vis[j] == 0:
			dfs(j,vis,edge)
			c += 1
	for j in range(i-1,0,-1):
		if vis[j] == 0:
			dfs(j,vis,edge)
			c += 1
	score.append([c,i])
	print()
print(sorted(score))
m = sorted(score)[0][0]
ans = []
for i in range(len(score)):
	if score[i][0] == m:
		ans.append(score[i][1])
print(ans)