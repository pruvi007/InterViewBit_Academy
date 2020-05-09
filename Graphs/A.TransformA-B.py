from sys import stdin, stdout
a, b = map(int,stdin.readline().split())
q = [ [a,[a]] ]
ans = []
while len(q):
    f = q.pop(0)
    cur,l = f[0],f[1]
    if cur == b:
        ans = l
        break
    n1,n2 = 2*cur, int(str(cur)+'1')
    if n1<=b:
        q.append([ n1,l+[n1] ])
    if n2<=b:
        q.append( [n2,l+[n2]] )
if len(ans):
    stdout.write("YES\n")
    stdout.write("{}\n".format(len(ans)))
    for x in ans:
        stdout.write("{} ".format(x))
    stdout.write("\n")
else:
    stdout.write("NO\n")