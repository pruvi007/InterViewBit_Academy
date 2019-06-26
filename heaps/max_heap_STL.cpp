/*
	MAX HEAP using STL 
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	make_heap(v.begin(),v.end());
	// getMax in max heap
	cout<<v.front()<<endl;
	// insert at last
	v.push_back(10);
	// heapify
	push_heap(v.begin(),v.end());
	cout<<v.front()<<endl;
	pop_heap(v.begin(),v.end());
	cout<<v.front()<<endl;

	// or we can use priority queue (by default a max heap)

	priority_queue<int> pq;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		// insert in priority queue
		pq.push(x);
	}
	// max element of priority queue
	cout<<pq.top()<<endl;
	// deleteMax from priority queue
	pq.pop();
	
	cout<<pq.top()<<endl;

}