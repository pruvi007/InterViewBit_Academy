#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+1;
int dp[MAXN][MAXN];


bool solve(string a,string b,int sa,int sb,int n,int m)
{
    if( sa==n )
    {
        if( sb==m )
            return true;
        return false;
    }
    if( dp[sa][sb]!=-1 )
        return dp[sa][sb];

    bool x,y;
    if( a[sa]==b[sb] or char(a[sa]-32) == b[sb] )
    {
        // either go to next of both chars or remain at B
        x = solve( a,b,sa+1,sb+1,n,m ) or solve( a,b,sa+1,sb,n,m ) ;
        dp[sa][sb] = int(x);
    }
        
    else if( a[sa]!=b[sb] )
    {

        // can be skipped if only lowercase 
        if( a[sa]>='a' and a[sa]<='z' )
        {
             y = solve( a,b,sa+1,sb,n,m );
            dp[sa][sb] = int(y);
        }
        // if upperCase then directly return false
        else
        {
            return false;
        }
       
    }
    else
        dp[sa][sb] = 0;
    
    return bool(dp[sa][sb]);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a,b;
        cin >> a;
        cin >> b;
        int n = a.length();
        int m = b.length();
        bool ans = solve( a,b,0,0,n,m );
        cout << ans << endl;
    }
}