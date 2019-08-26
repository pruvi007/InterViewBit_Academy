/*
    MAX SUBSEQUENCE SUM WITHOUT NON-ADJACENT ELEMTS
    state-> dp[i] denoted max subsequence sum till i with no adjacent elements
    dp[i] = max( dp[i-1], a[i]+dp[i-2] )
    handle negative elements
    if(neg) dp[i] = dp[i-1]
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            if(a[i]>0)
                flag=1;
        }
        if(flag == 0)
        {
            cout << *max_element(a,a+n) << endl;
            continue;
        }
        ll dp[n+1];
        dp[0] = a[0]>0?a[0]:0;
        dp[1] = max(dp[0],a[1]);
        for(int i=2;i<=n;i++)
        {
            if(a[i] > 0)
                dp[i] = max( a[i]+dp[i-2], dp[i-1] );
            else dp[i] = dp[i-1];
        }
        cout << dp[n-1] << endl;
    }
}