/*
	print the 1st negative integers of every window of size k.
	Approach-. Maintain a queue of negative integers and pop when that negative element is not part of any window.
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
	int b;
	cin>>b;
	queue<int> q;
	for(int i=0;i<b;i++)
	{
		if(a[i]<0)
			q.push(a[i]);
	}
	if(q.size()>0)
		cout<<q.front()<<" ";
	else cout<<"0 ";
	for(int i=b;i<n;i++)
	{
		if(!q.empty() && a[i-b]==q.front())
		{
			q.pop();
		}
		if(a[i]<0)
		{
			q.push(a[i]);
		}
		
		if(!q.empty())
			cout<<q.front()<<" ";
		else cout<<"0 ";
	}
	cout<<endl;
}