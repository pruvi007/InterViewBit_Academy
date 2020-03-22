#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &a,int k)
{
    int n = a.size();
    int dp[k+1];
    for(int i=0;i<=k;i++)
        dp[i] = INT_MAX;
    dp[0] = 0;
    for(int i=0;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if( a[j]<=i and dp[i-a[j]]!=INT_MAX)
            {
                dp[i] = min( dp[i], dp[i-a[j]] + 1);
            }
        }
    }
    return dp[k];
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    int am;
    cin >> am;
    int ans = solve(a,am);
    cout << ans << endl;

}