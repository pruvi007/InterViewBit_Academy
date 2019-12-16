n = int(input())
while n>0:
    a,b = input(),input()
    n,m = len(a),len(b)
    dp = [ [0 for j in range(m+1)] for i in range(n+1) ]
    # print(dp)
    dp[0][0] = 0
    for i in range(1,m+1):
        dp[0][i] = i
    for i in range(1,n+1):
        dp[i][0] = i
    # for r in dp:
    #     print(r)
    # print()
    for i in range(1,n+1):
        for j in range(1,m+1):
            if a[i-1] == b[j-1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                insert = dp[i][j-1]
                delete = dp[i-1][j]
                replace = dp[i-1][j-1]
                dp[i][j] = 1 + min( min(insert,delete),replace )
    # for r in dp:
    #     print(r)
    print(dp[n][m])
    n-=1
