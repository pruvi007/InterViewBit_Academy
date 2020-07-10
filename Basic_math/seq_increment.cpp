#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1e9+7;

ll power(ll a,ll b){
	ll s = 1;
	while(b){
		if(b&1)
			s = (s%mod*a%mod)%mod;
		a = (a%mod * a%mod)%mod;
		b /= 2;
	}
	return s;
}
ll solve(ll a,ll b, ll c, ll x, ll n){
	ll M = (a%mod * b%mod)%mod;
	ll s = n*power(c, a*b-x );
	M -= a;
	while(M>0)
	{
		s += n*power(c,M-x);
		M -= a;
	}
	return s;

}
int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	vector<ll> v(a);
	for(int i=0;i<a;i++)
		cin >> v[i];
	ll s = 0;
	for(int i=0;i<a;i++){
		s = s + solve(a,b,c,i,v[i]);
		s %= mod;
	}
	cout << s%mod << '\n';
}