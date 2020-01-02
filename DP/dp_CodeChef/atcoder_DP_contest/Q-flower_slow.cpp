#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n;
    cin >> n;
    ll a[n],h[n];
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> a[i];

    ll lis[n][2] ;
    lis[0][0] = 1;
    lis[0][1] = a[0];
    for(int i=1;i<n;i++){
        lis[i][0] = 1;
        lis[i][1] = a[i];
        for(int j=0;j<i;j++)
        {
            if( h[i] > h[j] )
            {
                lis[i][0] = max( lis[i][0],lis[j][0]+1 );
                lis[i][1] = max( lis[i][1],lis[j][1]+a[i] ) ;
            }
        }
    }
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         cout << lis[j][i] << " ";
    //     cout << endl;
    // }
    cout << lis[n-1][1] << endl;
}