n = int(input())
a = list( map(int,input().split()) )
a = sorted(a)
ans = 0
for i in range(n):
    ans += abs(i+1 - a[i])
print(ans)