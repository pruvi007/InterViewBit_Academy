def contains(a,b):
    for i in range(26):
        if a[i]>b[i]:
            return False
    return True

def solve(s,t):
    original = [0]*26
    # print(len(original))
    for c in t:
        original[ ord(c)%65 ]+=1
    current = [0]*26
    l,r = 0,0
    n = len(s)
    print(n)
    ans = 999999999
    # start,end=0,0
    while r<n and l<n:
        
        if contains( original,current ):
            # todo with left pointer
            print(l,r)
            d = r-l+1
            if d<ans:
                
            
            current[ ord(s[l])%65 ]-=1
            l+=1
        else:
            # todo with right pointer
            
            current[ ord(s[r])%65 ]+=1
            r+=1
    print(  )
    return ans 

s,t = input(),input()
ans = solve(s,t)
print(ans)