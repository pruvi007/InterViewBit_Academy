/*
	use the adjancency list to get the immediate neigbours
	sort the values in descending order using comparator in case of same first values sort the next in descending
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

struct myComp{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return (a.first > b.first) || (a.first==b.first && a.second>b.second);
	}
};

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	int val[n];
	for(int i=0;i<n;i++)
		cin >> val[i];
	vector<vector<pair<int,int> > > v(n+1);
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin >> x >> y;
		v[x].push_back({val[y-1],y});
		v[y].push_back({val[x-1],x});
	}
	for(int i=1;i<=n;i++)
	{
		vector<pair<int,int> > temp;
		for(int j=0;j<v[i].size();j++)
		{
			temp.push_back(v[i][j]);
		}
		sort(temp.begin(),temp.end(),myComp());
		// cout << i <<" : ";
		// for(int j=0;j<temp.size();j++)
		// {
		// 	cout << temp[j].first << " " << temp[j].second << endl;
		// }
		if(k<=temp.size())
			cout << temp[k-1].second << endl;
		else cout <<"-1\n";
	}
}