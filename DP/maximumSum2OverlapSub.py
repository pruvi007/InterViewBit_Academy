
# O(n^2) logic
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        n = len(A)
        if not n:
            return 0
        pre = [0 for i in range(n)]
        pre[0] = A[0]
        for i in range(1,n):
            pre[i] = pre[i-1]+A[i]
        pre = [0] + pre
        # print(pre)
        l = []
        i = 0
        while i<n:
            s,e = i, i+L-1
            if s<n and e<n:
                l.append([s,e])
            i+=1
        i=0
        m = []
        while i<n:
            s,e = i,i+M-1
            if s<n and e<n:
                m.append([s,e])
            i+=1
        ans = 0
        # print(l)
        # print(m)
        for i in range(len(l)):
            for j in range(len(m)):
                s1,e1 = l[i][0], l[i][1]
                s2,e2 = m[j][0], m[j][1]
                if s1<s2 and e1<s2 or s2<s1 and e2<s1:
                    # print(s1,e1)
                    # print(s2,e2)
                    s1 = pre[e1+1] - pre[s1]
                    s2 = pre[e2+1] - pre[s2]
                    ans = max(ans,s1+s2)
        return ans

    


# O(n) logic
'''
Lets work with M sized arrays
LEFT[i] = max sum of any M sized array left of i
RIGHT[i] = max sum of any M sized array right of i

for every L sized subarray :
    get its left and right then keep track of max
'''
class Solution:
    def maxSumTwoNoOverlap(self, A: List[int], L: int, M: int) -> int:
        n = len(A)
        if not n:
            return 0
        pre = [0 for i in range(n)]
        pre[0] = A[0]
        for i in range(1,n):
            pre[i] = pre[i-1]+A[i]
        pre = [0] + pre
        dp1,dp2 = [0 for i in range(n)],[0 for i in range(n)]

        # left DP
        for i in range(n):
            s,e = i,i+M-1
            if s<n and e<n:
                if e+1<n:
                    dp1[e+1] = max( dp1[e], pre[e+1]-pre[s])

        # right DP
        for i in range(n-1,-1,-1):
            s,e = i, i-M+1
            if s>=0 and e>=0:
                if e-1>=0:
                    dp2[e-1] = max(dp2[e], pre[s+1]-pre[e])
        # print(dp1)
        # print(dp2)
        ans = 0
        for i in range(n):
            s,e = i,i+L-1
            if s<n and e<n:
                curSum = pre[e+1]-pre[s]
                left = dp1[s]
                right = dp2[e]
                ans = max( ans,left+curSum,right+curSum )
            
        return ans

