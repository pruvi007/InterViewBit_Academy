#include<bits/stdc++.h>
using namespace std;

int getCount( int n,int b,int c )
{
    int g = __gcd(b,c);
    int l = b*c/g;
    return n/b + n/c - n/l;
}
int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int low = 1,high = 1e9;
    int ans;
    while( low<=high )
    {
        int mid = (low+high)/2;

        // get the total count of number for this mid
        // that would be mid/a + mid/b - mid/lcm(a,b)
        // according to this count adjust low and high
        int count = getCount( mid,b,c );
        if( count < a )
        {
            ans = mid;
            low = mid+1;
        }
        else 
            high = mid-1;
    }
    cout << low << endl;
}