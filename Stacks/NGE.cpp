/*
	find the next greater eleement of each eleemnt.
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
	{
		cin>>a[i];
	}
	stack<pair<int,int> > s;
	int nge[n]={-1};
	s.push({a[0],0});
	for(int i=1;i<n;i++)
	{
		

		pair<int,int> x = s.top();

		if(a[i]<=x.first)
		{
			s.push({a[i],i});
		}
		else
		{

			while(!s.empty() && a[i]>s.top().first)
			{

				nge[s.top().second] = a[i];
				s.pop();

			}
			s.push({a[i],i});
		}
	}
	while(!s.empty())
	{
		pair<int,int> p = s.top();
		nge[p.second] = -1;
		s.pop();
	}

	for(int i=0;i<n;i++)
		cout<<nge[i]<<" ";
	cout<<endl;
}