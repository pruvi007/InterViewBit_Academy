t = int(input())
while t>0:
    k,m = map(int,input().split())
    info = []
    for i in range(m):
        x,y = map(int,input().split())
        info.append([x,y])
    dp = [ [0 for j in range(k+1)] for i in range(m+1) ]
    for i in range(m+1):
        for j in range(k+1):
            if i==0 or j==0:
                dp[i][j] = 0
            elif info[i-1][0] <= j:
                dp[i][j] = max( info[i-1][1] + dp[i-1][j-info[i-1][0]], dp[i-1][j] )
            else:
                dp[i][j] = dp[i-1][j]
    print("Hey stupid robber, you can get {}.".format(dp[m][k]))
    t-=1
