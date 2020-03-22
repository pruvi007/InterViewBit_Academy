
#include<bits/stdc++.h>
using namespace std;

int BS_start( vector<int> &v,int x  )
{
    int low = 0,high = v.size()-1;
    int ans = -1;
    while( low<=high )
    {
        int mid = (low+high)/2;
        if( v[mid]>=x )
        {
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;
    }
    return ans;
}

int BS_end( vector<int> &v,int x  )
{
    int low = 0,high = v.size()-1;
    int ans = -1;
    while( low<=high )
    {
        int mid = (low+high)/2;
        if( v[mid]<=x )
        {
            ans = mid;
            low = mid+1;
        }
        else
            high = mid-1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    // My idea: maintain a list against each number consisiting of (i,j) denoting the subarray i..j wjich contains num
    map< int,vector<int> > mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]].push_back(i);
    }
    for(auto it = mp.begin();it!=mp.end();it++)
    {
        vector<int> p = it->second;
        cout << it->first << " : ";
        for(int i=0;i<p.size();i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while( q-- )
    {
        int l,r,t;
        cin >> l >> r >> t;
        int maj = 0;
        int ans = -1;
        for( auto it=mp.begin();it!=mp.end();it++ )
        {
            int cur = it->first;
            vector<int> v = it->second;
           
            if( v.size() < t)
                continue;
            int start = BS_start( v,l );
            int end = BS_end( v,r );
            cout << cur << ":"<<start << " " << end << endl;
            if( end-start+1 >= t )
            {
                ans = cur;
                break;
            }
        }
        cout << ans << endl;

    }
}