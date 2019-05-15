s = input()

L = len(s)
# print(L)
l = 0
r=0
f = []
size = 125
for i in range(size):
    f.append(0)
    
# print(L)
f[ord(s[0])%size] += 1
ans = -1
# print(L)
while l<=r and r<L :
	flag = 0;
	for i in range(size):
		if f[i]>1:
			flag=1
			break
	if flag==1:
		f[ord(s[l])%size] -= 1
		l+=1
		if l>r:
		    break
	else:
		if (r-l+1)>ans:
			ans = r-l+1
		r+=1
		if r==L:
		    break;
		f[ord(s[r])%size] += 1
# 	print(ans)
print(ans)