/*
	find k maxs among n integers
	idea: create a k sized min heap. When encounter a greater element the pop from heap and push to heap.
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
	int k;
	cin>>k;
	priority_queue<int,vector<int>,greater<int> > pq;
	for(int i=0;i<k;i++)
		pq.push(a[i]);
	for(int i=k;i<n;i++)
	{
		if(a[i]>pq.top())
		{
			pq.pop();
			pq.push(a[i]);
		}
	}
	while(!pq.empty())
	{
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}