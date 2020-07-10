#include<bits/stdc++.h>
using namespace std;

map<int,int> ans;
map<int,int> problem;
void dfs(vector<vector<int>> &v,int n,set<int> &vis,int p,vector<int> &deg)
{
	vis.insert(n);
	bool isLeaf = true;
	for(int i=0;i<v[n].size();i++)
	{
		int node = v[n][i];
		isLeaf = false;
		if(problem[n]==2)
		{
			p = n;
			ans[p]++;
		}
		if( vis.find(node)==vis.end() )
		{
			vis.insert(node);
			
			dfs(v,node,vis,p,deg);
		}
	}
	// if(deg[n]==1)
	// 	cout << n << ":" << ":" << p << endl;
	// if(p!=1 and deg[n]==1 and p!=-1)
	// 	ans[p]++;
	return;
}
int main(){
	int n;
	cin >> n;
	vector< vector<int> > v(n+1);
	problem.clear();
	vector<int> deg(n+1);
	for(int i=0;i<n-1;i++)
	{
		int x,y,t;
		cin >> x >> y >> t;
		v[x].push_back(y);
		v[y].push_back(x);
		problem[x]=t;
		problem[y]=t;
		deg[x]++;deg[y]++;
	}
	set<int> vis;
	ans.clear();
	dfs(v,1,vis,-1,deg);
	vector<int> fans;
	
	for(auto it=ans.begin();it!=ans.end();it++){
		if(it->second==1 and it->first!=1)
			fans.push_back(it->first);
		// cout << it->first << " : " << it->second << '\n';
	}
	cout << fans.size()<<'\n';
	for(int i=0;i<fans.size();i++)
		cout << fans[i] << " ";
	cout << '\n';
}