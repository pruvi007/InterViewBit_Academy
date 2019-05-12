// implement merge_sort 
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

void merge(int a[],int l,int mid,int r)
{

	// find the sizes of the two l,r aux arrays
	int n1 = mid-l+1;
	int n2 = r-mid;
	int L[n1],R[n2];

	// enter elements in the L,R aux array from a
	for(int i=0;i<n1;i++)
		L[i] = a[l+i];
	for(int i=0;i<n2;i++)
		R[i] = a[mid+i+1];

	// elements will be entered in original array from l i.e k (here)
	int i = 0,j=0,k=l; 
    
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k] = L[i]; 
            i++; 
        } 
        else
        { 
            a[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    
    while (i < n1) 
    { 
        a[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    
    while (j < n2) 
    { 
        a[k] = R[j]; 
        j++; 
        k++; 
    }  
}
void merge_sort(int a[],int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,r);

		merge(a,l,m,r);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}