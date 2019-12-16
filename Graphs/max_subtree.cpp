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
int M = 1;
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
        M = max(size[p1],M);
    }
    else
    {
        par[p1] = p2;
        size[p2] += s1;
        M = max(size[p2],M);
    }
    return 1;
}

int main()
{
	int n;
	cin >> n ;
	// init DSU
	int par[n+1],size[n+1];
	for(int i=1;i<=n;i++)
	{
		par[i] = i;
		size[i] = 1;
	}
	int m;
	cin >> m;
	vector< pair<int,int> > edge;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		edge.push_back({x,y});

	}
	int r;
	cin >> r;
	vector<int> rem;
	map<int,int> mp;
	for(int i=0;i<r;i++)
	{
		int x;
		cin >> x;
		rem.push_back(x);
		mp[x-1]=1;
	}
	for(int i=0;i<m;i++)
	{
		if(mp.find(i)==mp.end())
		{
			int b = doUnion(edge[i].first,edge[i].second,par,size);
		}
	}
	vector<int> ans;
	cout << M << endl;
	map<int,vector<int> > gp;
	for(int i=1;i<=n;i++)
	{
		int p = getPar(i,par);
		gp[p].push_back(i);
	}
	for(auto it=gp.begin();it!=gp.end();it++)
	{
		vector<int> v = it->second;
		for(int i=0;i<v.size();i++)
			cout << v[i] << " ";
		cout << endl;
	}
	for(int i=rem.size()-1;i>=0;i--)
	{
		int ind = rem[i]-1;
		int x = edge[ind].first;
		int y = edge[ind].second;
		ans.push_back(M);
		int b = doUnion(x,y,par,size);
	}
	reverse(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		cout << ans[i] << " ";
	cout << endl;

}