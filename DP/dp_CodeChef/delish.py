t = int(input())
while t>0:
    n = int(input())
    a = list( map(int,input().split()) )
    l,r = [0]*n,[0]*n
    l[0],r[n-1]=a[0],a[n-1]
    for i in range(1,n):
        l[i] = l[i-1]+a[i]
    for i in range(n-2,-1,-1):
        r[i] = r[i+1]+a[i]
    # print(l)
    # print(r)
    m = 0
    for i in range(1,n):
        d = abs(r[i]-l[i-1])
        m = max(m,d)
    print(m)
    t-=1
