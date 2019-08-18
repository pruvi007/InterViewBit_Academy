#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll mod = 1e9+7;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	ll nge[n],pge[n];

	stack<pair<int,int> > s;
	
	// calculating NGE
	s.push({a[0],0});
	for(int i=1;i<n;i++)
	{
		if(a[i] <= s.top().first)
		{
			s.push({a[i],i});
		}
		else
		{
			while(!s.empty() && a[i] > s.top().first)
			{
				nge[s.top().second] = i;
				s.pop();
			}
			s.push({a[i],i});
		}
	}
	while(!s.empty())
	{
		nge[s.top().second] = n;
		s.pop();
	}

	// calculate PGE
	s.push({a[n-1],n-1});
	for(int i=n-2;i>=0;i--)
	{
		if(a[i] <= s.top().first)
		{
			s.push({a[i],i});
		}
		else
		{
			while(!s.empty() && a[i] > s.top().first)
			{
				pge[s.top().second] = i;
				s.pop();
			}
		}
		s.push({a[i],i});
	}
	while(!s.empty())
	{
		pge[s.top().second] = -1;
		s.pop();
	}

	for(int i=0;i<n;i++)
		cout << nge[i] << " ";
	cout << endl;
	for(int i=0;i<n;i++)
		cout << pge[i] << " ";
	cout << endl;

	vector<int> ans;
	for(int i=0;i<n;i++)
	{
		ll l = abs((nge[i]-i)==0?1:(nge[i]-i));
		ll r = abs((i-pge[i])==0?1:(i-pge[i]));
		int x = (l%mod * r%mod);
		ans.push_back(x);
		cout << x << " ";
	}
	cout << endl;
}