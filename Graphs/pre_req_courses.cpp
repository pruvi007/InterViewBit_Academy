/*
	Pre-Requisites to finish all the courses
	Idea: if there is a cycle then unable to finish
	Here we can think that the graph would be directed
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int dfs(int n,int vis[],vector< vector<int> > &v)
{
	// started processing (inside stack)
	vis[n] = 1;
	for(int i=0;i<v[n].size();i++)
	{
		// backEdge (edge to an ancestor )
		if(vis[v[n][i]] == 1)
			return 1;
		else if(vis[v[n][i]] == 0)
		{
		    if(dfs(v[n][i],vis,v))
		        return 1;
		}
			
	}
	// process complete so mark it 2
	vis[n] = 2;
	return 0;
}

int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;
	vector< vector<int> > v(10001);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		v[x].push_back(y);
	}

	int vis[10001];
	memset(vis,0,sizeof(vis));
	int isCycle=0;

	for(int i=1;i<=A;i++)
	{
	    if(dfs(i,vis,v))
	    {
	    	isCycle = 1;
	        cout << "NOT\n";
	    }
	    
	}
	if(!isCycle)
		cout << "YES\n";
}