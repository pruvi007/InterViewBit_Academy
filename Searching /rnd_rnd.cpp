#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin >> n >> m;
	unordered_map<int,int> um;
	for(int i=0;i<m;i++)
	{
		int x;
		cin >> x;
		um[x]++;
	}
	vector<int> a;
	for(int i=1;i<=n;i++)
		a.push_back(i);
	for(int i=1;i<=n;i++)
		a.push_back(i);

	int mm = INT_MAX;
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		int c = 1;
		int tot = 0;
		int f[10000]={0};
		for(int j=0;j<a.size();j+=(i+1))
		{
			int x = a[j];
			cout << x << " ";
			if( um.find(x) != um.end() && f[a[j]]==0 )
			{
				tot++;
				f[a[j]]=1;
				if( tot == m)
					break;
			}
			c++;

		}
		cout << endl;
		if(mm > c && tot == m)
		{
			mm = c;
			ans = i+1;
		}
	}
	cout << mm << endl;
}