/*
	Given a string S, count minimum no. of swaps needed to regroup 0's and 1's.  
	After all swaps final string will look like all 0's followed by 
	all 1's or all 1's followed by all 0's. Swap operation swaps two adjacent characters (01 -> 10, 10 -> 01, 00 -> 00 and 11 -> 11).  
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n = s.length();
	int c = 0;
	if(s[0]=='1')
	{

		int last = 0;
		for(int i=1;i<n;i++)
		{
			if(s[i-1]=='0' && s[i]=='1')
			{
				c += (i-last);
			}
			if(s[i]=='1')
				last = i;
		}
	}
	else
	{
		int last = 0;
		for(int i=1;i<n;i++)
		{
			if(s[i-1]=='1' && s[i]=='0')
			{
				c += (i-last);
			}
			if(s[i]=='0')
				last = i;
		}
	}
	cout<<c<<endl;
	cout<<s<<endl;
}