#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll solve( vector<int> a,int n )
{
    vector<int> dp(n,0);
    // here dp[i] -> number of arithmetic slices ending with A[i] ( you have to include a[i] )

    // check the first 3 numbers
    if( a[2]-a[1] == a[1]-a[0] )
        dp[2] = 1;
    ll ans = dp[2];
    for(int i=3;i<n;i++)
    {
        // if a[i] forms AP then add 1 to dp[i-1]
        if( a[i]-a[i-1] == a[i-1]-a[i-2] )
            dp[i] = dp[i-1] + 1;
        // else dp[i] will be 0 ( because our dp state demands to include current element)
        ans += dp[i];
    }
    return ans;
}
int main()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    ll ans = solve( a,n );
    cout << ans << endl;
}