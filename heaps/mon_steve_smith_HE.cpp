/*
	MONK and STEVE SMITH
	HE
	idea: store the pair in heaps and then use comaprator to sort
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
#define ll long long int

struct myComp{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return (a.first < b.first) || ((a.first == b.first) && (a.second > b.second));
	}
};

int main()
{
	int n,k;
	cin >> n >> k;
	priority_queue<pair<int,int>,vector<pair<int,int>>,myComp> pq;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		pq.push({x,i});
	}
	while(k)
	{
		pair<int,int> p = pq.top();
		pq.pop();
		cout << p.second+1 << " ";
		pq.push({p.first-1,p.second});
		k--;
	}
}