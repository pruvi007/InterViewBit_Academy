/*
	Coin Change Problem
	Given sum
	Find minimum coins which will make up the sum

	using MEMOIZATION
	(using a map)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

// map is used to remove overlapping substructure. (so that each call is made once)
map<int,int> m;
int minCoins(vector<int> &a,int s)
{
	if(s==0)
		return 0;
	int cMin = INT_MAX;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<=s)
		{
			if(m.find(s-a[i])!=m.end())
				cMin = min(cMin,m[s-a[i]]);
			else
			{
				// this is the recurrence relation
				cMin = min(cMin,minCoins(a,s-a[i]));
				m[s-a[i]] = cMin;
			}
			
		}
	}
	return cMin+1;
}
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x);
	}
	int sum ;
	cin >> sum;
	cout << (minCoins(a,sum)) << endl;
}
