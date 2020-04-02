
'''
Really good question 
dp[l][r] -> minimum removal when minimum is l and maximum is r
'''


global dp
def solve(a,l,r,d):
    if r-l+1 <= 1:
        return 0
    curD = a[r]-a[l]
    if curD <= d:
        return 0
    if dp[l][r]!=-1:
        return dp[l][r]
    
    dp[l][r] = min( 1+solve(a,l+1,r,d), 1+solve(a,l,r-1,d) ) 
    return dp[l][r]

def greedy(a,d):
    n = len(a)
    ans = 10000
    for i in range(n-1):
        for j in range(i+1,n):
            curD = a[j]-a[i]
            if curD <= d:
                pointsRemoved = (i + n-j-1)
                ans = min(ans,pointsRemoved)
    if ans==10000:
        if len(a)==1:
            return 0
        return len(a)-1
        
    return ans

dp = [[ -1 for i in range(100)] for j in range(100)]
n, d = map(int,input().split())
a = list(map(int,input().split()))
a = sorted(a)
ans = solve(a,0,n-1,d)
print("DP SOLUTION:",ans)

ans = greedy(a,d)
print("Greedy Solution:",ans)



