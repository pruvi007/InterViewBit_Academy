def axes(a):
    n = len(a)
    l,r = 0,0
    for i in range(n):
        x,y = a[i][0],a[i][1]
        if (x<0 and y<=0) or (x<0 and y>=0):
            l+=1
        else:
            r+=1
    if l==0 or r==0:
        return "safe"
    if l==1 or r==1:
        return "safe"
    return "unsafe"

n = int(input())
a = []
for i in range(2):
    x = list( map(int,input().split()) )
    a.append(x)
ans = axes(a)
print(ans)
