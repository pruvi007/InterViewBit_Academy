/*
	reach a given score (use only 3 or 5 or 10)
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

map<string,int> m;
int ways(int n, vector<int> &comb,int N){
	int dp[n+1]={0};
	dp[0] = 1;
	for(int i=3;i<=n;i++)
		dp[i] += dp[i-3];
	for(int i=5;i<=n;i++)
		dp[i] += dp[i-5];
	for(int i=10;i<=n;i++)
		dp[i] += dp[i-10];
	return dp[n];
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> comb;
		int ans = ways(n,comb,n);
		cout << ans << endl;
	}
}