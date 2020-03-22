#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9 + 7;
int solve( vector< vector<int> > adj,vector<int> val,int cur )
{
    // get the child, gchild and ggchild for the current node
    vector<int> child,gchild,ggchild;
    for(int i=0;i<adj[cur].size();i++)
        child.push_back( adj[cur][i] );
    for(int i=0;i<child.size();i++)
    {
        for(int j=0;j<adj[child[i]].size();j++)
            gchild.push_back( adj[child[i]][j] );
    }
    for(int i=0;i<gchild.size();i++)
    {
        for(int j=0;j<adj[gchild[i]].size();j++)
            ggchild.push_back( adj[gchild[i]][j] );
    }

    // now cases
    // case 1 - take current node and call on ggchild
    // case 2 - dont take current child and call on child
    // case 3 - dont take any child and call on gchild
    int a = val[cur-1];
    for(int i=0;i<ggchild.size();i++)
        a += solve( adj,val,ggchild[i] )%mod;
    int b = 0;
    for(int i=0;i<child.size();i++)
        b += solve( adj,val,child[i] )%mod;
    int c = 0;
    for(int i=0;i<gchild.size();i++)
        c += solve( adj,val,gchild[i] )%mod;
    int ans = max( a,max(b,c) );
    return ans%mod;
}
int main()
{
    int n;
    cin>>n;
    vector<int> P(n),val(n);
    vector< vector<int> > adj(n+1);
    for(int i=0;i<n;i++)
    {
        cin >> P[i];
        if(i>0)
            adj[P[i]].push_back(i+1);
    }
    for(int i=0;i<n;i++)
        cin >> val[i];
    
    int ans = solve( adj,val,1 );
    cout << ans << endl;
}