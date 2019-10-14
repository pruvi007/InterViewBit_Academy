#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll tree[500005];

void build(ll a[],ll l,ll r,ll pos)
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
  	//adding so that we get total no of set bits 
	tree[pos] = max(tree[pos*2+1],tree[pos*2+2]);
}

ll query(int l,int r,int ql,int qe,int pos)
{
	if(ql<=l && qe>=r)
		return tree[pos];
	if(ql>r || qe<l)
		return 0;
	int mid = (l+r)/2;
	return max(query(l,mid,ql,qe,2*pos+1),query(mid+1,r,ql,qe,2*pos+2));
}

int main()
{
	int n;
	cin >> n;
	ll a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	build(a,0,n,0);

	ll c = 0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ll val = a[i]*a[j];
			ll M = query(0,n,i,j,0);
			if( val<=M )
			{
				// cout << i+1 << " " << j+1 << " -> " << val << ": " << M <<endl;
				c++;
			}
		}
	}
	cout << c << endl;
}