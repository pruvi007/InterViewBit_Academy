/*
    suppose to maximize sum of a[i]-a[i-1] where a[i] can take values from 1 to a[i];
    idea take n*2 DP whre 0 col contains info abt current val being 1
    and 1 col contains info abt current val being a[i]; 
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i=1;i<n;i++)
        {
            // current value is 1
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]+abs(1-a[i-1]));
            // current value is a[i]
            dp[i][1] = max(dp[i-1][1]+abs(a[i]-a[i-1]), dp[i-1][0]+abs(a[i]-1));
        }
        // for(int i=0;i<n;i++)
        // {
        //     // cout << dp[i][0] << " " << dp[i][1] << endl;
        // }
        cout << max(dp[n-1][0],dp[n-1][1]) << endl;
    }
}
