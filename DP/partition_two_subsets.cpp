#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &a,int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += a[i];
    int dp[sum+1][n+1];
    for(int i=0;i<=sum;i++)
        dp[i][0] = 0;
    for(int i=0;i<=n;i++)
        dp[0][i] = 0;

    for(int i=1;i<=sum;i++)
    {
        // cout << "Sum: "<<i << "-> ";
        for(int j=1;j<=n;j++)
        {
            if(a[j-1]<=i)
                dp[i][j] = max( a[j-1]+ dp[i-a[j-1]][j-1],dp[i][j-1]);
            else 
                dp[i][j] = dp[i][j-1];
        }
        
    }
    // for(int i=0;i<=sum;i++)
    // {
    //     for(int j=0;j<=n;j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return (sum-dp[sum/2][n])*dp[sum/2][n] ;
}
int main()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    int ans = solve(a,n);
    cout << ans << endl;
}