#include<bits/stdc++.h>
using namespace std;

int solve( vector<pair<int,int> > v, int n ,int zero,int one )
{
    // dp[i][j] -> max no. of substrings with i zeros and j ones
    vector< vector<int> > dp( zero+1, vector<int>(one+1, 0) );

    for(int k=0;k<v.size();k++)
    {
        int z = v[k].first;
        int o = v[k].second;
        for(int i=z;i>=0;i--)
        {
            for(int j=o;j>=0;j--)
            {
                
                dp[i][j] = max( dp[i][j], dp[i - z][j - o]+1 );
            }
        }
    }
    return dp[zero][one];

}
int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    int z,o;
    cin >> z >> o;
    vector< pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        int l = a[i].length();
        int c = 0;
        for(int j=0;j<l;j++)
        {
            if( a[i][j]=='1' )
                c++;
        }
        v.push_back( {l-c,c} );
    }
    int ans = solve( v,n,z,o );
    cout << ans << endl;
}