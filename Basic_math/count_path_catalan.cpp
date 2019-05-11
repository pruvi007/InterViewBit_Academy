

// this time while counting paths .. no path can cross the major diagonals.
// the idea of catalan numbers came from the fact that if H is greater than H, then we will cross the major diagonal. So always H is less than V

// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = 1e9 + 7;
ll binomialCoeff(ll n, ll k) 
{ 
    ll res = 1; 
  
    // Since C(n, k) = C(n, n-k) 
    if (k > n - k) 
        k = n - k; 
  
    // Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
    for (int i = 0; i < k; ++i) 
    { 
        res = (res%mod * (n - i)%mod)%mod; 
        res /= (i + 1); 
    } 
  
    return res; 
} 
  

ll catalan(ll n) 
{ 
    // Calculate value of 2nCn 
    ll c = binomialCoeff(2*n, n); 
  
    // return 2nCn/(n+1) 
    return c/(n+1); 
} 
int main()
{
	int n;
	cin>>n;

	
	ll cat[n];
	cat[0] = 1;
	cat[1] = 1;

	// catalan number  = (1/n+1) * 2n C n  for nth catalan number
	for(int i=2;i<=n;i++)
	{
		cat[i] = catalan(i)%mod;
	}
	cout<<cat[n]<<endl;

}