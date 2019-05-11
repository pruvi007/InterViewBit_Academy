#include<bits/stdc++.h>
using namespace std;

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

		int xi = -1,xj = -1;
		for(int i=1;i<n;i++)
		{
			if(a[i]<a[i-1])
			{
				xi = i-1;
				break;
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			if(a[i-1]>a[i])
			{
				xj = i;
				break;
			}
		}
		cout<<xi<<" "<<xj<<endl;
		int min = INT_MAX,max = INT_MIN;
		if(xi!=-1 && xj!=-1)
		{
			for(int i=xi;i<=xj;i++)
			{
				if(a[i]>max)
					max = a[i];
				if(a[i]<min)
					min = a[i];
			}
			for(int i=0;i<n;i++)
			{
				if(a[i]>min)
				{
					xi = i;
					break;
				}
			}
			for(int i=n-1;i>=0;i--)
			{
				if(a[i]<max)
				{
					xj = i;
					break;
				}
			}
			cout<<min<<" "<<max<<endl;
			cout<<xi<<" "<<xj<<endl;
		}
		else cout<<"-1\n";
		
		// for(int i=xi;i<=xj;i++)
		// 	cout<<a[i]<<" ";
		// cout<<endl;
	}
}