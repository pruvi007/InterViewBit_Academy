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

int minVal(int x, int y) { return (x > y)? x: y; }    
int getMid(int s, int e) { return s + (e -s)/2; }  
int RMQUtil(Vi &st, int ss, int se, int qs, int qe, int index)  
{  
    if (qs <= ss && qe >= se)  
        return st[index];  
  
    if (se < qs || ss > qe)  
        return INT_MIN;  
    int mid = getMid(ss, se);  
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),  
                RMQUtil(st, mid+1, se, qs, qe, 2*index+2));  
}  
int RMQ(Vi &st, int n, int qs, int qe)  
{  
    // Check for erroneous input values  
    if (qs < 0 || qe > n-1 || qs > qe)  
    {  
        return -1;  
    }  
  
    return RMQUtil(st, 0, n-1, qs, qe, 0);  
}  
int constructSTUtil(Vi &a, int ss, int se, Vi &st, int si)  
{  
    if (ss == se)  
    {  
        st[si] = a[ss];  
        return a[ss];  
    }  
  
    int mid = getMid(ss, se);  
    st[si] = minVal(constructSTUtil(a, ss, mid, st, si*2+1),  
                    constructSTUtil(a, mid+1, se, st, si*2+2));  
    return st[si];  
}  

Vi constructST(Vi &a, int n)  
{  
    // Allocate memory for segment tree  
    int x = (int)(ceil(log2(n)));  
    int max_size = 2*(int)pow(2, x) - 1;  
  
    Vi st(max_size,0);  
    constructSTUtil(a, 0, n-1, st, 0);  
    return st;  
}  

int main()
{
    fast;
    ll n,k;
    cin >> n >> k;
    Vi a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    Vi tree = constructST(a,n);
    ll s = 0;
    for(int i=0;i<n;i++){
        int low = i, high = n-1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            ll M = RMQ( tree,n,i,mid );
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