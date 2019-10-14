
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			continue;
		int a[n];
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		stack<pair<int,int> > s;
		int nge[n]={-1};
		s.push({a[0],0});
		for(int i=1;i<n;i++)
		{
			

			pair<int,int> x = s.top();

			if(a[i]<x.first)
			{
				s.push({a[i],i});
			}
			else
			{

				while(!s.empty() && a[i]>=s.top().first)
				{

					nge[s.top().second] = i;
					s.pop();

				}
				s.push({a[i],i});
			}
		}
		while(!s.empty())
		{
			pair<int,int> p = s.top();
			nge[p.second] = n-1;
			s.pop();
		}
		
		int f_ans[n];
		for(int i=0;i<n;i++)
		{
			// cout << nge[i] << " ";
			// mp[nge[i]]++;
			f_ans[i] = nge[i]-i;
		}
		// cout << endl;
		int m = 0,ans;
		for(int i=0;i<n;i++)
		{
			// cout << f_ans[i] << " ";
			if(f_ans[i]>=m)
			{
				m = f_ans[i];
				ans = i+1;
			}
		}
		printf("%d\n",ans);
	}
	
}