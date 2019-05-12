/* instead of swapping a[i] and a[i+1], now consider a window size of 3 and swap a[i], a[i+2]. 
However, its a wrong way to sort an array, but  your task is to find the final array obtained after performing trouble sort.*/

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

	// obs: after trouble sort, all the even indices are sorted and all the odd indices are sorted.

	vector<int> e,o;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			e.push_back(a[i]);
		else o.push_back(a[i]);
	}
	sort(e.begin(),e.end());
	sort(o.begin(),o.end());
	int c1 = 0,c2=0;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			a[i] = e[c1++];
		else a[i] = o[c2++];
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}