#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int n,k;
    cin >> n >> k;
    int a[n][n];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];
    // prefix matrix
    for(int i=0;i<n;i++)
        for(int j=1;j<n;j++)
            a[i][j] += a[i][j-1];
    for(int i=0;i<n;i++)
        for(int j=1;j<n;j++)
            a[j][i] += a[j-1][i];
    
    int low=1,high = n;
    int ans = -1;

    // binary search on length
    while(low<=high)
    {
        int mid = (low+high)/2;
        bool valid = false;
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                int sx = i;
                int sy = i+mid-1;
                int ex = j;
                int ey = j+mid-1;
                if( sy>=n or ey>=n )
                    break;

                // O(1) calculation of total ones present in the calculated square
                int ones = a[sy][ey];
                ones -= ex-1>=0 ? a[sy][ex-1]: 0;
                ones -= sx-1>=0?a[sx-1][ey]:0;
                if( sx-1>=0 and ex-1>=0 )
                    ones += a[sx-1][ex-1];
                // cout << sx <<"," << sy << "-" <<ex<<","<<ey<<": "<<ones << '\n'; 
                if(ones<=k)
                {
                    
                    valid = true;
                    break;
                }

            }
            if(valid)
                break;
        }
        if(valid)
        {
            ans = mid;
            low = mid+1;
        }
        else high = mid-1;
    }
    cout << ans << '\n';
}