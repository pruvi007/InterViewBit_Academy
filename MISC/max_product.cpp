#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    vector<ll> a1,a2;
    ll sum1=0,sum2=0;
    sort(a.rbegin(),a.rend());
    a1.push_back(a[0]);sum1=a[0];
    for(int i=1;i<n;i++)
    {
        if(sum1>sum2)
        {
            sum2+=a[i];
            a2.push_back(a[i]);
        }
        else
        {
            sum1+=a[i];
            a1.push_back(a[i]);
        }
    }
    for(int i=0;i<a1.size();i++)
        cout << a1[i] << " ";
    cout << endl;
    for(int i=0;i<a2.size();i++)
        cout << a2[i] << " ";
    cout << endl;
    cout << sum1*sum2 << endl;

    ll ans1 = sum1*sum2;
    int l1 = a1.size()-1,l2=a2.size()-1;
    while( l1>=0 and l2>=0 and a1[l1]==a2[l2] )
    {
        l1--;l2--;
    }
    int temp = a1[l1];
    a1[l1] = a2[l2];
    a2[l2] = temp;
    sum1=0;sum2=0;
    for(int i=0;i<a1.size();i++)
    {
        sum1+=a1[i];
        cout << a1[i] << " ";
    }
    cout << endl;
    for(int i=0;i<a2.size();i++)
    {
        sum2 += a2[i];
        cout << a2[i] << " ";
    }
    cout << endl;
    ll ans2 = sum1*sum2;
    cout << ans2 << endl;
}