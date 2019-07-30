/*
	MASK Updates
	updata: take xor of all bits from l to r
	query: count set bits in l to r
	solution using Segment Tree
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

#define ll long long int
ll mod = 1e9+7;
int tree[400005];
int lazy[400005];

void build(int a[],int l,int r,int pos)
{
	if(l==r)
	{
		tree[pos] = a[l];
		return;
	}
	int mid = (l+r)/2;
	// left child
	build(a,l,mid,2*pos+1);
	// right child
	build(a,mid+1,r,2*pos+2);
	tree[pos] = tree[pos*2+1]+tree[pos*2+2];
}
void updateSegmentTree(int index, int delta, int low, int high, int pos){
       
        //if index to be updated is less than low or higher than high just return.
        if(index < low || index > high){
            return;
        }
        
        //if low and high become equal, then index will be also equal to them and update
        //that value in segment tree at pos
        if(low == high){
            tree[pos] += delta;
            return;
        }
        //otherwise keep going left and right to find index to be updated 
        //and then update current tree position if min of left or right has
        //changed.
        int mid = (low + high)/2;
        updateSegmentTree(index, delta, low, mid, 2 * pos + 1);
        updateSegmentTree(index, delta, mid + 1, high, 2 * pos + 2);
        tree[pos] = tree[2*pos+1]+ tree[2*pos + 2];
    }

void updateSegmentTreeRangeLazy(int startRange, int endRange,int low, int high, int pos) {
        if(low > high) {
            return;
        }

        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if (lazy[pos] != 0) {
            tree[pos] ^= lazy[pos];
            if (low != high) { //not a leaf node
                lazy[2 * pos + 1] ^= lazy[pos];
                lazy[2 * pos + 2] ^= lazy[pos];
            }
            lazy[pos] = 0;
        }

        //no overlap condition
        if(startRange > high || endRange < low) {
            return;
        }

        //total overlap condition
        if(startRange <= low && endRange >= high) {
            tree[pos] ^= 1;
            if(low != high) {
                lazy[2*pos + 1] ^= 1;
                lazy[2*pos + 2] ^= 1;
            }
            return;
        }

        //otherwise partial overlap so look both left and right.
        int mid = (low + high)/2;
        updateSegmentTreeRangeLazy(startRange, endRange, low, mid, 2*pos+1);
        updateSegmentTreeRangeLazy(startRange, endRange, mid+1, high, 2*pos+2);
        tree[pos] =(tree[2*pos + 1] + tree[2*pos + 2]);
    }

int QueryLazy(int qlow, int qhigh,int low, int high, int pos) {

        if(low > high) {
            return 0;
        }

        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        if (lazy[pos] != 0) {
            tree[pos] ^= lazy[pos];
            if (low != high) { //not a leaf node
                lazy[2 * pos + 1] ^= lazy[pos];
                lazy[2 * pos + 2] ^= lazy[pos];
            }
            lazy[pos] = 0;
        }

        //no overlap
        if(qlow > high || qhigh < low){
            return 0;
        }

        //total overlap
        if(qlow <= low && qhigh >= high){
            return tree[pos];
        }

        //partial overlap
        int mid = (low+high)/2;
        return QueryLazy(qlow, qhigh,low, mid, 2 * pos + 1) + QueryLazy(qlow, qhigh,mid + 1, high, 2 * pos + 2);

    }

void update_Range(int ql,int qe,int l,int r,int pos)
{
	if(l>r || ql>r || qe<l)
		return ;
	if(l==r)
	{
		tree[pos] = tree[pos]^1;
		return ;	
	}
	int mid = (l+r)/2;
	update_Range(ql,qe,l,mid,2*pos+1);
	update_Range(ql,qe,mid+1,r,2*pos+2);
	tree[pos] = tree[2*pos+1] + tree[2*pos+2];
}
int query(int l,int r,int ql,int qe,int pos)
{
	if(ql<=l && qe>=r)
		return tree[pos];
	if(ql>r || qe<l)
		return 0;
	int mid = (l+r)/2;
	return query(l,mid,ql,qe,2*pos+1) + query(mid+1,r,ql,qe,2*pos+2);
}
int main()
{
	int n;
	cin>>n;
	int a[n] = {0};
	build(a,0,n-1,0);
	memset(lazy,0,sizeof(lazy));
	int q;
	cin>>q;
	ll sum = 0;
	while(q--)
	{
		int t,l,r;
		cin>>t>>l>>r;
		if(t==0)
		{
			updateSegmentTreeRangeLazy(l,r,0,n-1,0);
		}
		else
		{
			ll ans = QueryLazy(l,r,0,n-1,0);
			cout<<ans<<endl;
			sum = (sum%mod + ans%mod)%mod;
		}

	}
	cout<<sum<<endl;

	
}