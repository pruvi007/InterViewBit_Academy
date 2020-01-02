#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    int c=1;
    int m = 0;
    for(int i=1;i<n;i++)
    {
        if( a[i]>a[i-1])
            c++;
        else{
            m = max(m,c);
            c=1;
        }
    }
    m = max(m,c);
    cout << m << endl;
}