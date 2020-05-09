t = int(input())
while t>0:
    n,k = map(int,input().split())
    a = []
    poss = True
    d = {}
    for i in range(1,n+1):
        p1,p2 = i+k,i-k
        ans = 0
        if 0<p1<=n and 0<p2<=n:
            if p1<p2 and p1 not in d:
                ans = p1
                d[p1] = 1
            elif p2 not in d:
                ans = p2
                d[p2] = 1
        elif 0<p1<=n and p1 not in d:
            ans = p1
            d[p1] = 1
        elif 0<p2<=n and p2 not in d: 
            ans = p2
            d[p2] = 1
        else:
            poss = False
        a.append(ans)
    print(d)
    if poss:
        print(' '.join( [str(x) for x in a] ))
    else:
        print(-1)
    t-=1


'''
10
10 0
10 1
7 0
10 9
9 0
10 3
8 2
8 0
7 0
10 1

1 2 3 4 5 6 7 8 9 10
2 1 4 3 6 5 8 7 10 9
1 2 3 4 5 6 7
-1
1 2 3 4 5 6 7 8 9
-1
3 4 1 2 7 8 5 6
1 2 3 4 5 6 7 8
1 2 3 4 5 6 7
2 1 4 3 6 5 8 7 10 9
'''