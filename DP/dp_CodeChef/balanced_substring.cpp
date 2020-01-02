#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a[n];
    for(int i=0;i<n;i++)
    {
        if( s[i]=='1')
            a[i]=1;
        else
            a[i]=-1;
    }
    int dp[n];
    map<int,int> mp;
    mp[0] = 0;
    dp[0] = a[0];
    int ans = 0;
    mp[a[0]] = 1;
    for(int i=1;i<n;i++)
    {
        dp[i] = dp[i-1] + a[i];
        if(  mp.find(dp[i])!=mp.end() )
        {
            int len = i-mp[dp[i]]+1;
            ans = max(ans,len);
        }
        else
            mp[dp[i]] = i+1;
    }
    // for(int i=0;i<n;i++)
    //     cout << dp[i] << " ";
    // cout << endl;
    cout << ans << endl;    
    
}