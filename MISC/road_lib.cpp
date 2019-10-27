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


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,c_lib,c_road;
		cin >> n >> m >> c_lib >> c_road;
		vector< vector<int> > v(n+1);
		// init dsu
		int par[n+1],size[n+1];
		for(int i=1;i<=n;i++)
		{
			par[i] = i;
			size[i] = 1;
		}
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
			int b = doUnion(x,y,par,size);
		}
		unordered_map<int,int> mp;
		for(int i=1;i<=n;i++)
		{
			int p = getPar(i,par);
			mp[p]++;
		}

		int ans = 0;

		if( c_lib < c_road )
		{
			for(auto it = mp.begin();it!=mp.end();it++)
			{
				ans += c_lib*it->second;
			}
		}
		else
		{
			for(auto it = mp.begin();it!=mp.end();it++)
			{
				ans += c_lib + c_road*(it->second-1);
			}
		}
		cout << ans << endl;
	}
}