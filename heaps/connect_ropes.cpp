/*
	Connect ropes with minimum cost
	Idea-. use a min heap and add two min elements and push their sum back to min heap.
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > pq;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		pq.push(x);
	}
	int sum = 0;
	while(pq.size()!=1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		cout<<a<<" "<<b<<endl;
		sum += a+b;
		pq.push(a+b);
	}
	cout<<sum<<endl;
}