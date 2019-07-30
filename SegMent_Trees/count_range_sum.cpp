/*
	Count range summ
	given L and R, find the ranges in the array whose sum lies between L and R
	idea: Build a Seg Tree and count the no. of nodes whose sum lies between L and R
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

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	memset(tree,NULL,sizeof(tree));
	build(a,0,n-1,0);
	int L,R;
	cin >> L >> R;
	int c = 0;
	for(int i=0;i<400005;i++)
	{
		if(tree[i] == NULL)
			break;
		else
		{
			if(tree[i] >= L && tree[i] <= R)
				c++;
		}
	}
	cout << c << endl;
}