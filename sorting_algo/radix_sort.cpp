// implement radix sort - explouts numbers at digit level
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
	
	
	vector<int> d_size;
	int max_digit = 0 ; //the max digits
	for(int i=0;i<n;i++)
	{
		int c = 0;
		int x = a[i];
		while(x)
		{
			x=x/10;
			c++;
		}
		d_size.push_back(c);
		if(c>max_digit)
			max_digit = c;

	}
	for(int i=0;i<max_digit;i++)
	{
		list<int> *bucket = new list<int>[10];
		int extract = pow(10,i);
		cout<<"\nIteration- "<<i+1<<endl;

		for(int j=0;j<n;j++)
		{
			int index = (a[j]/extract)%10;
			bucket[index].push_back(a[j]);

		}
		int ca=0;
		list<int>::iterator itr;
		for(int j=0;j<10;j++)
		{
			
			if(bucket[j].size()>0)
			{
				cout<<"Bucket- "<<j<<": ";
				for(itr=bucket[j].begin();itr!=bucket[j].end();itr++)
				{
					cout<<*itr<<" ";
					a[ca++] = *itr;
				}
				cout<<endl;
			}
			
		}

	}

	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;

}