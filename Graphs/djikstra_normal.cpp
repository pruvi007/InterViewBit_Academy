/*
	implement djikstra 
	in this code i ll do the O(V^2) implementation
	Then in  further codes i ll do it using min heap
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int n,m;
int min_vertex(int dis[],bool vis[])
{
	int min=INT_MAX,min_ind=-1;
	for(int i=0;i<n;i++)
	{
		if(dis[i] < min && vis[i] == false)
		{
			min = dis[i];
			min_ind = i;
		}
	}
	return min_ind;
}

int main()
{
	
	cin >> n;
	
	cin >> m;
	int dj[1001][1001];
	memset(dj,0,sizeof(dj));
	vector< vector<pair<int,int> > > v(100001);
	for(int i=0;i<m;i++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		dj[x][y] = w;
		dj[y][x] = w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});

	}
	int dis[n+1];
	for(int i=0;i<n;i++)
		dis[i] = INT_MAX;
	int src;
	cin >> src;
	dis[src] = 0;
	bool vis[n+1];
	memset(vis,false,sizeof(vis));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << dis[j] << " ";
		cout << endl;
		int u = min_vertex(dis,vis);
		// cout << u << " ";
		if(u==-1)
			break;
		vis[u] = true;
		for(int j=0;j<v[u].size();j++)
		{
			pair<int,int> p = v[u][j];
			int f = p.first;
			int w = p.second; 
			if(vis[f]==false && dis[u]!=INT_MAX )
			{
				// cout << u << ": " << j << " " << dj[u][j] << endl;
				dis[f] = min(dis[f],dis[u]+w);
			}
		}
	}
	cout << endl;
	for(int i=0;i<n;i++)
		cout << dis[i] << " ";
	cout << endl;
}