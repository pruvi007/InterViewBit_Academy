
def getMaxSubString(s,t):
	n,m = len(s),len(t)
	low,high=1,n

	while low<=high:
		mid = (low+high)//2
		valid1 = isSubsequence(s,0,)
		valid2 = isSubsequence(s,mid,n-1,t)
		for i in range()



s = input()
t = input()
ans = getMaxSubString(s,t)