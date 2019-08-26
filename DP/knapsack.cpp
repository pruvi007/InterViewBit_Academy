/*
    0/1 KnapSack
    Recursive + Tabular

*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll ans = 0;
ll knapSack(int s[],int v[],int n,int level,int c){
    if( level==-1 || c==0 )
        return 0;
    if( s[level]>c )
        return knapSack( s,v,n,level-1,c );
    else{
        ll a = knapSack( s,v,n,level-1,c );
        ll b = v[level] + knapSack( s,v,n,level-1,c-s[level] );
        return max( a,b );
        
    }
}

ll knapSackTable(int s[],int v[],int n,int c){
    ll dp[n+1][c+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=c;j++)
        {
            if( i==0 || j==0 )
                dp[i][j] = 0;
            else if( s[i-1] <= j )
                dp[i][j] = max( v[i-1]+dp[i-1][ j-s[i-1] ], dp[i-1][j] );
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][c];
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int c,n;
        cin >> c >> n;
        int v[n];
        int s[n];
        ans = 0;
        for(int i=0;i<n;i++)
        {
            cin >> s[i] >> v[i];
        }
        ll res = knapSack( s,v,n,n-1,c );
        cout << res << endl;

        res = knapSackTable( s,v,n,c );
        cout << res << endl;
    }
}