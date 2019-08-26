#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        queue< pair<int,int> > q;
        int ans;
        q.push({0,0});
        unordered_map<int,int> m;
        while( !q.empty() ){
            pair<int,int> p = q.front();
            q.pop();
            if( p.first == n )
            {
                ans = p.second;
                break;
            }
            m[p.first]++;
            int a = p.first + 1;
            int b = 2*p.first;
            if(a <= n && m.find(a)==m.end() )
                q.push({a,p.second+1});
            if(b<=n && m.find(b) == m.end() )
                q.push({b,p.second+1});
        }
        cout << ans << endl;
    }
}