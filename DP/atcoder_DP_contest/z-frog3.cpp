#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll INF = 1e14+7;
int main()
{
    ll n,c;
    cin >> n >> c;
    vector<ll> h(n);
    for(int i=0;i<n;i++)
        cin >> h[i];
    ll dp[n];
    dp[0] = 0;
    for(int i=1;i<n;i++)
    {
        dp[i] = INF;
        for(int j=0;j<i;j++)
        {
            dp[i] = min( dp[i], dp[j]+(h[j]-h[i])*(h[j]-h[i])+c );
        }
    }
    cout << dp[n-1] << endl;

}