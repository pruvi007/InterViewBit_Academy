

#include<bits/stdc++.h>
using namespace std;

// min swaps to sort the entire the array
// without making graph , considering cycles by indexing
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int l = 0;
	int swaps=0;

	// keep swapping untill the correct number comes to that place. Then increment

	while(l<n)
	{
		if(a[l]==l+1)
			l++;
		if(l==n)
			break;
		if(a[l]!=l+1)
		{
			swaps++;
			int t = a[a[l]-1];
			a[a[l]-1] = a[l];
			a[l] = t;
		}
		// for(int i=0;i<n;i++)
		// 	cout<<a[i]<<" ";
		// cout<<endl;
	}
	cout<<swaps<<endl;
}