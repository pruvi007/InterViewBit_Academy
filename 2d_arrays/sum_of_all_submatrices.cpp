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

// O(n^6) approach of generating all submatrices
	int sum = 0;
	// get the top left corner
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			// get the bottom right corners
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<m;l++)
				{
					// get the sum between these two corners
					for(int x=i;x<=k;x++)
					{
						for(int y=j;y<=l;y++)
							sum += a[x][y];
					}
				}	
			}
		}
	}
	cout<<sum<<endl;


// O(n^2) approach to get the contribution 
// choose a cell and that cell can be chosen as bottom right in (i+1)*(j+1) ways and top left as (n-i)*(m-j) ways. 
	int sum2= 0 ;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			sum2 += a[i][j]*(i+1)*(j+1)*(n-i)*(m-j);
		}
	}
	cout<<sum2<<endl;


}