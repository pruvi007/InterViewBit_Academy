#include<bits/stdc++.h>
using namespace std;

int getGoodArrays(vector<int> a,int n,int k)
{
    unordered_map<int,int> mp;
    int count = 0;
    for(int len=k;len<=n;len++)
    {
        for(int i=0;i<len;i++)
        {
            mp[a[i]]++;
        }
        for(int i=len;i<=n;i++)
        {
            // cout << "start:" << i-len << ", ENd: " << i << ", Size: " << mp.size() << endl;
            if( mp.size()==k )
                count++;
            mp[ a[i-len] ]--;
            if( mp[a[i-len]]==0 )
                mp.erase(a[i-len]);
            if(i<n)
            mp[a[i]]++;
        }
        mp.clear();
    }
    return count;
}
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    // the following method is O( n^2 ) -> for each length use slifing window and map to count required good subarrays
    int ans = getGoodArrays(a,n,k)
    
    
}