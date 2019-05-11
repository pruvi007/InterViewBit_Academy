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
	for(int i=0;i<n;i++)
	{
		int x = a[i];
		vector<int> pf;
		while(x%2==0)
		{
			pf.push_back(2);
			x/=2;
		}
		for(int j=3;j<=sqrt(x);j++)
		{
			while(x%j==0)
			{
				pf.push_back(j);
				x/=j;
			}
		}
		if(x>2)
			pf.push_back(x);
		for(int i=0;i<pf.size();i++)
			cout<<pf[i]<<" ";
		cout<<endl;
	}
}