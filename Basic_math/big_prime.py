def prime(x):
	import math
	for i in range(2, int(math.sqrt(x))+1 ):
		if x%i==0:
			return False
	return True

m = 10000001
M = 100000001
flag = [0]*M
for i in range(2,M):
	l = 2
	if flag[i]==0:
		while i*l <= M:
			flag[i*l] = 1
			l += 1
prime = []
for i in range(2,M):
	if flag[i] == 0:
		prime.append(i)
		print(i,end=' ')
print(len(prime))
