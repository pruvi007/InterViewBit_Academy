#define INF 1000001
vector< vector<int> > getAllPairShortestPath( vector<vector<int> > v,int n )
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( v[i][j] == 0)
                v[i][j] = INF;
        }
    }
    
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                // if k is an intermediate node and have lesser distance
                if( v[i][j] > v[i][k] + v[k][j] )
                    v[i][j] = v[i][k] + v[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    return v;
}

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector< vector<int> > v( n,vector<int>(n,0) );
        // int m;
        // cin >> m;
        for(int i=0;i<edges.size();i++)
        {
            int x,y,w;
            x = edges[i][0];
            y = edges[i][1];
            w = edges[i][2];
            v[x][y] = w;
            v[y][x] = w;
        }

        // get all pair shortest paths 
        // this will let us know the cities reached from ith city under threshold distance
        vector< vector<int> > floyd = getAllPairShortestPath( v,n );
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[i] = 0;
            for(int j=0;j<n;j++)
            {
                if( j!=i and floyd[i][j] <= threshold )
                    mp[i]++;
            }
        }
        int cur = INT_MAX,ind;
        for( auto it=mp.begin();it!=mp.end();it++)
        {
            if( it->second <= cur )
            {
                cur = it->second;
                ind = it->first;
            }
        }
        return ind;
    }
};