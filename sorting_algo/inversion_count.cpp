// count total number of inversions in array 
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;


vector<int> temp;
int merge(int a[],int l,int m,int r)
{

	int i=l,j=m,k=l;
	
	int c = 0;

	
	while(i<m && j<=r)
	{
		if(a[i]<=a[j])
		{
			temp.push_back(a[i]);
			i++;
		}
		else
		{
			temp.push_back(a[j]);

			// if L[i] is greater than R[j], then all the remaining elemnts will also be greater then R[j];
			c += (m-i);
			j++;
		}
		
	}
	while(i<m)
		temp.push_back(a[i++]);
	while(j<=r)
		temp.push_back(a[j++]);

	int ct=0;
	for(int i=l;i<=r;i++)
		a[i] = temp[ct++];
	temp.clear();
	return c;
}

int merge_sort(int a[],int l,int r)
{
	int c =0;
	if(l<r)
	{
		int mid = (l+r)/2;

		c = merge_sort(a,l,mid);
		c += merge_sort(a,mid+1,r);

		c += merge(a,l,mid+1,r);

	}
	return c;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int ic = merge_sort(a,0,n);
	cout<<ic<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}