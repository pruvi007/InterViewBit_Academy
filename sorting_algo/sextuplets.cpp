// find sextuplets such that (a*b+c)/d - e = f

// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = 1e9+7;
int main()
{
	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	vector<ll> rhs;
	// rhs = (f+e)*d , d != 0
	// lhs = a*b+c
	for(int i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					
					rhs.push_back((a[k]+a[j])*a[i]);
					
				}
			}
		}
		
	}

	sort(rhs.begin(),rhs.end());
	multiset<ll> s;
	for(int i=0;i<rhs.size();i++)
		s.insert(rhs[i]);

	ll c = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				ll l = a[i]*a[j]+a[k];
				if(s.find(l)!=s.end())
					c = (c + *s.upper_bound(l) - *s.lower_bound(l) )%mod;

			}
		}
	}
	cout<<c<<endl;

}