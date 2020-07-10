/*
    handle - pruvi007
    questionName - 
    Contest - 
    Topic - 
    Platform - 
*/
#include<bits/stdc++.h>
using namespace std;
#define ll          long long int
#define fast         ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF          1e18
#define MOD          1000000007
#define Vi           vector<ll> 
#define Vs           vector<string>
#define VI           vector<vector<ll> >
#define PII          pair<ll,ll> 
#define PSI          pair<string,ll>
#define PB           push_back


int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
int DX[] = {0,-1,-1,-1,0,1,1,1};
int DY[] = {-1,-1,0,1,1,1,0,-1};

int main()
{
    fast;
    int n,q;
    cin >> n >> q;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        int low = *s.begin();
        int high = *(--s.end());
        while(low<=high){
            int mid = (low+high)/2;
            
        }
    }
}