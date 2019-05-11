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

		int B;
		cin>>B;

		int l=0,r=1;
		int sum = a[l]+a[r];
		int f=0;
		while(r<n)
		{
			cout<<sum<<" : "<<l<<" "<<r<<endl;
			if(sum == B)
			{
				f=1;
				break;
			}
			else if(sum<B)
			{
				r++;
				sum+=a[r];
			}
			else if(sum>B)
			{
				sum -= a[l];
				l++;
			}
		}
		if(f==1)
		{
			for(int i=l;i<=r;i++)
				cout<<a[i]<<" ";
			cout<<endl;
		}
		else cout<<"-1\n";
	}
}