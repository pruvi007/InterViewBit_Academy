#include<bits/stdc++.h>
using namespace std;

// memory efficient

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

		vector<pair<int,int> > v;
	    for(int i=0;i<n;i++)
		{
			v.push_back({a[i],i});
		}
		sort(v.begin(),v.end());

		int visit[n+1];
		for(int i=0;i<=n;i++)
		    visit[i] = 0;

		int sum = 0;
		for(int i=0;i<n;i++)
		{
			int cycle=0;
			if(visit[i]==1 || v[i].second==i)
			    continue;

			int j = i;
			while(visit[j]==0)
			{
			    cycle++;
			    visit[j]=1;
			    j = v[j].second;
			}
			if(cycle>0)
			    sum+=(cycle-1);
			
		}
		cout<<sum<<endl;
	}


}
