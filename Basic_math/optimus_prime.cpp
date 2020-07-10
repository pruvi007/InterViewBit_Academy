#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll factorSum(ll n){
	ll s = 0;
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){
			if(n/i == i)
				s += i;
			else{
				s += n/i;
				s += i;
			}
		}
	}
	return s;
}
vector<ll> sieve(){
	ll M = 1000001;
	vector<ll> p(M+1,-1);
	for(int i=2;i<=M;i++){
		int l = 2;
		while(i*l<=M){
			p[i*l]=1;
			l+=1;
		}
	}
	vector<ll> ans;
	for(int i=2;i<p.size();i++){
		if(p[i]==-1)
			ans.push_back(i);
	}
	return ans;
}
int main(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	ll s = 0;
	for(int i=0;i<n;i++){
		cin >> v[i];
		s += factorSum(v[i]);
	}
	vector<ll> p = sieve();
	// for(int i=0;i<20;i++)
	// 	cout << p[i] << " ";
	// cout << endl;
	ll dp[s+1];
	for(int i=0;i<=s;i++)
		dp[i] = INT_MAX;
	dp[0] = 0;
	
	for(int i=0;i<=s;i++){
		for(int j=0;;j++){
			if(p[j]>s)
				break;
			if( i>=p[j] and dp[i-p[j]]!=INT_MAX)
				dp[i] = min(dp[i],dp[i-p[j]]+1);
		}
	}
	// cout << endl;
	// for(int i=0;i<=s;i++)
	// 	cout << i << ": " << dp[i] << "  ";
	ll ans = dp[s];
	if(dp[s]==INT_MAX)
		ans = -1;
	cout << ans << '\n';
}