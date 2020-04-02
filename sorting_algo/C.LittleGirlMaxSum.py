from sys import stdin, stdout  


'''
find the frequency of each index then assign greedily to each index
then perform the prefix sum

using stdin and stdout for fast I/O
'''

n, q = map(int,stdin.readline().split())
a = list( map(int,stdin.readline().split()) )
v = []
for i in range(n):
    v.append([0,i])
queries = []
for i in range(q):
    l,r = map(int,stdin.readline().split())
    queries.append([l,r])
    l= l-1
    v[l][0] += 1
    if r<n:
        v[r][0] -= 1
for i in range(1,n):
    v[i][0] += v[i-1][0]

mod_a = [ 0 for i in range(n) ]
v = sorted(v,reverse=True)
a = sorted(a,reverse=True)
# print(v)
# print(a)
for i in range(len(v)):
    mod_a[ v[i][1] ] = a[i]
# print(mod_a)
prefix = [0]*n
prefix[0] = mod_a[0]
for i in range(1,n):
    prefix[i] = prefix[i-1] + mod_a[i]
ans = 0
for i in range(len(queries)):
    l,r = queries[i][0],queries[i][1]
    l-=1
    r-=1
    if l-1>=0:
        ans += prefix[r]-prefix[l-1]
    else:
        ans += prefix[r]

x = str(ans)
ch = ''
for i in range(len(x)):
    ch += x[i]
stdout.write(ch)