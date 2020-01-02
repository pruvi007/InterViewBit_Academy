n,k = map(int,input().split())
s = input()
av = input().split()
ns = [ s[i] for i in range(len(s)) ]
for i in range(len(ns)):
    if ns[i] in av:
        ns[i] = 1
    else:
        ns[i] = 0
# print(ns)
c = 0
ans = 0
for i in range(len(ns)):
    if ns[i]==1:
        c+=1
    else:
        ans += c*(c+1)//2
        c = 0
ans += c*(c+1)//2
print(ans)