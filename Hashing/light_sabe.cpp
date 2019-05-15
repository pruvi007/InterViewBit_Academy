/* Given two array of integers A and B of size N and M respectively. The goal is 
to select some continuous interval in A such that there are exactly 
B[0] elements with value 1, B[1] elements with value 2 and so on ending with B[m-1] elements with value m.*/

// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;


/*
	Approach-> find satisfying l&r, and count extra elements. ANs would be min of those extra elemenets among all the satisfying l & r.
*/
int main()
{
	int n;
	cin>>n;
	int a[n];
	int max = 0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>max)
			max = a[i];
	}

	int k;
	cin>>k;
	int b[k];
	int m[max+2]={0};
	int m2[max+2]={0};
	int sum = 0;
	for(int i=0;i<k;i++)
	{
		cin>>b[i];
		if(i+1 > max)
			max = i+1;
		if(b[i]>0)
			m[i+1] = b[i];
		sum += b[i];
	}
	// cout<<max<<endl;
	int l=0,r=0;
	m2[a[0]]++;
	int min = INT_MAX;
	int xl=-1,xr=-1;
	while(l<=r && r<n)
	{
		
		int flag=0;
		for(int i=0;i<=max;i++)
		{
			if(m[i]>m2[i])
			{
				flag=1;
				break;
				
			}
			
		}
		// cout<<endl;
		if(flag==0)
		{

			cout<<"satisfy\n";
			int d = abs((r-l+1)-sum);
			if(d<min)
			{
				min = d;
				xl = l;
				xr = r;
			}
			m2[a[l]]--;
			l++;
			if(l>r)
				break;
		}
		else
		{
			r++;
			if(r==n)
				break;
			m2[a[r]]++;
		}
	}
	if(min == INT_MAX)
		cout<<"-1\n";
	else
	{
		cout<<min<<endl;
		for(int i=xl;i<=xr;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}
	

	

}
