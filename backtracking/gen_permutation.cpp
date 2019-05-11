#include<bits/stdc++.h>
using namespace std;


// the following will produce permutation.. however it won't be lexicographic order.
void permute(int a[],int n,int level)
{
	if(level == n)
	{
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}

	for(int i=level;i<n;i++)
	{
		// swap1;
		int t = a[level];
		a[level] = a[i];
		a[i] = t;

		permute(a,n,level+1);

		// swap back to make original array for next branch
		t = a[level];
		a[level] = a[i];
		a[i] = t;
	}
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

		permute(a,n,0);
	}
}