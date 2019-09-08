/*
	Find the length of longest fibonacci seq
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		ll a[n];
		unordered_map<ll,ll> mp;
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			mp[a[i]]++;
		}

		ll M = 0;
		vector<ll> seq;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{

				ll x = a[i];
				ll y = a[j];
				ll z = x+y;
				vector<ll> temp{x,y};
				ll l = 2;
				while( mp.find(z) != mp.end() )
				{
					temp.push_back(z);
					x = y;
					y = z;
					z = x+y;
					l++;
				}
				if(l>M)
				{
					M = l;
					seq = temp;
				}
			}
		}
		cout << M << endl;
		for(int i=0;i<seq.size();i++)
			cout << seq[i] << " ";
		cout << endl;
	}
}