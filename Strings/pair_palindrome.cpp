
/*
	all pairs of words which can be concatenated to form palindromes
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

/*
	map all the words. Now for a string find a prefix whose reverse is mapped, and the remaining is a palindrome. 
	If yes then a possible pair.
*/
int isPalindrome(string s,int l,int r)
{
	while(l<r && r>l)
	{
		if(s[l]==s[r])
		{
			l++;
			r--;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int n;
	cin>>n;
	vector<string> s;
	map<string,int> m;
	for(int i=0;i<n;i++)
	{
		string x;
		cin>>x;
		// cout<<isPalindrome(x,0,x.length()-1);
		s.push_back(x);
		m[x]++;
	}

	// doubt whether it will get TLE.
	for(int i=0;i<n;i++)
	{
		int l = s[i].length();
		string pre = "";
		for(int j=0;j<l;j++)
		{
			pre = pre + 
		}
	}
}