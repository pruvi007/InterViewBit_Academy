#include<bits/stdc++.h>
using namespace std;

int subset_sum(int a[],int n,int k,int level,int sum)
{
	if(level == n)
	{
		return sum==k?1:0;
	}
	// summing because both branches will contribute to sum;
	return subset_sum(a,n,k,level+1,sum+a[level]) + subset_sum(a,n,k,level+1,sum);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		int k;
		cin>>k;
		int level = 0;
		int sum = 0;
		cout<<subset_sum(a,n,k,level,sum)<<endl;
	}
}