#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];

	int max = INT_MIN,min=INT_MAX;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>max)
			max = a[i];
		if(a[i]<min)
			min = a[i];
	}

	list<int> *l;
	l = new list<int>[n+3];

	int range = (max - min)/(n-1);
	for(int i=0;i<n;i++)
	{
		int b = 1 + (a[i] - min)/(range);
		l[b].push_back(a[i]);
	}

	int st = min;
	int end = min + range-1;

	int first_b;
	for(int i=1;i<n+3;i++)
	{
		cout<<st<<"-"<<end<<"---  ";
		list<int>::iterator it;
		for(it=l[i].begin();it!=l[i].end();it++)
			cout<<*it<<" ";
		cout<<endl;
		st = end+1;
		end = st+range-1;
	}
	for(int i=0;i<n+3;i++)
	{
		if(l[i].size()>0)
		{
			first_b = i;
			break;
		}
	}
	int ans = INT_MIN;
	int M=INT_MIN,m=INT_MAX;
	list<int>::iterator it;
	for(it=l[first_b].begin();it!=l[first_b].end();it++)
	{
		if(*it>M)
			M = *it;
		if(*it<m)
			m = *it;
	}
	for(int i=first_b+1;i<n+3;i++)
	{
		if(l[i].size()>0)
		{
			int M1=INT_MIN,m1 = INT_MAX;
			for(it=l[i].begin();it!=l[i].end();it++)
			{
				if(*it>M1)
					M1 = *it;
				if(*it<m1)
					m1 = *it;
			}
			int x = m1 - M;
			if(x>ans)
				ans = x;
			M = M1;
			m = m1;

		}
	}
	cout<<ans<<endl;


	// calculate by sorting the values;
	sort(a,a+n);
	int ans2 = INT_MIN;
	for(int i=1;i<n;i++)
	{
		if((a[i] - a[i-1])>ans2)
			ans2 = a[i]-a[i-1];
	}
	cout<<ans2<<endl;
	


}