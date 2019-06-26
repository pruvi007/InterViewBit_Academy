/*
	max product subarray
	idea: maintain max positive product and max negative product till the current a[i];
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

	int maxval = 1, minval = 1;
	// maxval should be positive and minval should be negative
	int ans = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(a[i]>0)
		{
			maxval = maxval * a[i];
			minval = min(minval*a[i],1);
		}
		if(a[i]==0)
		{
			maxval = 0;
			minval = 1;
		}
		if(a[i]<0)
		{
			int temp = maxval;
			maxval = minval*a[i];
			minval = temp*a[i];
		}
		ans = max(ans,maxval);
		if(maxval <= 0)
			maxval = 1;
	}
	cout << ans << endl;
}