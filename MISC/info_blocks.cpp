#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n ;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	map<int,int> mp;
	for(int i=n-1;i>=0;i--)
	{
		if( mp.find(a[i])==mp.end() )
			mp[a[i]] = i;
	}
	int i=0;

	int change = 0;
	while(i<n)
	{
		int x = a[i];
		int last = mp[x];
		int j = i;
		unordered_map<int,int> m2;
		while( j<=last )
		{
			if( mp[a[j]] >= last)
				last = mp[a[j]];
			m2[a[j]]++;
			j++;
		}
		int M = 0;
		int sum = 0;
		for(auto it=m2.begin();it!=m2.end();it++)
		{
			// cout << it->first << " " << it->second << endl;
			M = max(it->second,M);
			sum += it->second;
		}
		// cout << endl;
		i=j;
		change += abs(sum - M );
	}
	cout << change << endl;
}