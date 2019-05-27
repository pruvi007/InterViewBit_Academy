/*
	reverse first b eleemts of a queue.
	Approach: use stack for first b elelemts then enqueue them and for the remaining .. dequeue and enequque

*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	queue<int> q;
	stack<int> s;

	// enqueue all elements in queue
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		q.push(x);
	}
	int b;
	cin>>b;

	// push first b elements into stack and keep track of first element
	
	int last;
	for(int i=0;i<b;i++)
	{
		// cout<<q.front()<<" ";
		int x = q.front();
		q.pop();
		s.push(x);
	}
	last = s.top();
	// cout<<q.size();
	// enqeue back all the elements of the stack to get them in reverse order
	// cout<<"stack: ";
	while(!s.empty())
	{
		// cout<<s.top()<<" ";
		q.push(s.top());
		s.pop();
	}
	// cout<<endl;

	
	// dequeue and enqueue all the remaining elements back to the queue.
	while(!q.empty() && q.front()!=last)
	{
		int x = q.front();
		q.pop();
		q.push(x);

	}
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();

	}
	cout<<endl;

}