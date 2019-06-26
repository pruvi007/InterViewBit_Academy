/*
	COINS IN A LINE
	you can only take out either from first or from last

	Its 2D dp
	I will use Memoization
	idea: take from front and profit of rest or take from last and profit of the rest.

	int first glance you ll see that greedy would work. However the following TC proves that it will not work
	1 100 500 10
	ans 501
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int turn = 0;

// to memoize the sub problems we will use a map.
map<pair<int,int>,int> m;
int cMax = INT_MIN;
int maxProfit(vector<int> &a,int s,int e)
{
	if(s == e)
		return a[s];
	if(e == s+1)
		return max(a[s],a[e]);

	bool A = (m.find({s+1,e-1}) != m.end());
	bool b = (m.find({s+2,e}) != m.end());
	bool c = (m.find({s,e-2}) != m.end());
	if(A && b && c)
	{
		cMax =  max( a[s]+min( m[{s+1,e-1}],m[{s+2,e}] ), a[e]+min( m[{s+1,e-1}],m[{s,e-2}] ) );
	    m[{s,e}] = cMax;
	}
	else if(!A && b && c)
	{
		cMax =  max( a[s]+min( maxProfit(a,s+1,e-1),m[{s+2,e}] ), a[e]+min( maxProfit(a,s+1,e-1),m[{s,e-2}] ) );
	    m[{s,e}] = cMax;
	}
	else if(A && !b && c)
	{
		cMax =  max( a[s]+min( m[{s+1,e-1}],maxProfit(a,s+2,e) ), a[e]+min( m[{s+1,e-1}],m[{s,e-2}] ) );
	    m[{s,e}] = cMax;
	}
	else if(A && b && !c)
	{
		cMax =  max( a[s]+min( m[{s+1,e-1}],m[{s+2,e}] ), a[e]+min( m[{s+1,e-1}],maxProfit(a,s,e-2) ) );
	    m[{s,e}] = cMax;
	}
	else if(!A && !b && c)
	{
		cMax =  max( a[s]+min( maxProfit(a,s+1,e-1),maxProfit(a,s+2,e) ), a[e]+min( maxProfit(a,s+1,e-1),m[{s,e-2}] ) );
	    m[{s,e}] = cMax;
	}
	else if(!A && b && !c)
	{
		cMax =  max( a[s]+min( maxProfit(a,s+1,e-1),m[{s+2,e}] ), a[e]+min( maxProfit(a,s+1,e-1),maxProfit(a,s,e-2) ) );
	    m[{s,e}] = cMax;
	}
	else if(A && !b && !c)
	{
		cMax =  max( a[s]+min( m[{s+1,e-1}],maxProfit(a,s+2,e) ), a[e]+min( m[{s+1,e-1}],maxProfit(a,s,e-2) ) );
		m[{s,e}] = cMax;
	}
	else
	{
	    cMax =  max( a[s]+min( maxProfit(a,s+1,e-1),maxProfit(a,s+2,e) ), a[e]+min( maxProfit(a,s+1,e-1),maxProfit(a,s,e-2) ) );
	    m[{s,e}] = cMax;
	}
	
	return cMax;
	
}


int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int p = maxProfit(a,0,n-1);
	cout << p << endl;
}