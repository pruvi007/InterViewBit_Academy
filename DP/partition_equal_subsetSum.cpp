#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &a,int sum)
{
    int n = a.size();
    if(sum%2)
        return false;
    else
    {
        bool dp[sum+1][n+1];
        for(int i=0;i<=sum;i++)
        {
            for(int j=0;j<=n;j++)
            {
                // zero sum can be made everytime
                if(i==0)
                    dp[i][j] = true;
                // if we dont select any element then false
                else if(j==0)
                    dp[i][j] = false;
                else{
                    if( a[j-1]<=i )
                        dp[i][j] = dp[i][j-1] or dp[i-a[j-1]][j-1] ;
                    else
                        dp[i][j] = dp[i][j-1];
                }
            }
        }
        // cout << dp[sum/2][n] << endl;
        return dp[sum/2][n];
    }
}

int main()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    bool ans = solve(a,sum);
    cout << ans << endl;
}