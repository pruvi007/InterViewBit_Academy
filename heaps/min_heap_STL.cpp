/*
	implement MIN Heap using reverse priority queue
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	// type,container,comparison
	priority_queue<int,vector<int>, greater<int> > pq;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		pq.push(x);
	}
	cout<<pq.top()<<endl;
	pq.pop();
	cout<<pq.top()<<endl;
}