
from sys import stdin, stdout

def check(flag):
    for i in range(len(flag)):
        if flag[i] == False:
            return False
    return True

def minLight(a,n):
    A = []
    for i in range(n):
        if a[i]>-1:
            start,end = max(0,i-a[i]), min(n-1,i+a[i])
            d = end-start+1
            A.append([start,end])
    A = sorted(A,reverse=True)
    print(A)
    flag = [ False for i in range(n) ]
    candle = 0
    valid = False
    while len(A)>0:
        x = A.pop(0)
        start,end = x[0], x[1]
        req = False
        for i in range(start,end+1):
            if flag[i]==False:
                flag[i] = True
                req = True
        if req:
            candle += 1
        if check(flag):
            valid = True
            break
    if valid:
        return candle
    return -1
t = int(stdin.readline())
while t>0:
    n = int(stdin.readline())
    a = list( map(int,stdin.readline().split()) )
    ans = minLight(a,n)
    stdout.write("{}\n".format(ans))
    t-=1