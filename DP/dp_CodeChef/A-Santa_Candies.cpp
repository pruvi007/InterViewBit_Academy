/*
--- My CPP Template ---
@Handle: pruvi007 :)
@Name: Praveen Kumar :)
@Institution: IIIT Guwahati :)
*/

#include<bits/stdc++.h>
using namespace std;

#define fast  ios_base::sync_with_stdio(false), cin.tie(NULL) , cout.tie(NULL)
#define ll long long int 
#define ld long double
#define pb  push_back
#define mp  make_pair
#define mod 1000000007

ll power(ll x, ll n){
    if(n==0)
    return 1;
    
    if(n%2)
    return (x*power((x*x)%mod, (n-1)/2))%mod;
    else
    return power((x*x)%mod, n/2);
}

template<typename T>
class DSU{
    public:
      T parent [200005];
      T size [200005];
      void init(T x){
          parent[x] = x;
          size[x] = 1;
      }
      T root(T x){
          if(parent[x] == x)
          return x;
          return parent[x] = root(parent[x]);
      }
      void Union(T x, T y){
          x = root(x);
          y = root(y);
          if(x != y){
              if(size[x] < size[y])
              swap(x, y);
              parent[y] = x;
              size[x] += size[y];
          }
      }
};

template <typename T>
class Segment_Tree{
    public:
      ll tree[4*100005];
      ll a[100005];
      void build(ll node, ll s, ll e){
          if(s == e)
          tree[node] = a[s];
          else{
              ll mid = (s + e)/2;
              build(2*node, s, mid);
              build(2*node+1, mid+1, e);
              tree[node] = (tree[2*node] | tree[2*node+1]);
          }
      }
 
      void update(ll node, ll s, ll e, ll pos, ll val){
          if(s == e){
              tree[node] = val;
              a[pos] = val;
          }
          else{
              ll mid = (s + e)/2;
              if(pos <= mid)
              update(2*node, s, mid, pos, val);
              else
              update(2*node+1, mid+1, e, pos, val);
              tree[node] = (tree[2*node] | tree[2*node+1]);
          }
      }
 
      ll query(ll node, ll s, ll e, ll l, ll r){
          if(s >= l && e <= r)
          return tree[node];
          else if(e < l || s > r)
          return 0ll;
          else{
              ll mid = (s + e)/2;
              ll left = query(2*node, s, mid, l, r);
              ll right = query(2*node+1, mid+1, e, l, r);
              return (left | right);
          }
      }
};  

vector<int> ans;
int M = 0;
void solve( int n,int cur,int level,vector<int> temp )
{
    
    if(cur==0)
    {
        if(temp.size() >= M)
        {
            M = temp.size();
            ans = temp;
        }
        // cout << temp.size() << endl;
        // for(int i=0;i<temp.size();i++)
        //     cout << temp[i] << " ";
        // cout << endl;
        return;
    }
    if(cur<0 or level>n)
        return;

    temp.push_back(level);
    solve( n,cur-level,level+1,temp );
    temp.pop_back();
    solve( n,cur,level+1,temp);
    
        
}
int main()
{
    fast;
    /////////////////////////////////////////////////////////////////////////
    int n;
    cin >> n;
    vector<int> temp;
    solve(n,n,1,temp);
    
    cout << M << endl;
    for(int i=0;i<M;i++)
        cout << ans[i] << " ";
    cout << endl;

    ////////////////////////////////////////////////////////////////////////
    return 0;
}
