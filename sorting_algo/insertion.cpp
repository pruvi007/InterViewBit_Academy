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

	// pick an element and put it in its right place, by moving all the elements by one unit ahead.
	for(int i=1;i<n;i++)
	{
		int key = a[i];
		int j = i-1;
		while(j>=0 && key<a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
		
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}