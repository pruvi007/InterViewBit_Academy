/*
	You are given a string. The only operation allowed is to insert characters in the beginning of the string. 
	How many minimum characters are needed to be inserted to make the string a palindrome string 
	Example: Input: ABC Output: 2 Input: AACECAAAA Output: 2
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

// my idea is to check whether string is palindrome or not, if not then delete from last and check again. (brute force)

int check_palindrome(string s,int l,int r)
{
	int flag=0;
	while(l<r && r>l)
	{
		if(s[l]==s[r])
		{
			l++;
			r--;
		}
		else
			return 0;
	}
	return 1;
}
int main()
{
	string s;
	cin>>s;

	int min = INT_MAX;
	int n = s.length();
	
	// cout<<check_palindrome(s,0,n-1);

	for(int i=0;i<n;i++)
	{
		int ans = check_palindrome(s,0,n-i-1);
		if(ans)
		{
			min = i;
			break;
		}
	}
	cout<<min<<endl;
	
	
}