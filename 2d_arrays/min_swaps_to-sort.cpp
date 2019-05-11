#include<bits/stdc++.h>
using namespace std;

// using graph and finding cycles.


list<int> *l;
int c;
int visit[100001];

void DFSUtil(int n)
{
	if(visit[n]==0)
	{
		visit[n]=1;
	
		c++;

	}
	
	list<int>::iterator it;
	for(it=l[n].begin();it!=l[n].end();it++)
	{
		if(visit[*it]==0)
		{

			DFSUtil(*it);
		}
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
		
		
		l = new list<int>[2*n];
		for(int i=0;i<n;i++)
		{
			if(a[i] != i)
			{
				l[i].push_back(a[i]);
			}
		}



		list<int>::iterator itr;
		for(int i=0;i<n;i++)
		{
			if(l[i].size()>0)
			{
				cout<<i<<":  ";
				for(itr=l[i].begin();itr!=l[i].end();itr++)
					cout<<*itr<<" ";
				cout<<endl;
			}
		}


		vector<int> cycle;
		for(int i=0;i<=n;i++)
			visit[i]=0;
		for(int i=0;i<n;i++)
		{
			
			if(l[i].size()>0)
			{
				c = 0;
				DFSUtil(i);
				cycle.push_back(c);
			}
			
			
		}
		for(int i=0;i<cycle.size();i++)
		{
			cout<<cycle[i]<<" ";
		}
		cout<<endl;

		

	}
	

}