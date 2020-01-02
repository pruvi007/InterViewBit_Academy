#include<bits/stdc++.h>
using namespace std;

int M = 0;
vector<int> fix,ans;
bool valid(vector<int> a,int n,int k)
{
    bool flag = false;
    for(int i=1;i<n;i++)
    {
        if( a[i]+a[i-1] < k )
            return false;
    }
    return true;
}
void solve( vector<int> a,int n,int level,int k )
{
    if(level==n)
    {
        

        if( valid(a,n,k) )
        {
            int c = 0;
            for(int i=0;i<n;i++)
            {
                // cout << a[i] << " ";
                c += abs(fix[i]-a[i]);
            }
            if( c<M )
            {
                ans = a;
                M = c;
            }    
            // cout << endl;
            
        }
        return ;
    }
    int x = a[level];
    if( (a[level]+a[level-1]) < k )
    {
        int d = k - (a[level]+a[level-1]);
        a[level] += d;
        solve( a,n,level+1,k );

        a[level] = x;
        solve( a,n,level+1,k );
        
    }
    a[level] = x;
    solve( a,n,level+1,k );
}
int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        fix.push_back(a[i]);
    }
    // solve( a,n,1,k );
    for(int i=1;i<n;i++)
    {
        int d = a[i]+a[i-1];
        if( d<k )
        {
            a[i] += (k-d);
            M += (k-d);
        }
            
    }
    cout << M << endl;
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    cout << endl;
}