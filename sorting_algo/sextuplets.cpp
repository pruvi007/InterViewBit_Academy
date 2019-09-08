// find sextuplets such that (a*b+c)/d - e = f

// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

#define ll long long int

#define FOR(i, k, n) for(int i = k ; i < n ; i++)
const int mod = 1e9 + 7 ;
 
unordered_map <long long, int> mp ;
 
int solve(vector<int> &A) {
    mp.clear() ;
    int n = A.size() ;
    int idx = 0 ;
    long long ans = 0 ;
    FOR(i, 0, n){ // f
        FOR(j, 0, n){ // e
            FOR(k, 0, n){ // d
                if(A[k]){
                    mp[(long long)((long long)1ll*(1ll*A[i] + 1ll*A[j])*A[k])]++ ;
                }
            }
        }
    }
 
    FOR(i, 0, n){ // a
        FOR(j, 0, n){ // b
            FOR(k, 0, n){ // c
                long long ele = (long long)((long long)A[i]*A[j] + A[k]) ;
                ans = (ans + mp[ele]) ;
            }
        }
    }
    return ans%mod ;
}


int main()
{
	int n;
	cin>>n;
	int a[n];
	vector<int> A;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		A.push_back(a[i]);
	}

	int ans = solve(A);

	cout << ans << endl;
	// vector<ll> rhs;
	// // rhs = (f+e)*d , d != 0
	// // lhs = a*b+c
	// for(int i=0;i<n;i++)
	// {
	// 	if(a[i]!=0)
	// 	{
	// 		for(int j=0;j<n;j++)
	// 		{
	// 			for(int k=0;k<n;k++)
	// 			{
					
	// 				rhs.push_back((a[k]+a[j])*a[i]);
					
	// 			}
	// 		}
	// 	}
		
	// }

	// sort(rhs.begin(),rhs.end());
	// multiset<ll> s;
	// for(int i=0;i<rhs.size();i++)
	// 	s.insert(rhs[i]);

	// ll c = 0;
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		for(int k=0;k<n;k++)
	// 		{
	// 			ll l = a[i]*a[j]+a[k];
	// 			if(s.find(l)!=s.end())
	// 				c = (c + *s.upper_bound(l) - *s.lower_bound(l) )%mod;

	// 		}
	// 	}
	// }
	// cout<<c<<endl;

}