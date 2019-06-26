/*
	SPECIAL MEDIAN
	if there exist an ai such that it's median of a0 to a(i-1) or a(i+1) to a(n)
	idea is to keep track of forward medians and backeard medians
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

	double med = a[0];
	l.push(a[0]);
	vector<double> fmed;
	fmed.push_back(a[0]);
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
		else if(l.size() > r.size())
		{
			med = l.top();
		}
		else
		{
			med = (double)((double)l.top() + (double)r.top())/2.0;
		}
		fmed.push_back(med);
	}
// 	cout<<endl;

	vector<double> bmed;
	bmed.push_back(a[n-1]);
	med = a[n-1];
	l = priority_queue<int>();
	r = priority_queue<int,vector<int>,greater<int> >();
	l.push(a[n-1]);
	for(int i=n-2;i>=0;i--)
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
		else if(l.size() > r.size())
		{
			med = l.top();
		}
		else
		{
			med = med = (double)((double)l.top() + (double)r.top())/2.0;
		}
		bmed.push_back(med);
	}
	cout<<endl;

	for(int i=0;i<fmed.size();i++)
		cout<<fmed[i]<<" ";
	cout<<endl;
	for(int i=0;i<bmed.size();i++)
		cout<<bmed[i]<<" ";
	cout<<endl;

	int found = 0;
	for(int i=1;i<n;i++)
	{
		if(a[i] == fmed[i-1])
		{
			found=1;
			break;
		}
	}
	int c = 0;
	for(int i=n-2;i>=0;i--)
	{
		if(a[i] == bmed[c++])
		{
			found=1;
			break;
		}
	}
	if(a[n-1] == fmed[n-2])
		found=1;
	if(a[0] == bmed[n-2])
		found=1;
	cout<<found<<endl;

}