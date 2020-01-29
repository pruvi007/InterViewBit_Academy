#include<bits/stdc++.h>
using namespace std;

int dp[101][101][101];

int solve(vector<int> a,int odd,int even,int level)
{
    if(level==a.size() or (even==0 and odd==0) )
    {
        int c=0;
        for(int i=0;i<a.size();i++)
            cout << a[i] << " ";
        cout << endl;
        for(int i=1;i<a.size();i++)
        {
            if(a[i]==0)
                return INT_MAX;
            if(a[i]%2==0 and a[i-1]%2!=0)
                c++;
            else if(a[i]%2!=0 and a[i-1]%2==0)
                c++;
        }
        return c;
    }

    if(dp[odd][even][level]!=-1)
        return dp[odd][even][level];

    int x=INT_MAX,y=INT_MAX,z=INT_MAX;
    if(a[level]==0)
    {
        if(even>0)
        {
            a[level] = -2;
            x = solve( a,odd,even-1,level+1  );
        }
        if( odd>0 )
        {
            a[level]=-1;
            y = solve( a,odd-1,even,level+1 );
        }
    }
    else
        z = solve(a,odd,even,level+1);
    dp[odd][even][level] = min( x,min(y,z) );

    return dp[odd][even][level];
}
int main()
{
    int n;
    cin >> n ;
    vector<int> a(n);
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        mp[a[i]]=1;
    }
        
    int o=0,e=0;
    for(int i=1;i<=n;i++)
    {
        if(mp.find(i)==mp.end())
        {   
            if(i%2==0)
                e++;
            else 
                o++;
        }   
    }
    memset(dp,-1,sizeof(dp));
    int ans = solve( a,o,e,0 );
    cout << ans << endl;
}