/*
	Mancunian and colored tree (HE)
	Find the nearest Ancestor with the same color.
	Idea: do a dfs and maintain color,value pair
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > v(100001);
map<int,int> color,pathColor;
bool vis[100001];
int l=2;
int dfs(int n,int child,bool vis[])
{
	if( n == child )
	{
		if(pathColor.find(color[n]) != pathColor.end())
			return pathColor[color[n]];
		return -1;
	}
	cout << n << " ";
	vis[n] = true;
	pathColor[color[n]] = n;
	
	
	for(int i=0;i<v[n].size();i++)
	{
		if(vis[ v[n][i] ] == false)
		{
			return dfs(v[n][i],child,vis);
		}
	}
	
}


int main()
{
	int n,c;
	cin >> n >> c;
	
	for(int i=1;i<n;i++)
	{
		int x;
		cin >> x;
		int par = x;
		v[par].push_back(i+1);
	}
	
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		color[i+1] = x;

	}
	for(int i=1;i<=n;i++)
	{
		pathColor.clear();
		memset(vis,false,sizeof(vis));
		cout << endl;
		int ans = dfs(1,i,vis);
		map<int,int>::iterator it;

		cout << endl << i << ": ";
		for(it=pathColor.begin();it!=pathColor.end();it++)
		{
			cout << it->first << "-" << it->second << "   ";
		}
		cout << endl;

		cout << ans << " ";
	}
	
	cout << endl;

}