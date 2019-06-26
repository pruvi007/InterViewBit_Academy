/*
	Find shortest distance between source and destination in a graph which has weights 1 or 2.
	idea: introduce dummy nodes to make distances 1, then apply BFS to get the shortest distance.
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
vector< vector<int> > v(100001);

int bfs(bool vis[],int source,int dest)
{
	// we will push val,level in the queue
	queue< pair<int,int> > q;
	q.push({source,0});
	vis[source] = true;
	while(!q.empty())
	{
		int n = q.size();
		for(int i=0;i<n;i++)
		{
			pair<int,int> p = q.front();
			q.pop();

			// cout << p.first << " ";

			if(p.first == dest)
				return p.second;

			for(int j=0;j<v[p.first].size();j++)
			{
				if(vis[v[p.first][j]] == false)
				{
					vis[v[p.first][j]] = true;
					q.push({v[p.first][j],p.second+1});
				}
			}

		}
		// cout << endl;	
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;

	int l1 = 99999;
	while(m--)
	{
		int x,y,w;
		cin >> x >> y >> w;
		if(w == 2)
		{
			int t1 = l1;
			int t2 = l1+1;
			l1+=2;
			v[x].push_back(t1);
			v[t1].push_back(y);
		}
		else
		{
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}

	cout << endl;
	for(int i=0;i<v.size();i++)
	{
		if(v[i].size() > 0)
		{
			cout << i << ": ";
			for(int j=0;j<v[i].size();j++)
				cout << v[i][j] << " ";
			cout << endl;
		}
	}
	int s,d;
	cin >> s >> d;
	bool vis[100001];
	memset(vis,0,sizeof(vis));
	cout << bfs(vis,s,d) << endl;

}