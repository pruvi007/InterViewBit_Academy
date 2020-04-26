#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        ll n,k;
        cin >> n >> k;
        ll a[n];
        ll tot = 0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            tot+=a[i];
        }
        if(k>=tot)
        {
            cout << tot << "\n";
        }
        else{
            priority_queue<int> pq;
            for(int i=0;i<n;i++)
            {
                if(a[i]>0)
                    pq.push(a[i]);
            }
            ll sum = 0;
            ll c = 0;
            while(!pq.empty())
            {
                ll x = pq.top();
                pq.pop();
                if(x==0)
                    break;
                sum += x;
                c++;
                if(c==k)
                    break;
                
                pq.push(x-1);
                    
            }
            cout << sum << "\n";
        }
        
    }
}