
class ZigZag:

    def longestZigZag(self,a):
        n = len(a)
        if n<=1:
            return n
        # dp[0][i] = longest zig-zag ending at negative
        # dp[1][i] = longest zig-zag ending at positive
        dp = [[ 0 for i in range(n)] for j in range(2)]
        if a[1]-a[0] > 0:
            dp[1][1] = 1
        elif a[1]-a[0] < 0 :
            dp[0][1] = 1
        
        for i in range(2,n):
            for j in range(0,i):
                d = a[i] - a[j]
                # if d is negative -> add 1 from the max positve
                if d<0:
                    dp[0][i] = max( dp[0][i], dp[1][j]+1 )
                elif d>0:
                    dp[1][i] = max( dp[1][i], dp[0][j]+1 )
        for d in dp:
            print(d)

        return max( max(dp[0]),max(dp[1]) )+1

n = int(input())
a = list( map(int,input().split()) )
obj = ZigZag()
ans = obj.longestZigZag(a)
print(ans)
