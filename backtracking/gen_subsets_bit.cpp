#include<bits/stdc++.h>
using namespace std;

void subsets(int a[],int n)
{
	vector<int> temp;
	int size = pow(2,n);
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<n;j++)
		{
			// to check if jth bit is set in i or not (if set then take else dont take)
			int x = i & (1<<j);
			// cout<<x;
			if(x)
			{
				temp.push_back(a[j]);
			}
		}
		// cout<<endl;
		for(int j=0;j<temp.size();j++)
			cout<<temp[j]<<" ";
		cout<<endl;
		temp.clear();
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
		
		
		subsets(a,n);
	}
}