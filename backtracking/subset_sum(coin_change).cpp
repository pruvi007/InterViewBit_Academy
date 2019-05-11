#include<bits/stdc++.h>
using namespace std;

// Q. can we add more similar elements and implement subset_sum ???????

int subset_sum_multiple(int a[],int n,int k,int level,int sum)
{
	if(sum>k)
		return 0;
	if(level == n)
	{
		return sum==k?1:0;
	}

	// remain at same level to add more of same.
	return subset_sum_multiple(a,n,k,level,sum+a[level]) + subset_sum_multiple(a,n,k,level+1,sum);
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

		cout<<subset_sum_multiple(a,n,k,0,0)<<endl;
	}
}