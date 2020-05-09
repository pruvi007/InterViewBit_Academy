from sys import stdin, stdout
n,t = map(int,stdin.readline().split())
a = list( map(int,stdin.readline().split()) )
start = 0
ans = "NO"
while start<=n:
    if start == t-1:
        ans = "YES"
        break
    if start<n-1:
        start += a[start]
    else:
        break

stdout.write("{}\n".format(ans))
