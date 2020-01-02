#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve( int a[],int n,int l,int r )
{
    if( dp[l][r]!=-1 )
        return dp[l][r];
    if( l>r )
        return 0;
    if( l==r )
        return a[l];
    
    int x = a[l] + min( solve( a,n,l+2,r ), solve( a,n,l+1,r-1) );
    int y = a[r] + min( solve( a,n,l,r-2 ), solve( a,n,l+1,r-1 ) );
    dp[l][r] = max(x,y);
    return max(x,y);
}
int main()
{
    int n;
    cin >> n ;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    memset( dp,-1,sizeof(dp) );
    int ans = solve( a,n,0,n-1 );
    cout << ans << endl;
}