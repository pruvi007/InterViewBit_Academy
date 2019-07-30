/*
	monk and graph problem
	HE
	handling self loops (use map and store them seaprately dont include in adjacency list)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > v(100005);
map<int,int> mp;
bool vis[100005];
int c;
int self;
void dfs(int n)
{
	vis[n] = true;
	cout << n << " " ;
	if(mp.find(n) != mp.end())
		c += mp[n];

	for(int i=0;i<v[n].size();i++)
	{
		if(vis[ v[n][i] ] == false)
		{
			c+= v[n].size();
			dfs(v[n][i]);
		}
	}
}
void bfs(int n)
{
	queue<int> q;
	q.push(n);
	vis[n] = true;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		cout << x << " ";
		if(mp.find(x) != mp.end())
			self += mp[x];
		c += v[x].size();
		
		for(int i=0;i<v[x].size();i++)
		{
			if(vis[ v[x][i] ] == false)
			{
				vis[v[x][i]] = true;
				q.push(v[x][i]);
			}
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		if( x == y )
			mp[x]++;
		else
		{
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	memset(vis,false,sizeof(vis));
	int max = 0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i] == false)
		{
			c = 0;
			self = 0;
			bfs(i);
			cout << endl;
			int ans = self + c/2;
			if(ans > max)
				max = ans;
		}
	}
	cout << max << endl;

}