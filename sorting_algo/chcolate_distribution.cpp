
/* given an array of integers denoting chocolates in ith packet. Distribute packets to B students such that 1. 
each student gets a packet and 2. Difference between max packet and min packet should be min.*/


// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

// my approach, I will maintain a set with window size of B on sorted array.
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int B;
	cin>>B;

	multiset<int,greater<int> > s;
	multiset<int> t;
	sort(a,a+n);
	for(int i=0;i<B;i++)
	{
		s.insert(a[i]);
		t.insert(a[i]);
	}
	int M = *(s.begin());
	int m = *t.begin();
	cout<<m<<" "<<M<<endl;
	int diff = abs(M-m);
	int min = diff;
	for(int i=B;i<n;i++)
	{

		s.erase(s.find(*t.begin()));
		t.erase(t.begin());
		s.insert(a[i]);
		t.insert(a[i]);

		M = *s.begin();
		m = *t.begin();
		cout<<m<<" "<<M<<endl;
		diff = abs(M-m);
		if(diff<min)
			min = diff;
	}
	cout<<min<<endl;
}