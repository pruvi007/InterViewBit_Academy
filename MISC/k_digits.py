def smallest(a,k,res):
	if k==0:
		res.append(a)
		return
	l = len(a)
	if l<=k:
		return
	m = 0
	for i in range(1,k+1):
		if a[i]<a[m]:
			m = i
	res.append(a[m])
	new_a = [ a[i] for i in range(m+1,len(a)-m)]
	smallest(new_a,k-m,res)

a = input()
k = int(input())
res = []
a = [ a[i] for i in range(len(a))]
smallest(a,k,res)
print(res)
