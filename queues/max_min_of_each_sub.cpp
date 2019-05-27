/*
	find the sum of max- min of each subarray of size b
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

	multiset<int> s;
	multiset<int,greater<int> > g;
	queue<int> q;

	int sum = 0;
	for(int i=0;i<b;i++)
	{
		s.insert(a[i]);
		g.insert(a[i]);
		q.push(a[i]);
	}

	cout<<*s.begin()<<" "<<*g.begin()<<endl;
	sum += *s.begin() + *g.begin();

	for(int i=b;i<n;i++)
	{
		int x = q.front();
		q.pop();
		s.erase(s.find(x));
		g.erase(g.find(x));

		q.push(a[i]);
		s.insert(a[i]);
		g.insert(a[i]);

		cout<<*s.begin()<<" "<<*g.begin()<<endl;
		sum += *s.begin() + *g.begin();
	}

	cout<<sum<<endl;

}