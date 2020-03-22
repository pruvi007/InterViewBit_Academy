#include<bits/stdc++.h>
using namespace std;

int valid(int x, int m,int n ,int k)
{
    int c = 0;
    int flag = 0;
    for(int i=1;i<=n;i++)
    {
       
        // number less than equal to x in the ith table
        int less = x/i;
        c+= min(m,less); 
    }
    
    cout <<" " << x << " " << c << endl;
    return c>=k;
}
int main()
{
    int m,n,k;
    cin >> m >> n >> k;
    int low = 1,high = m*n;
    int ans=-1;
    while( low<=high )
    {
        int mid = (low+high)/2;
        cout << "Mid: " << mid << endl;
        if( valid(mid,m,n,k) )
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    cout << ans << endl;
}