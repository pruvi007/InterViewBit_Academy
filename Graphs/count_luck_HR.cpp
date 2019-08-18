/*
    Find the path from start to end using BFS by passing vector of paths in BFS call
    then for each node in the final path if there are more than one choice than decision is incremented
*/

// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

char grid[1001][1001];
int isSafe(int x,int y,int n,int m)
{
    return x>=0 && y>=0 && x<n && y<m && (grid[x][y]=='.' || grid[x][y]=='*');
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        
        pair<int,int> s;
        pair<int,int> f;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == 'M')
                    s = {i,j};
                if(grid[i][j] == '*')
                    f = {i,j};
            }
                
        }
        int k;
        cin >> k;
        
        queue< pair< pair<int,int>,vector<pair<int,int> > > > q;
        vector<pair<int,int> > v;
        v.push_back(s);
        q.push({s,v});
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        map<pair<int,int>,int> mp;
        mp[s]=1;
        vector<pair<int,int> > fPath;
        while(!q.empty())
        {
            pair< pair<int,int>,vector<pair<int,int> > > p = q.front();
            q.pop();
            mp[p.first] =1;
            if(p.first == f)
            {
                fPath = p.second;
                break;
            }
                
            
            for(int i=0;i<4;i++)
            {
                int a = p.first.first + dx[i];
                int b = p.first.second + dy[i];
                if(isSafe(a,b,n,m) && mp.find({a,b}) == mp.end())
                {
                    vector<pair<int,int> > temp = p.second;
                    temp.push_back({a,b});
                    q.push( { {a,b}, temp } );
                    
                }
            }
            
        }
        mp.clear();
        int decision = 0;
        for(int i=0;i<fPath.size()-1;i++)
        {
            cout << fPath[i].first << " " << fPath[i].second << " ";
            int a = fPath[i].first;
            int b = fPath[i].second;
            mp[{a,b}]=1;
            int count =0;
            for(int j=0;j<4;j++)
            {
                int x = a+dx[j];
                int y = b+dy[j];
                if(isSafe(x,y,n,m) && mp.find({x,y}) == mp.end())
                    count++;
            }
            cout << count << endl;
            if(count > 1)
                decision++;
        }
            
        
        // cout << decision << endl;
        if(decision == k)
            cout << "Impressed\n";
        else cout << "Oops!\n";

    }
}
