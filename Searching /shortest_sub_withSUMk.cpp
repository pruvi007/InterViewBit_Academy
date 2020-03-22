#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n ;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int k ;
    cin >> k;
    int dp[n];
    dp[0] = a[0];
    for(int i=1;i<n;i++)
        dp[i] = dp[i-1] + a[i];
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            int subSum;
            if( i-1 >=0 )
                subSum = dp[j] - dp[i-1];
            else 
                subSum = dp[j];
            if( subSum >= k)
            {
                int len = j-i+1;
                ans = min(ans,len);
            }
        }
    }
    cout << ans << endl;
}