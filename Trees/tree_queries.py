n,q = map(int,input().split())
a = list( map(int,input().split()) )
s,lv = [],[]
l = 0
while True:
	start,end = 2**l-1,2**(l+1)-1
	if start >= n:
		break
	sumLevel = 0
	# print(start,end)
	curLv = []
	while start <n and start < end:
		sumLevel += a[start]
		curLv.append(a[start])
		start+=1
	s.append(sumLevel)
	lv.append(curLv)
	l += 1
# print(lv)
# print(s)
for z in range(q):
	inp = list( map(int,input().split()) )
	if inp[0] == 1:
		x,l = inp[1]-1,inp[2]-1
		print(lv[l][x])
	elif inp[0] == 2:
		start,end = inp[1]-1,inp[2]
		ans = 0
		for i in range(start,end):
			ans += s[i]
		print(ans)
	else:
		x,l,val = inp[1]-1,inp[2]-1,inp[3]
		s[l] -= lv[l][x]
		s[l] += val
		lv[l][x] = val


