// perform the merge operation on two sorted arrays in O(mn) but O(1) space

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
	int m;
	cin>>m;
	int b[m];
	for(int i=0;i<m;i++)
		cin>>b[i];
	// n smaller elements and m larger elements
	// do sorted insert in either of the array

	int l = 0;
	while(l<n)
	{
		if(a[l]>b[0])
		{
			int temp = a[l];
			cout<<temp<<" : ";
			a[l] = b[0];
			int index = -1;

			// find the correct place for the element
			for(int i=1;i<m;i++)
			{
				if(b[i]>temp)
				{
					index = i-1;
					break;
				}
			}
			if(index == -1)
				index = m-1;

			// do a sorted insert in the larger array
			for(int i=1;i<=index;i++)
			{
				b[i-1] = b[i];
			}
			b[index] = temp;
			for(int i=0;i<m;i++)
				cout<<b[i]<<" ";
			cout<<endl;
		}
		l++;
	}
	// a contains n smaller elements
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	// b conatains the m larger elements
	for(int i=0;i<m;i++)
		cout<<b[i]<<" ";
	cout<<endl;
}