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

int getValue(string s)
{
    int c = 0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == 'c')
            c+=4;
        else if(s[i]=='w')
            c+=3;
        else if(s[i]=='m')
            c+=2;
        else c+=1;
    }
    return c*s.length();
}
int solveKnapSack(int k,vector<string> &s)
{
    vector<pair<int,int> > a;
    int n = s.size();
    for(int i=0;i<s.size();i++)
    {
        int v = getValue(s[i]);
        a.push_back({v,s[i].length()});
    }
    int dp[n+1][k+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            int value = a[i-1].first;
            int size = a[i-1].second;
            if(i==0 or j==0)
                dp[i][j] = 0;
            else if( size <= j )
                dp[i][j] = max( value + dp[i-1][j-size], dp[i-1][j] );
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}
int main()
{
    fast;
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<string> s;
    for(int i=0;i<n;i++)
        cin >> s[i];
    int ans = solveKnapSack(k,s);
    cout << ans << '\n';
}