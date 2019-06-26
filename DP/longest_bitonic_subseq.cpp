/*
	BITONIC SEQ.
	find the longest subsequnce which is first increasing then decreasing
	idea: calculate LIS and LDS and then max of lis[i]+lds[j] will be the answer
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int lis[n];
	lis[0]=1;
	for(int i=1;i<n;i++)
	{
		lis[i] = 1;
		for(int j=0;j<i;j++)
		{
			if(a[i] > a[j])
			{
				lis[i] = max(lis[i],lis[j]+1);
			}
		}
	}

	int lds[n];
	lds[n-1] = 1;
	for(int i=n-2;i>=0;i--)
	{
		lds[i]=1;
		for(int j=n-1;j>i;j--)
		{
			if(a[i] > a[j])
			{
				lds[i] = max(lds[i],lds[j]+1);
			}
		}
	}
	int max = 0;
	for(int i=0;i<n;i++)
	{
		int x = lis[i] + lds[i];
		if(x>max)
			max = x;
	}
	cout << max-1 << endl;
}