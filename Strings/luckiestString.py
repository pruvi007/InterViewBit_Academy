from sys import stdin,stdout
n = int(stdin.readline())
s = stdin.readline().split('\n')[0]
lps = [ 0 for i in range(n) ]
lps[0] = 0
l,r = 0,1
while r<n:
    if s[l]==s[r]:
        l+=1
        lps[r]=l
        r+=1
    else:
        if l>0:
            l = lps[l-1]
        else:
            lps[r] = 0
            r+=1
print(lps)
        