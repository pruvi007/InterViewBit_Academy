/*
	given two sorted arrays. 
	Return k minimum sum pairs of the form (ai,bj).
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

class node{
	int sum;
	int i;
	int j;
public:
	node(int s,int a,int b)
	{
		this->sum = s;
		this->i = a;
		this->j = b;
	}
	int getSum() const { return sum; } 
   	int getI() const { return i; } 
   	int getJ() const {return j; }
};

class myComp{
public:
	int operator() (const node& n1,const node& n2)
	{
		return n1.getSum() > n2.getSum();
	}
};


int main()
{
	int n,m;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++)
		cin>>b[i];
	sort(a,a+n);
	sort(b,b+m);
	int k;
	cin>>k;
	priority_queue<node,vector<node>,myComp> pq;
	pq.push(node(a[0]+b[0],0,0));
	
	int c = 0;
	while(1)
	{
		node nd = pq.top();
		cout<<a[nd.getI()]<<" "<<b[nd.getJ()]<<endl;
		c++;
		if(c==k)
			break;
		pq.pop();
		node nd1 = node(a[nd.getI()]+b[nd.getJ()+1],nd.getI(),nd.getJ()+1);
		node nd2 = node(a[nd.getI()+1]+b[nd.getJ()],nd.getI()+1,nd.getJ());
		pq.push(nd1);
		pq.push(nd2);

	}


}
