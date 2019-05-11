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

		for(int i=0;i<n;i++)
		{
			if((a[i]<0 && i%2!=0) || (a[i]>=0 && i%2==0))
			{
				int st = i;
				int end=-1;
				int neg = 0;
				if(a[st]<0)
				    neg=1;
				for(int j=st+1;j<n;j++)
				{
					if(neg==1 && a[j]>=0)
					{
						end=j;
						break;
					}
					else if(neg==0 && a[j]<0)
					{
					    end=j;
						break;   
					}
				}
				if(end!=-1)
				{
					int temp = a[end];
					for(int j=end;j>st;j--)
					{
						a[j] = a[j-1];
					}
					a[st] = temp;
				}
			}
		}

		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
}