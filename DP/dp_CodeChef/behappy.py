def solve(a,level,rem):
	if level==len(a):
		if rem==0:
			return 1
		return 0
	s = 0
	for i in range(a[level][0],a[level][1]+1):
		if rem>0:
			s += solve(a,level+1,rem-i)
	return s
n,t = map( int,input().split() )
a = []
for i in range(n):
	l,r = map( int,input().split() )
	a.append([l,r])
ans = solve(a,0,t)
print(ans)
