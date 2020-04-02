#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];

int recur(int ind, int cnt, int last, vector<int> &a, int n,int k) 
{ 
    if (cnt == k) 
        return 0; 
    if (ind == n) 
        return -1e9; 
  
    if (dp[ind][cnt] != -1) 
        return dp[ind][cnt]; 
    int ans = 0; 
    for (int i = ind; i < n; i++)  
    { 
       
        if (cnt % 2 == 0) 
            ans=max(ans,recur(i + 1, cnt + 1, i, a, n,k)); 

        else
            ans = max(ans, __gcd(a[last], a[i]) +  recur(i + 1, cnt + 1, 0, a, n,k)); 
    } 
  
    return dp[ind][cnt] = ans; 
} 
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    int k;
    cin >> k;
    int m = 0;
    for(int i=2;i<=2*k;i+=2)
    {
        memset(dp,-1,sizeof(dp));
        int ans = recur(0,0,0,a,n,i);
        m = max(ans,m);
    }
    
    cout << m << endl;
}