#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	int a[n][m];
	int aux[n][m];
	// given array will be sorted by row and column
	// find the max sum SUB-MAtrix
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
			aux[i][j] = a[i][j];
		}
	}

	// Approach 1 - Generate all sub-matrices and find sum in O(1) and keep track of max
	// O(n^4)

	for(int i=0;i<n;i++)
	{
		for(int j=1;j<m;j++)
			aux[i][j] = aux[i][j] + aux[i][j-1];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
			aux[i][j] = aux[i][j] + aux[i-1][j];
	}

	int max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<m;l++)
				{
					int i1=i,j1=j,i2=k,j2=l;
					
					int sum = 0;
					sum = aux[i2][j2];
					if(i1>0)
					 	sum = sum - aux[i1-1][j2];
					if(j1>0)
						sum = sum - aux[i2][j1-1];

					// add the overlapping region
					if(i1>0 && j1>0)
						sum = sum + aux[i1-1][j1-1];
					// cout<<sum<<endl;
					if(sum>max)
						max = sum;
				}
			}
		}
	}
	cout<<max<<endl;


	// Approach 2 - instead of creating prefix Aux. Create Suffix Aux because we know the ans would always contain a[n][m] cuz its the max elem of the matrix.

	int suff[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			suff[i][j] = a[i][j];
	}

	for(int i=n-1;i>=0;i--)
	{
		for(int j=m-2;j>=0;j--)
		{
			suff[i][j] = suff[i][j] + suff[i][j+1];
		}
	}
	for(int i=n-2;i>=0;i--)
	{
		for(int j=m-1;j>=0;j--)
		{
			suff[i][j] = suff[i][j] + suff[i+1][j];
		}
	}

	// now find the max in suff to get the answer.
	max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(suff[i][j]>max)
				max = suff[i][j];
		}
	}
	cout<<max<<endl;
}