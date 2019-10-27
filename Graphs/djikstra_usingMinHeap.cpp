

vector<int> Solution::solve(int A, vector<vector<int> > &B, int C) {
    
    priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<vector<pair<int,int>>> graph(A,vector<pair<int,int>> ());
    
    int n = B.size();
    for(int i = 0;i<n;i++)
    {
        int x = B[i][0];
        int y = B[i][1];
        int c = B[i][2];
        
        graph[x].push_back(make_pair(y,c));
        graph[y].push_back(make_pair(x,c));
    }
    
    
    // for(int i = 0;i<A;i++)
    // {
    //     for(int j = 0;j<graph[i].size();j++)
    //     {
    //         cout<<i<<" "<<graph[i][j].first<<" "<<graph[i][j].second<<endl;
    //     }
    // }
    

    vector<int> dist(A,INT_MAX);
    dist[C] = 0;
    pq.push({0,C});
    
    while(!pq.empty())
    {
        pair<int,int> t = pq.top();
        pq.pop();
        int c = t.first;
        int y = t.second;
        
        for(int i = 0;i<graph[y].size();i++)
        {
            int v = graph[y][i].first;
            int wt = graph[y][i].second;
            if(dist[v] > dist[y] + wt)
            {
                dist[v] = dist[y] + wt;
                pq.push({dist[v],v});
            }
        }
    }
    
    for(int i = 0;i<dist.size();i++)
    {
        if(dist[i] == INT_MAX)
            dist[i] = -1;
    }
    
    return dist;
}
