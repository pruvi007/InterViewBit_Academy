// max consecutive ones by doing at most 1 swap
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int n = s.length();

	int ones = 0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
			ones++;
	}
	// count right cumulative ones and left cumulative ones.
	int left[n],right[n];
	if(s[0]=='1')
		left[0] = 1;
	else left[0]= 0;
	if(s[n-1]=='1')
		right[n-1] = 1;
	else right[n-1] =0;

	for(int i=1;i<n;i++)
	{
		if(s[i]=='1')
			left[i] = left[i-1]+1;

		// if encounter 0 then again start cumulative sum from 0
		else left[i] = 0;
	}
	for(int i=n-2;i>=0;i--)
	{
		if(s[i]=='1')
			right[i] = right[i+1]+1;

		// if encounter 0 then again start cumulative from 0
		else right[i] = 0;
	}

	int max = INT_MIN;
	for(int i=1;i<n-1;i++)
	{
		int cnt = 0;
		if(s[i]=='0')
		{
			int sum = left[i-1] + right[i+1];
			if(sum<ones)
				cnt = sum+1;
			else cnt = sum;
		}
		if(cnt>max)
			max = cnt;
	}
	cout<<max<<endl;

}