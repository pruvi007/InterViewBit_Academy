// use cycle based approach. to mark an element add 1 to it and multiply by -1

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

	int l = 0;
	for(int i=0;i<n;i++)
	{
		a[a[i]%n] += i*n;
	}
	for(int i=0;i<n;i++)
	{
		a[i]/=n;
		cout<<a[i]<<" ";
	}
	cout<<endl;
}