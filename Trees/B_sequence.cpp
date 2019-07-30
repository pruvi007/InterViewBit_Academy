/*
	B sequuence
	HE
	idea: maintain a set on smaller elements and another on larger set.
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	set<int> s;
	set<int,greater<int> > g;
	s.insert(a[0]);
	int ind;
	int max = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] > max)
		{
			max = a[i];
			ind = i;
		}
	}

	for(int i=1;i<ind;i++)
		s.insert(a[i]);
			
	
	for(int i=ind+1;i<n;i++)
		g.insert(a[i]);

	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		if(x < max)
		{
			if(s.find(x) == s.end())
				s.insert(x);
			else g.insert(x);
		}
		else if(x > max)
		{
			s.insert(max);
			max = x;
		}
		cout << s.size() + g.size() + 1 << endl;
	}
	set<int>::iterator it;
	set<int,greater<int> >::iterator it2;
	for(it=s.begin();it!=s.end();it++)
		cout << *it << " ";
	cout << max << " ";
	for(it2=g.begin();it2!=g.end();it2++)
		cout << *it2 << " ";
}