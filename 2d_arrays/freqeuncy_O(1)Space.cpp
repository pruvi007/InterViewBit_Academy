#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        cin >> a[i];
    int i = 0;
    while(i<n)
    {
        if( a[i]<=0 )
            i++;
        else
        {
            int ind = a[i]-1;
            if(a[ind]>00)
            {
                // swap with element and mark the index
                a[i]=a[ind];
                a[ind]=-1;
            }
            else
            {
                // decrement the index denoting the count
                a[ind]--;
                // mark that element as visited
                a[i]=0;
                i++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << i+1 <<": " << -a[i] << endl;
    }
}