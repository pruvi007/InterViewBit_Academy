import operator
from sys import stdin, stdout

n, m, reqAvg = map(int,stdin.readline().split())
report = []
curSum, curAvg = 0,0
for i in range(n):
    avg, grade = map(int,stdin.readline().split())
    curSum += avg
    report.append([avg,grade])
report.sort( key=operator.itemgetter(1) )
# print(report)
curAvg = curSum/n
if curAvg>=reqAvg:
    print(0)
else:
    ans = 0
    for i in range(len(report)):
        val,grade = report[i]
        if val<m:
            r = min( reqAvg*n - curSum,m-val )
            curSum += r
            ans += (r)*grade
            if curSum/n >= reqAvg:
                break
                
    print(ans)