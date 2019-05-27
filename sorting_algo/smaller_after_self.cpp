// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int temp[100001];
map<int,int> mp;
int merge(int a[],int l,int m,int r)
{
	int i = l,j = m,k = 0;

	int c = 0;
	int small = 0;
	while(i<m && j<=r)
	{
		if(a[i]<=a[j])
		{
			temp[k++] = a[i++];

		}
		else
		{
			small++;
			temp[k++] = a[j++];
			c += (m-i);
			
		}
	}

	while(i<m)
		temp[k++] = a[i++];
	while(j<=r)
		temp[k++] = a[j++];

	int ct = 0;
	for(int i=l;i<=r;i++)
		a[i] = temp[ct++];
	// small.push_back(c);
	return c;
}
int merge_sort(int a[],int l,int r)
{
	int c = 0;
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
	int ans = merge_sort(a,0,n-1);
	cout<<ans<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	for(int i=0;i<n;i++)
		cout<<(n-1-i-mp[a[i]])<<" ";
	cout<<endl;

}