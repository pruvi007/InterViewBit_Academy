#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll m = INT_MAX;

bool bs(vector<ll> &v,ll x)
{
	int low = 0,high = v.size()-1;
	while(low<=high)
	{
		int mid = (low+high)/2;
		if( v[mid] == x)
			return true;
		else if(v[mid] > x)
			high = mid-1;
		else
			low = mid+1;
	}
	return false;
}
void fair_cut(ll a[],ll n,vector<ll> t1, ll l,ll k)
{
	if( l==n )
	{
		if(t1.size() == k)
		{
			// for(int i=0;i<k;i++)
			// 	cout << t1[i] << " ";
			// cout << endl;
			vector<ll> t2;
			int flag[n]={0};
			sort(t1.begin(),t1.end());
			for(int i=0;i<n;i++)
			{
				bool p = bs(t1,a[i]);
				if(!p)
					t2.push_back(a[i]);
			}
			// for(int i=0;i<k;i++)
			// 	cout << t1[i] << " ";
			// cout << " : ";
			// for(int i=0;i<t2.size();i++)
			// 	cout << t2[i] << " ";
			// cout << endl;
			ll s = 0;
			for(int i=0;i<k;i++)
			{
				for(int j=0;j<t2.size();j++)
				{
					s += abs(t1[i] - t2[j]);
				}
			}
			m = min(s,m);
		}
		return ;
	}

	t1.push_back(a[l]);
	fair_cut(a,n,t1,l+1,k);

	t1.pop_back();
	fair_cut(a,n,t1,l+1,k);

}
int main()
{
	int n,k;
	cin >> n >> k;
	ll a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	vector<ll> t1,t2;
	fair_cut(a,n,t1,0,k);
	cout << m << endl;
}