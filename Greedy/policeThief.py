from sys import stdin, stdout

def catchThieves(a, n, k): 
    p, t = [], []
    for i in range(n):
        if a[i]=='P':
            p.append(i)
        else:
            t.append(i)
    catch = 0
    while len(p)>0 and len(t)>0:
        x,y = p[0],t[0]
        if y<=(x+k) and y>=(x-k):
            p.pop(0)
            t.pop(0)
            catch+=1
        else:
            p.pop(0)
    return catch


t = int(stdin.readline())
while t>0:
    n, k = map(int,stdin.readline().split())
    a = stdin.readline().split('\n')[0]
    ans = catchThieves(a,n,k)
    stdout.write("{}\n".format(ans))
    t-=1