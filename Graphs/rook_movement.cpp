/*
	ROOK MOVEMENT
	idea: get all paths from source to destination using bfs and for each calculate the row/column changes
	However it may get MLE
*/
// solution by pruvi007
// MEM LIMIT EXCEEDED

bool isSafe(int a,int b,int n,int m, vector<string> &E)
{
    return a>=1 && a<=n && b>=1 && b<=m && E[a-1][b-1] == '0';
}
int Solution::solve(int A, int B, int C, int D, vector<string> &E) {
    int n = E.size();
    int m = E[0].size();
    
    // up,right,down,left movement array
    int dx[] = {-1,0,1,0};
    int dy[] = {0,1,0,-1};
    queue< pair< pair<int,int>, vector<pair<int,int> > > > q;
    vector< pair<int,int> > temp,fPath,fPath2;
    
    bool vis[n+1][m+1];
    memset(vis,false,sizeof(vis));
    temp.push_back({A,B});
    q.push( { {A,B},temp } );
    int found = 0;
    int ans = INT_MAX;
    while(!q.empty())
    {
        pair< pair<int,int>, vector<pair<int,int> > > p = q.front();
        q.pop();
        // cout << p.first.first << " " << p.first.second << endl;
        vis[p.first.first][p.first.second] = true;
        if(p.first.first == C && p.first.second == D)
        {
            // final path from source to dest
            
            fPath = p.second;
            found = 1;
            int c = 0;
    
            // cout << sd1 << " " << sd2 << endl;
            for(int i=1;i<fPath.size();i++)
            {
                // row change
                if(fPath[i].first == fPath[i-1].first)
                {
                    int r = fPath[i-1].first;
                    while(fPath[i].first == r)
                    {
                        i++;
                    }
                    i--;
                    c++;
                }
                
                // column change
                else if(fPath[i].second == fPath[i-1].second)
                {
                    int col = fPath[i-1].second;
                    while(fPath[i].second == col)
                    {
                        i++;
                    }
                    i--;
                    c++;
                }
                
            }
            if( ans > c)
            {
                ans = c;
                fPath2 = p.second;
            }
        }
        for(int i=0;i<4;i++)
        {
            int a = p.first.first + dx[i];
            int b = p.first.second + dy[i];
            if( isSafe(a,b,n,m,E) && vis[a][b] == false )
            {
                vector< pair<int,int> > temp2 = p.second;
                temp2.push_back({a,b});
                q.push( {{a,b},temp2} );
            }
        }
            
    }
    if(!found)
        return -1;
    for(int i=1;i<fPath2.size();i++)
    {
        cout << fPath2[i].first << " " << fPath2[i].second << endl;
    } 
    
    return ans;
    
}
