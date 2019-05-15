// find if there is subarray with 0 sum
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
	map<int,int> m;
	int sum = 0;
	int exist = 0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if(m[sum]>0 || sum==0)
		{
			exist = 1;
			break;
		}
		m[sum]++;
	}
	if(exist)
		cout<<"1\n";
	else cout<<"0\n";

}