/*
	WORD LADDER
	idea: use bfs and explore the adjacent words (that differs in only one char)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int isAdj(string a,string b)
{
	int c = 0;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!=b[i])
			c++;
	}
	return c==1;
}
int bfs_words(string s,string t,vector<string> &v)
{
	queue<pair<string,int> > q;
	map<string,int> m;
	m[s] = 1;

	q.push({s,0});
	while(!q.empty())
	{
		pair<string,int> p = q.front();
		q.pop();
		if(isAdj(t,p.first) || p.first == t)
		{
			if(isAdj(t,p.first))
				return p.second+2;
			return p.second+1;
		}
		for(int i=0;i<v.size();i++)
		{
			if(isAdj(v[i],p.first) && m.find(v[i])==m.end())
			{
				q.push({v[i],p.second+1});
				m[v[i]] = 1;
			}
		}
	}
	return 0;
}
int main()
{
	string s,t;
	cin >> s >> t;
	vector<string> v;
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		string x;
		cin >> x;
		v.push_back(x);
	}
	int ans = bfs_words(s,t,v);
	cout << ans << endl;
}