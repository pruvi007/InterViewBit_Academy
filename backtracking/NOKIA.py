from sys import stdin, stdout
t = int(stdin.readline())

while t>0:
    n,m = map(int,stdin.readline().split())
    a = [ i+1 for i in range(n)]

    ans = 10**10
    sols = []
    def minLen(n):
        if n<=0:
            return 0
        return n+1 + minLen(n//2) + minLen( n-1-n//2 )
    def maxLen(n):
        if n<=0:
            return 0
        return n+1 + maxLen(n-1)
    MAX,MIN = maxLen(n),minLen(n)
    # print(MIN,MAX)
    if MIN<=m<=MAX:
        ans = 0
    elif m>MAX:
        ans = m-MAX
    else:
        ans = -1
    stdout.write("{}\n".format(ans))
    t-=1