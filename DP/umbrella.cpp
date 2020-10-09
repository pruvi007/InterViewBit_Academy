/*
    handle - pruvi007
    questionName - 
    Contest - 
    Topic - 
    Platform - 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define MOD          1000000007
#define Vi           vector<ll> 
#define Vs           vector<string>
#define VI           vector<vector<ll> >
#define PII          pair<ll,ll> 
#define PSI          pair<string,ll>
#define PB           push_back


int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int DX[] = {0,-1,-1,-1,0,1,1,1};
int DY[] = {-1,-1,0,1,1,1,0,-1};

int knapSack(int k,int a[],int n)
{
    int dp[k+1];
    int MAXN = 10001;
    for(int i=0;i<=k;i++)
        dp[i] = MAXN;
    dp[0] = 0;

    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( i>=a[j] and dp[ i-a[j] ]!=MAXN)
            {
                dp[i] = min(dp[i],dp[i-a[j]]+1);
            }
        }
    }

    return dp[k]==MAXN?-1:dp[k];
}
int main()
{
    fast;
    int k;
    cin >> k;
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int ans = knapSack(k,a,n);
    cout << ans << '\n';
}