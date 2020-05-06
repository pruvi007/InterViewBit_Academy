#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin >> n;
    ll a[n],h[n];
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> a[i];

    // get the LIS in nlgn
    ll lis[n]={0},b[n]={0};
    lis[0] = h[0];b[0] = a[0];
    int l = 1;
    for(int i=1;i<n;i++)
    {

        for(int j=0;j<l;j++)
            cout << lis[j] << " ";
        cout << endl;
        for(int j=0;j<l;j++)
            cout << b[j] << " ";
        cout << endl;
        cout << endl;


        int p = lower_bound( lis,lis+l,h[i] ) - lis;
        ll x = a[i];
        if( p>0 )
            x += b[p-1];
        lis[p] = h[i];
        b[p] = max( b[p],x );
        if( p==l )
            l++;

        
    }
    for(int i=0;i<l;i++)
        cout << lis[i] << " ";
    cout << endl;
    for(int i=0;i<l;i++)
        cout << b[i] << " ";
    cout << endl;
    
   
    return 0;
}