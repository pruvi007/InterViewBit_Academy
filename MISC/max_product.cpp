#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    ll dp[n+1][sum];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=(1+sum/2);j++)
        {
            if( i==0 or j==0)
                dp[i][j] = 0;
            else if( a[i-1]<=i )
                dp[i][j] = max( a[i-1]+dp[i-1][j-a[i-1]],dp[i-1][j] );
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    ll s1 = dp[n][1+sum/2];
    ll s2 = sum - s1;
    cout << s1 << " " << s2 << endl;
    cout << s1*s2 << endl;
       
    
}