/*
	Flip The array
	Flip the sign of some elements such that the total sum is minimum non-negative
	my Idea: slect or not select an element
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n;
	cin >> n;
	vector<int> a;
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
		sum += a[i];
	}
	sort(a.begin(),a.end());
	vector<int> t1,t2;
	t1.push_back(a[0]);
	int s1=a[n-1],s2=0;
	for(int i=n-2;i>=0;i--)
	{
		if(s1 > s2)
		{
			s2 += a[i];
			t2.push_back(a[i]);
		}
		else
		{
			s1 += a[i];
			t1.push_back(a[i]);
		}
	}
	cout << t1.size() << " " << t2.size() << endl;
	cout << s1 << " " << s2 << endl;
	cout << "changes: " << min(t1.size(),t2.size()) << endl;

}