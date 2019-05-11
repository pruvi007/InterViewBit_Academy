#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cin>>a[i][j];
	}
	
	// order O(m+n). Start from top right corner and keep comparing with target element

	int target;
	cin>>target;
	int l = 0,r = m-1;
	int f = 0;
	int xl,xr;
	int loop=0;
	while(1)
	{
		loop++;
		if(a[l][r]==target)
		{
			xl = l;
			xr = r;
			break;
		}
		else if(a[l][r]>target)
		{
			r--;
		}
		else
			l++;
	}
	cout<<loop<<endl;
	cout<<"Element found at : "<<xl<<" "<<xr<<endl;
}