#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int mod = 1e9+7;
int dp[MAXN][MAXN];


// O(nK) space
int solve( int a[],int n,int l, int s ){
    if( s<0 or l>=n )
        return 0;
    if( dp[l][s]!=-1 )
        return dp[l][s];
    if( s==0 )
        return 1;

    int x = solve( a,n,l,s-a[l] )%mod;
    int y = solve( a,n,l+1,s )%mod;
    dp[l][s] = (x%mod + y%mod)%mod;
    return dp[l][s];
}

// O(K) space
int solve_space_optimized(int a[],int n,int s)
{
    int d[s+1]={0};
    dp[0] = 1;
    for(int i=0;i<n;i++)
    {
        // you can reach jth position from (j-a[i])th position
        for(int j=a[i];j<=s;j++)
            dp[j] += dp[j-a[i]];
    }
    return dp[s];
}
int main(){
    int n;
    cin >> n ;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int s;
    cin >> s;
    memset( dp,-1,sizeof(dp) );
    int ans = solve( a,n,0,s );
    cout << ans << endl;
}