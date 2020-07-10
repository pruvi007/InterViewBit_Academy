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

const int N = 1e6+1;
const int K = 21;
int n,k;
int table[N][K];
int numlog[N];
Vi a(N);
void build(){
    numlog[1] = 0;
    for (int i = 2; i < N; i++)
        numlog[i] = numlog[i/2] + 1;
    for (int i = 0; i < n; i++)
        table[i][0] = a[i];
    for (int j = 1; j < K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            table[i][j] = max(table[i][j-1], table[i + (1 << (j - 1))][j - 1]);
}
int query(int l ,int r){
    int curlog = numlog[r - l + 1];
    return max(table[l][curlog] , table[r - (1 << curlog) + 1][curlog]);
}

int main()
{
    fast;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    build();
    ll s = 0;
    for(int i=0;i<n;i++){
        int low = i, high = n-1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            ll M = query( i,mid );
            // cout << i <<"," << mid << " -> " << M << endl;
            if( M - a[i]<=k )
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        // cout << ans << endl;
        if(ans!=-1)
            s += ans - i + 1;
    }
    cout << s << '\n';

}