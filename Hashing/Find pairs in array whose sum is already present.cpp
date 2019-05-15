// Find pairs in array whose sum is already present
// expected Complexity : O(n^2)
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		mp[a[i]]++;
	}
	int c = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			int d = a[i]+a[j];
			if(mp.find(d)!=mp.end())
				c++;

		}
	}
	// map<int,int>::iterator it;
	// for(it=mp.begin();it!=mp.end();it++)
	// {
	// 	cout<<(it->first)<<" : "<<(it->second)<<endl;
	// }
	
	cout<<c<<endl;

}