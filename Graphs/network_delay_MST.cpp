#include<bits/stdc++.h>
using namespace std;


int getPar(int x,int par[])
{
    while(x!=par[x])
        x = par[x];
    return x;
}
bool find(int x,int y,int par[])
{
    return getPar(x,par) == getPar(y,par);
}
int doUnion(int x,int y,int par[],int size[]){
    if( find(x,y,par) )
        return -1;
    int p1 = getPar(x,par), p2 = getPar(y,par);
    int s1 = size[p1], s2 = size[p2];
    if( s1>s2 )
    {
        par[p2] = p1;
        size[p1] += s2;
    }
    else
    {
        par[p1] = p2;
        size[p2] += s1;
    }
    return 1;
    
}
bool comp(const vector<int> &a,const vector<int> &b)
{
    return a[2]<b[2];
}
vector< vector<int> > getMst( int n,vector< vector<int> > times)
{
    //  cout << "hello";
    sort(times.begin(),times.end(),comp);
    // cout << "hello";
    // for(int i=0;i<times.size();i++)
    //     cout << times[i][0] << " " << times[i][1] << " " << times[i][2] << endl;
    vector<vector<int> > mst;
    int par[n+1],size[n+1];
    for(int i=1;i<=n;i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    for(int i=0;i<times.size();i++)
    {
        int x = doUnion(times[i][0],times[i][1],par,size);
        if(x==1)
        {
            mst.push_back( times[i] );
        }
    }
    return mst;
}
int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > times;
    for(int i=0;i<m;i++)
    {
        int x,y,cost;
        cin >> x >> y >> cost;
        vector<int> temp{x,y,cost};
        times.push_back(temp);
    }
    // for(int i=0;i<times.size();i++)
    //     cout << times[i][0] << " " << times[i][1] << " " << times[i][2] << endl;
    int k;
    cin >> k;
    // cout << "hello";
    vector< vector<int> > mst = getMst( n,times );
    // for(int i=0;i<mst.size();i++)
    // {
    //     cout << mst[i][0] << " " << mst[i][1] << " " << mst[i][2] << endl;
    // }

    vector<vector<pair<int,int> > > adj(n+1);
    for(int i=0;i<mst.size();i++)
    {
        int x = mst[i][0];
        int y = mst[i][1];
        int c = mst[i][2];
        adj[x].push_back({y,c});
    }
    queue<int> q;
    bool vis[n+1];
    memset(vis,false,sizeof(vis));
    q.push(k);
    vis[k]=true;
    int ans = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        int mx = 0;
        
        for(int i=0;i<adj[x].size();i++)
        {
            int nbr = adj[x][i].first;
            int cost = adj[x][i].second;
            // cout << nbr << " ";
            if( vis[nbr]==false )
            {
                mx = max(cost,mx);
                q.push( nbr );
                vis[nbr] = true;
            }
            
            
        }
        // cout << m << endl;
        // cout << endl;
        ans += mx;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==false)
           cout << "-1\n";
    }
    cout << ans << endl;

}