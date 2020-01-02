#include<bits/stdc++.h>
using namespace std;
int INF = 1e9+7;

// dp version
map<int,int> m;
int solve( int n ){
    if( n==0 )
        return 0;
    if( n<0 )
        return INF;
    if( m.find(n)!=m.end() )
        return m[n];
    int a=0,b=0,c=0,d=0,e=0;
    a = 1+ solve(n-1);
    b =  1+solve(n-5);
    c = 1+ solve(n-10);
    d = 1+ solve(n-20);
    e =  1+solve(n-100);
    m[n] = min( a,min(b,min(c,min(d,e))));
    return m[n];
}

// however a greedy version will also work because all the denomination are divisor of the previous
int min_den(int n )
{
    int c = 0;
    int den[] = {1,5,10,20,100};
    for(int i=4;i>=0;i--)
    {
        if( n>=den[i] )
        {
            int d = n/den[i];
            c += d;
            n -= den[i]*d;
        }
        
    }
    return c;
}
int main()
{
    int n;
    cin >> n ;
    int ans = min_den( n );
    cout << ans << endl;
}