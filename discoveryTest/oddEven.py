def oddEven(a):
    odd,even=0,0
    o,e=0,0
    n = len(a)
    for i in range(n):
        if o==0:
            if a[i]%2:
                odd+=1
                o=1
        else:
            if a[i]%2==0:
                o=0
                odd+=1

    for i in range(n):
        if e==0:
            if a[i]%2==0:
                even+=1
                e=1
        else:
            if a[i]%2:
                e=0
                even+=1

    return max(odd,even)

a = list(map(int,input().split()))
ans = oddEven(a)
print(ans)
