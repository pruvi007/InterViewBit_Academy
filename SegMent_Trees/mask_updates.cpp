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
int tree[200005];

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
	int q;
	cin>>q;
	ll sum = 0;
	while(q--)
	{
		int t,l,r;
		cin>>t>>l>>r;
		if(t==0)
		{
			update_Range(l,r,0,n-1,0);
		}
		else
		{
			ll ans = query(0,n-1,l,r,0);
			cout<<ans<<endl;
			sum = (sum%mod + ans%mod)%mod;
		}

	}
	cout<<sum<<endl;

	
}