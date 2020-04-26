from sys import stdin, stdout
from collections import defaultdict
def atMostK(s,k):
    d = defaultdict(int)
    i,j,count=0,0,0
    curDis = 0
    while j<len(s):
        d[s[j]]+=1
        if d[s[j]]==1:
            curDis+=1
        j+=1

        while i<j and curDis>k:
            d[s[i]]-=1
            if d[s[i]]<=0:
                del d[s[i]]
                curDis-=1
            i +=1
            # print(j,i)
            
        count += j-i

    return count
        
            


s = stdin.readline().split('\n')[0]
ans = atMostK(s,26) - atMostK(s,25)
stdout.write("{}\n".format(ans))
