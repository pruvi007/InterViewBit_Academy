/*
	reverse the string and append it to the original. Now get the LPS.
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	string temp="";
	int n1 = s.length();
	for(int i=n1-1;i>=0;i--)
		temp+=s[i];
	s = s+ '@';
	s = s +temp;
	cout<<s<<endl;
	int n = s.length();
	int lps[n];
	lps[0] = 0;
	int l=0,r=1;
	
	while(r<n)
	{
		if(s[l] == s[r])
		{
			l++;
			lps[r] = l;
			r++;
		}
		else
		{
			if(l!=0)
				l = lps[l-1];
			else
			{
				lps[r] = 0;
				r++;
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<lps[i]<<" ";
	cout<<endl;
	int ans = abs(n1-lps[n-1]);
	cout<<ans<<endl;
}