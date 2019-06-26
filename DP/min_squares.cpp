/*
	Min squares that sum up to given sum
	(same to coin change)
	Generate your denominations as numbers less thn sqrt(n)
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
int minSquares(vector<int> &a,int s)
{
	if(s==0)
		return 0;
	int cMin = INT_MAX;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<=s)
		{
			if(m.find(s-a[i]) != m.end())
				cMin = min(cMin,m[s-a[i]]);
			else
			{
				cMin = min(cMin, minSquares(a,s-a[i]) );
				m[s-a[i]] = cMin;
			}
		}
		
	}
	return cMin + 1;
}
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	for(int i=1;i<=sqrt(n);i++)
		a.push_back(i*i);
	int ans = minSquares(a,n);
	cout << ans << endl;
}