/*
    handle - pruvi007
    questionName - 
    Contest - 
    Topic - 
    Platform - 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define MOD          1000000007
#define Vi           vector<ll> 
#define Vs           vector<string>
#define VI           vector<vector<ll> >
#define PII          pair<ll,ll> 
#define PSI          pair<string,ll>
#define PB           push_back


int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int DX[] = {0,-1,-1,-1,0,1,1,1};
int DY[] = {-1,-1,0,1,1,1,0,-1};

int getSubMatrixSum(VI &dp, int sx,int sy,int ex,int ey)
{
    // the submatrix sum will give us the matching number.
    // submatrix square denotes two subarrays of equal lengths.
    int t = dp[ex][ey];
    if( sx-1>=0 )
        t -= dp[sx-1][ey];
    if(sy-1>=0)
        t-= dp[ex][sy-1];
    if( sx-1>=0 and sy-1>=0 )
        t+= dp[sx-1][sy-1];
    return t;
}
int main()
{
    fast;
    int n,m,k;
    cin >> n >> m >> k;
    Vi a(n), b(m);
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int j=0;j<m;j++)
        cin >> b[j];
    VI dp( n,Vi(m,0) );
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]==b[j])
                dp[i][j] = 1;
            else dp[i][j] = 0;
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<m;j++)
            dp[i][j] += dp[i][j-1];
    }
    for(int i=0;i<m;i++)
    {
        for(int j=1;j<n;j++)
            dp[j][i] += dp[j-1][i];
    }


    ll c = 0;

    // O(n^3) solution
    // for(int len =k-1;len< min(n,m) ;len++){
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=0;j<m;j++)
    //         {
    //             int sx = i, sy = j;
    //             int ex = i+len, ey = j+len;
    //             if(ex<n and ey<m)
    //             {
    //                 int sum = getSubMatrixSum(dp,sx,sy,ex,ey);
    //                 // cout << sx <<","<<sy << "   "<<ex<<","<<ey << "  -> " << sum << endl;
    //                 if(sum >= k)
    //                     c++;
    //             }
                
    //         }
    //     }
    // }

    // O(n^2 lgn ) solution
    // BS on min len where square sub >= k
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int low = 0,high = min(i,j);
            int len = 0;
            while(low<high){
                int mid = (low+high)/2;
                int ex=i,ey=j;
                int sx=i-mid,sy=j-mid;
                int sum = getSubMatrixSum(dp,sx,sy,ex,ey);
                // cout << mid << " " << sx << ","<<sy<<"  " << ex<<","<<ey << "->" << sum<<endl;
                if(sum >= k)
                {
                    high = mid;
                }
                else{
                    low = mid+1;
                }
            }
            // cout << i-len << "," << j-len << "  " << i << "," << j << endl;
            // cout << min( i-len,j-len ) + 1 << endl;
            int ex=i,ey=j;
            int sx=i-low,sy=j-low;
            if(getSubMatrixSum(dp,sx,sy,ex,ey)>=k)
                c += min( i-low,j-low ) +1;
            
        }
    }

    cout << c << '\n';
}