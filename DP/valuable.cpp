#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int solve( vector< vector<int> > adj,vector<int> val,int cur )
{
    // get the child, and gchild .
    vector<int> child,gchild;
    for(int i=0;i<adj[cur].size();i++)
        child.push_back( adj[cur][i] );
    for(int i=0;i<child.size();i++)
    {
        for(int j=0;j<adj[child[i]].size();j++)
            gchild.push_back( adj[child[i]][j] );
    }
   

    // now cases
    // case 1 - take current node and call on gchild
    // case 2 - dont take current child and call on child
    int a = val[cur-1];
    for(int i=0;i<gchild.size();i++)
        a += solve( adj,val,gchild[i] );
    int b = 0;
    for(int i=0;i<child.size();i++)
        b += solve( adj,val,child[i] );
    
    int ans = max( a,b );
    return ans;
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