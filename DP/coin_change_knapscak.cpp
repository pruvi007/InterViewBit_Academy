#include<bits/stdc++.h>
using namespace std;
int coinChange(int a[],int n,int k){
    int dp[n+1][k+1];
    
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            // means no element so 0
            if( i==0 )
                dp[i][j] = 0;
            // sum = 0, 1 way
            else if( j==0 )
                dp[i][j] = 1;
            else if( a[i-1] > j )
                dp[i][j] = dp[i-1][j];
            else 
                dp[i][j] = dp[i-1][j] + dp[i][j-a[i-1]];
        }
    }
    
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=k;j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return dp[n][k];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
            cin >> a[i];
        int k;
        cin >> k;
        int ans = coinChange(a,n,k);
        cout << ans << endl;
    }
}