/*
	find the next Smaller element i.e. NSE
*/
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
	stack<pair<int,int> > s;
	s.push({a[0],0});

	int nse[n];
	for(int i=1;i<n;i++)
	{
		if(a[i]>=s.top().first)
		{
			s.push({a[i],i});
		}
		else
		{
			while(!s.empty() && a[i]<s.top().first)
			{
				nse[s.top().second] = a[i];
				s.pop();
			}
			s.push({a[i],i});
		}
	}
	while(!s.empty())
	{
		nse[s.top().second] = -1;
		s.pop();
	}

	for(int i=0;i<n;i++)
		cout<<nse[i]<<" ";
	cout<<endl;
}