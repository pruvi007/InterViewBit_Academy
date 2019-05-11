#include<bits/stdc++.h>
using namespace std;

// tested running fine by IB TC's
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

	// create prefix array
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
			a[i][j] = a[i][j] + a[i][j-1];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
			a[i][j] = a[i-1][j] + a[i][j];
	}

	int q;
	cin>>q;
	while(q--)
	{
		int i1,j1,i2,j2;
		cin>>i1>>j1>>i2>>j2;
		int sum = 0;
		sum = a[i2][j2];
		if(i1>0)
		 	sum = sum - a[i1-1][j2];
		if(j1>0)
			sum = sum - a[i2][j1-1];

		// add the overlapping region
		if(i1>0 && j1>0)
			sum = sum + a[i1-1][j1-1];
		cout<<sum<<endl;
	}
}