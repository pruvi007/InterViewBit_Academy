#include<bits/stdc++.h>
using namespace std;

int LBS(vector<pair<int,int> > &v,int k)
{
    int low = 0,high = v.size()-1;
    int ans = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if( v[mid].first == k )
        {
            ans = v[mid].second;
            low = mid+1;
        }
        else if( v[mid].first < k)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
    }
    return ans;
}

int SBS(vector<pair<int,int> > &v,int k)
{
    int low = 0,high = v.size()-1;
    int ans = -1;
    while(low<=high)
    {
        int mid = (low+high)/2;
        if( v[mid].first==k )
        {
            ans = v[mid].second;
            high = mid-1;
        }
        else if( v[mid].first < k)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
        
        
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        map<char,vector<pair<int,int>> > mp;
        int n,q;
        cin >> n >> q;
        string s;
        cin >> s;
        for(int i=0;i<n;i++)
        {
            char ch = s[i];
            if(mp.find(ch)!=mp.end())
            {
                vector<pair<int,int> > v = mp[ch];
                int curCount = v[ v.size()-1 ].first;
                v.push_back( pair<int,int>{curCount+1,i} );
                mp[ch] = v;
            }
            else
            {
                mp[ch].push_back( pair<int,int>{1,i} );
            }
            for(int j=0;j<26;j++)
            {
                char c = char(97+j);
                if(c==ch)
                    continue;
                else
                {
                    if(mp.find(c)!=mp.end())
                    {
                        vector<pair<int,int> > v = mp[c];
                        int curCount = v[ v.size()-1 ].first;
                        v.push_back( pair<int,int>{curCount,i} );
                        mp[c] = v;
                    }
                    else
                    {
                        mp[c].push_back( pair<int,int>{0,i} );
                    }
                }
                
            }
        }
        // for(auto it=mp.begin();it!=mp.end();it++)
        // {
        //     vector<pair<int,int> > v = it->second;
        //     for(int i=0;i<v.size();i++)
        //         cout << v[i].first << "," << v[i].second <<"  ";
        //     cout << endl;
        // }
        while(q--)
        {
            char ch,x;
            int k;
            cin >> ch >> x >> k;
            if(ch=='L')
            {
                if(mp.find(x)==mp.end())
                    cout << 0 << "\n";
                else{
                    vector< pair<int,int> > v = mp[x];
                    int last = LBS( v,k );
                    cout << last+1 << "\n";
                }
            }
            else{
                if(mp.find(x)==mp.end())
                    cout << 0 << "\n";
                else{
                    vector< pair<int,int> > v = mp[x];
                    int last = SBS( v,k );
                    cout << last+1 << "\n";
                }
            }
        }
    }
}