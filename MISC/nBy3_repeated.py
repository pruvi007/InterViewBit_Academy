import sys
def majority2(a):
	c1,c2 = 0,0
	first,second = float("inf"),float("inf")

	# for n/3 repeated number find two candidates (by moore voting process)
	# then check each candidate individually (if they are the n/3 repeated candidate)
	for i in range(len(a)):
		if a[i] == first:
			c1+=1
		elif a[i] == second:
			c2+=1
		elif c1==0:
			first = a[i];
			c1 = 1
		elif c2==0:
			second = a[i]
			c2 = 1
		else:
			c1-=1
			c2-=1

	c1,c2 = 0,0
	for x in a:
		if x == first:
			c1+=1
		elif x==second:
			c2+=1
	if c1 > len(a)/3:
		return first
	elif c2 > len(a)/3:
		return second
	return -1

n = int(input())
a = list(map(int,input().split()))
ans = majority2(a)
print(ans)
