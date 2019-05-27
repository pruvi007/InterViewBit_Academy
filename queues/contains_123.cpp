/*
	find first n integers which 1,2,3 only. This question is level order traversal of queues.
	Recursion tree will contain 3 bracnhes of each fork.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	int c = 3;
	while(q.size()<=n)
	{
		q.push(q.front()*10+1);
		c++;
		if(c>=n)
			break;
		q.push(q.front()*10+2);
		c++;
		if(c>=n)
			break;
		q.push(q.front()*10+3);
		c++;
		if(c>=n)
			break;
		cout<<q.front()<<" ";
		q.pop();
	}
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}