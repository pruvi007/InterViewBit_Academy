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
		vector<int> v;

		for(int i=1;i<=n;i++)
		{
			v.push_back(i);
		}

		for(int i=0;i<n;i++)
		{
			vector<int> temp;
			for(int j=0;j<v.size();j++)
			{
				if(j%2!=0)
				{
					temp.push_back(v[j]);
				}
			}
			v = temp;
			for(int j=0;j<v.size();j++)
				cout<<v[j]<<" ";
			cout<<endl;
			if(v.size() == 1)
				break;
		}
		cout<<v[0]<<endl;

		int c = 0;
		while(n)
		{
			c++;
			n/=2;
		}

		cout<<pow(2,c-1)<<endl;
	}

}