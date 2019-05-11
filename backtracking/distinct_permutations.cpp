#include<bits/stdc++.h>
using namespace std;


int shouldSwap(int a[],int start,int curr)
{
	for(int i=start;i<curr;i++)
	{
		if(a[i] == a[curr])
			return 0;
	}
	return 1;
}
void distinct_permutations(int a[],int n,int level)
{	
	if(level == n)
	{
		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}

	for(int i=level;i<n;i++)
	{
		// if the element is seen before then dont swap
		if(shouldSwap(a,level,i))
		{
			
			// swap 1
			int t = a[level];
			a[level] = a[i];
			a[i] = t;

			distinct_permutations(a,n,level+1);


			// swap again to balance for the next branch
			t = a[level];
			a[level] = a[i];
			a[i] = t;
		}
		
			


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

		
		distinct_permutations(a,n,0);
	}
}