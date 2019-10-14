/*
	Maintain left and right sets to get the required indices
	
*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	cin >> n >> q;
	int a[n];
	set<int> right;
	set<int,greater<int> > left;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i] == 1)
		{
			right.insert(i);
			left.insert(i);
		}
	}

	while(q--)
	{
		int x;
		cin >> x;
		if( x==0 )
		{
			int p;
			cin >> p;
		
			auto it1 = right.upper_bound(p);
			auto it2 = left.upper_bound(p);

			if( it2!=left.end() )
				cout << *it2 << " ";
			else
				cout << -1 << " ";

			if( it1!=right.end() )
				cout << *it1 << " ";
			else 
				cout << -1 << " ";

			
			cout << endl;
		}
		else
		{
			int p;
			cin >> p;
			if( a[p]==0)
			{
				a[p] = 1;
				left.insert(p);
				right.insert(p);
			}
			

		}
	}
}