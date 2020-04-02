#include<bits/stdc++.h>
using namespace std;

int solve(int n,int steps)
{
    if(n==1)
        return steps;
    
    int b = INT_MAX;

    for(int i=2;i<n;i++)
    {
        if( n%i==0 )
        {
            b = min(b,solve(i,steps+1));
        }
    }
    b = min(b,solve(n-1,steps+1));
    return b;
}
int main()
{
    int n;
    cin >> n;
    int ans = solve(n,0);
    cout << ans << endl;
}


/*
    After solving it using DP I found a interesting fact
    1. If Even ans is 2
    2. If Odd ans is 3
    Corner -> (ans for 2 is 1 )
*/