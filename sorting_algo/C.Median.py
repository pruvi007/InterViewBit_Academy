

n, med = map( int,input().split() )
a = list( map(int,input().split()) )
s,l = 0,0
present = False
for i in range(n):
    if a[i]==med:
        present = True
        break
ans = 0
if not present:
    a = a + [med]
    ans += 1
a = sorted(a)
m,M = 1,10**5+1
curMed = a[(len(a)+1)//2 - 1]
if curMed == med:
    print(ans)
else:
    if curMed<med:
        while curMed<med:
            a = a + [M]
            
            curMed = a[(len(a)+1)//2 - 1]
            ans += 1
    else:
        while curMed>med:
            a = [1]+a
            curMed = a[(len(a)+1)//2 - 1]
            ans += 1
    # print(a)
    print(ans)



'''
5 3
1 2 3 4 5
4 3
1 2 4 5
5 5
1 2 3 4 5
3 10
10 20 30
3 4
1 2 3
2 4
1 2
'''

'''
0
1
4
1
4
3
'''