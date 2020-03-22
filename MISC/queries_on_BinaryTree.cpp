#include<bits/stdc++.h>
using namespace std;

#define  ll long long int

int getCumulativeValueFromParents( map<int,int> mp,int node )
{
    int value = 0;
    while( node )
    {
        int parent = node;
        if( mp.find(parent)!=mp.end() )
        {
            value += mp[parent];
        }
        node /= 2;
    }
    return value;
}
int main()
{
    // given a complete tree consisiting 2^31 nodes
    int q;
    cin >> q;
    map<int,int> mp;
    while( q-- )
    {
        int ch;
        cin >> ch;
        if( ch==1 )
        {
            int n,d;
            cin >> n >> d;
            mp[n] += d;
        }
        else
        {
            int x,z;
            cin >> x >> z;
            int ans = getCumulativeValueFromParents( mp,x );
            cout << ans << endl;
        }
        
    }
}