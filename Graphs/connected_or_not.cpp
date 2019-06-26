/*
	Find if a given graph is connected or not
	Idea: run a dfs once (if any node is unvisisted then disconnected)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > v(1000);
void dfs(bool vis[],int n)
{
	cout << n << " ";
	vis[n] = true;

	for(int i=0;i<v[n].size();i++)
	{
		if(vis[v[n][i]] == false)
		{
			dfs(vis,v[n][i]);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	
	while(m--)
	{
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	bool vis[n+1];
	memset(vis,n+1,false);
	dfs(vis,1);

	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i] == false)
			flag = 1;
	}
	if(flag)
		cout << "Not Connected\n";
	else cout << "Connected\n";
}