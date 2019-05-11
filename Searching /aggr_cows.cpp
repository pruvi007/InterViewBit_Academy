#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int b;
	cin>>b;

	sort(a,a+n);
	int low = a[0],high = a[n-1];
	int ans;
	while(low<=high)
	{
		int mid = (low+high)/2;
		int last = a[0];
		int c = 1;
		for(int i=1;i<n;i++)
		{
			if((a[i]-last) >= mid)
			{
				c++;
				last = a[i];
			}
		}

		if(c>=b)
		{
			ans = mid;
			low = mid+1;
		}
		else high = mid-1;
	}
	cout<<ans<<endl;
}