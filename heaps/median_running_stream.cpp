/*
	median of running stream of integers
	idea: to use a max heap to store lower part, min heap to store upper part
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	// max heap
	priority_queue<int> l;
	// min heap
	priority_queue<int,vector<int>,greater<int> > r;

	int med = a[0];
	l.push(a[0]);

	cout<<med<<" ";
	for(int i=1;i<n;i++)
	{
		

		if(a[i]>med)
		{
			int d1 = l.size();
			int d2 = r.size()+1;
			if(abs(d1-d2)>1)
			{
				int shift = r.top();
				r.pop();
				l.push(shift);
				r.push(a[i]);
			}
			else
			{
				r.push(a[i]);
			}
		}
		else
		{
			int d1 = l.size()+1;
			int d2 = r.size();
			if(abs(d1-d2)>1)
			{
				int shift = l.top();
				l.pop();
				r.push(shift);
				l.push(a[i]);
			}
			else
			{
				l.push(a[i]);
			}
		}
		
		if(l.size() < r.size())
		{
			med = r.top();
		}
		else
		{
			med = l.top();
		}
		cout<<med<<" ";
	}
	cout<<endl;
}