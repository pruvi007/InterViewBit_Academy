/*
	find the area of largest histogram 
	Approach: find the next Smaller and previous Smaller during precomputation to get the width.
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
	int nse[n],pse[n];
	stack<pair<int,int> > s;
	
	// calculating NSE
	s.push({a[0],0});
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
				nse[s.top().second] = i;
				s.pop();
			}
			s.push({a[i],i});
		}
	}
	while(!s.empty())
	{
		nse[s.top().second] = n-1;
		s.pop();
	}


	// calculating PSE
	s.push({a[n-1],n-1});
	for(int i=n-2;i>=0;i--)
	{
		if(a[i]>=s.top().first)
		{
			s.push({a[i],i});
		}
		else
		{
			while(!s.empty() && a[i]<s.top().first)
			{
				pse[s.top().second] = i;
				s.pop();
			}
		}
		s.push({a[i],i});
	}
	while(!s.empty())
	{
		pse[s.top().second] = 0;
		s.pop();
	}

	for(int i=0;i<n;i++)
		cout<<nse[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<pse[i]<<" ";
	cout<<endl;

	// calculate max area
	int max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		int x = a[i]*abs(nse[i]-pse[i]);
		if(x>max)
			max = x;
	}
	cout<<max<<endl;


}