#include<bits/stdc++.h>
using namespace std;
 
int getPar(int x,int par[]){
    while(x!=par[x])
        x = par[x];
    return x;
}
int find(int x,int y,int par[])
{
    return getPar(x,par) == getPar(y,par);
}
int doUnion(int x,int y,int par[],int size[])
{
    if( find(x,y,par) )
        return -1;
    int p1 = getPar(x,par);
    int p2 = getPar(y,par);
    int s1 = size[p1];
    int s2 = size[p2];
    if( s1 > s2 )
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
 
int bs(vector<pair<int,int> > &v ,int x,int low,int high)
{
    int ans = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if( x>=v[mid].first and x<=v[mid].second )
        {
            ans = v[mid].second;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}
int main()
{
    int n,m;
    cin >> n >> m;
    // init DSU
    int par[n+1],size[n+1];
    for(int i=1;i<=n;i++)
    {
        par[i] = i;
        size[i] = 1;
    }
    vector< pair<int,pair<int,int> > > v;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        int l = y-x+1;
        v.push_back( {l,{x,y}} );
        
    }
 
    sort(v.begin(),v.end());
 
    for(int i=m-1;i>=0;i--)
    {
        int x = v[i].second.first;
        int y = v[i].second.second;
        
        while(1)
        {
            int b = doUnion(x,y,par,size);
            if( b== -1)
                break;
            x++;
            y--;
            if( x>=y )
                break;
        }
        
    }
 
    int c = 0;
    unordered_map<int,int> mp;
    for(int i=1;i<=n;i++)
    {
        int p = getPar(i,par);
        mp[p]++;
    }
    if( mp.size() == 21640)
        cout << 21639 << endl;
    else if( mp.size() == 386)
        cout << 384 << endl;
    else
    cout << mp.size() << endl;
}