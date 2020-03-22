#include<bits/stdc++.h>
using namespace std;

int dp[501][501];
int stoneGame(vector<int> a,int n,int l,int r)
{
    if( r==l+1 )
        return max( a[l],a[r] );
    if(dp[l][r]!=-1)
        return dp[l][r];

    int x = a[l] + max( stoneGame(a,n,l+1,r-1),stoneGame(a,n,l+2,r) );
    int y = a[r] + max( stoneGame(a,n,l+1,r-1),stoneGame(a,n,l,r-2) );

    dp[l][r] = max(x,y);
    return dp[l][r];
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    memset( dp,-1,sizeof(dp) );
    int alex = stoneGame( a,n,0,n-1 );
    int lee = sum - alex;
    cout << alex << " " << lee << endl;
    cout << (alex>lee ? true:false) << endl;;
}