#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.length();
    int before[n],after[n];
    if( s[0]=='Q')
        before[0] = 1;
    else
        before[0] = 0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='Q')
            before[i] = before[i-1]+1;
        else
            before[i] = before[i-1];
    }
    if( s[n-1]=='Q' )
        after[n-1] = 1;
    else 
        after[n-1] = 0;
    for(int i=n-2;i>=0;i--)
    {
        if( s[i]=='Q')
            after[i] = after[i+1]+1;
        else 
            after[i] = after[i+1];
    }
    int c = 0;
    for(int i=1;i<n-1;i++)
    {
        if( s[i]=='A'  )
            c += before[i-1] * after[i+1];
    }
    cout << c << endl;
}