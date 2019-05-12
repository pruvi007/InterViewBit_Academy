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

	// bubble sort using flag 
	bool flag = false;
	while(flag==false)
	{
		flag = true;
		int i = 0;
		while(i<n)
		{
			if(a[i]>a[i+1])
			{
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				flag=false; //there was atleast one position that needed to be swapped so need to iterate once more.
			}
			i++;
			
		}
	}

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}