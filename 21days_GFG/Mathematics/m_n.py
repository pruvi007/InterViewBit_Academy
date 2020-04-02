t = int(input())
while t>0:
    m,n = map(int,input().split())
    x = m+n
    if len(str(x))==len(str(n)):
        print(n)
    else:
        print(x)
    t-=1