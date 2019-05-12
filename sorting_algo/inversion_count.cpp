// count total number of inversions in array 
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;



int merge(int a[],int l,int m,int r)
{

	int n1 = m-l+1;
	int n2 = r-m ;
	int L[n1],R[n2];

	int i=0,j=0,k=l;
	// populate the left and right arrays
	for(int i=0;i<n1;i++)
		L[i] = a[i+l];

	for(int i=0;i<n2;i++)
		R[i] = a[m+i+1];

	int c = 0;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];

			// if L[i] is greater than R[j], then all the remaining elemnts will also be greater then R[j];
			c += (m-i);
			j++;
		}
		k++;
	}
	while(i<n1)
		a[k++] = L[i++];
	while(j<n2)
		a[k++] = R[j++];

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

		c += merge(a,l,mid,r);

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
	int ic = merge_sort(a,0,n-1);
	cout<<ic<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}