#include<bits/stdc++.h>

using namespace std;

const int me = 100025;
const int sz = 1200000000;

struct node{
    int sum;
    node *l, *r;
    
    node() {}
};
typedef node * pnode;

int get(pnode &t){
    return t ? t->sum : 0;
}
pnode Init(int sum){
    pnode p = (pnode)malloc(sizeof(node));
    p->sum = sum;
    p->l = NULL;
    p->r = NULL;
    return p;
}
void add(int low, int high, pnode &root, int pos, int value){
    if(!root)
        root = Init(0);
    if(low == high){
        root->sum += value;
        return;
    }
    int mid = (low + high) >> 1;
    if(pos <= mid)
        add(low, mid, root->l, pos, value);
    else add(mid + 1, high, root->r, pos, value);
    root->sum = get(root->l) + get(root->r);
}
int get(int low, int high, pnode &root, int l, int r){
    if(low > r || high < l)
        return 0;
    if(!root)
        return 0;
    if(low >= l && high <= r)
        return root->sum;
    int mid = (low + high) >> 1;
    return get(low, mid, root->l, l, r)
    + get(mid + 1, high, root->r, l, r);
}
int Kth_element(int low, int high, pnode &root, int k){
    if(low == high)
        return low;
    int mid = (low + high) >> 1;
    int on_left = get(root->l);
    if(on_left >= k)
        return Kth_element(low, mid, root->l, k);
    else return Kth_element(mid + 1, high, root-> r, k - on_left);
}

int n, q, type, x,l,r;
pnode root;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    
    root = Init(0);
    
    // scanf("%d%d", &n, &q);
    // for(int i = 1; i <= n; i ++){
    //     scanf("%d", &x);
    //     add(1, sz, root, x, 1);
    // }
    scanf("%d",&q);
    vector<int> ans;
    map<int,int> mp;
    int m =INT_MAX;
    int M=INT_MIN;
    while(q --){
        scanf("%d%d%d", &type, &l,&r);
        if(type == 1){
            // int cnt = get(1, sz, root, 1, x);
            add(1, sz, root, l, 1);
            mp[l]++;
            if(l<m)
                m = l;
            if(l>M)
                M = l;
        }
        else if(type == 2){
            if( (l<m and r<m)  or (l>M and r>M) )
            {
                cout << 0 << endl;
                ans.push_back(0);
            }
            else if(l==r)
            {
                ans.push_back(mp[l]);
                cout << mp[l] << endl;
            }
                
            else
            {
                int A = get(1, sz, root, 1, l);
                int B = get(1, sz, root, 1, r);
                // printf("%d\n", get(1, sz, root, 1, x));
                if(mp.find(l)!=mp.end())
                    A -= mp[l];
               
                cout << l <<","<<r<<" : " << A << " " << B <<"-> " ;
                int anss ;
                if(A==0)
                {
                   
                    anss = B;
                }
                    
                else
                {

                    anss = B-A;
                }
                    
                cout << anss << endl;
                ans.push_back(anss);
            }
           
        }
        // else{
        //     if(get(root) < x)
        //         printf("invalid\n");
        //     else printf("%d\n", Kth_element(1, sz, root, x));
        // }
    }
    for(int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}