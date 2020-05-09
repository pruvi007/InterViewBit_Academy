class solution:
    def __init__(self):
        n = int(input())
        self.a = list( map(int,input().split()) )
        from collections import defaultdict
        self.adj = defaultdict(list)
        self.S = sum(self.a)
        for i in range(n-1):
            x,y = map(int,input().split())
            self.adj[x].append(y)
            self.adj[y].append(x)
        self.vis = set()
        self.ans = 10**10
        self.dfs(1)
        print(self.ans)

    def dfs(self,n):
        subTree = 0
        self.vis.add(n)
        for i in range(len(self.adj[n])):
            if(self.adj[n][i] not in self.vis):
                subTree += self.dfs( self.adj[n][i] )
        self.ans = min(self.ans,self.S-subTree)
        # print(subTree)
        return self.a[n-1]+subTree

obj = solution()

    


    
