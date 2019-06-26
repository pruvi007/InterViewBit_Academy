/*
	Find the lonest Palindromic SUBSTRING 
	idea: create a bool isPalin matrix which tells whether from s[i..j] is palindrome or not
*/
// soluiton by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.length();
	int isPalin[n][n] = {0};

	// 1 length are always palindromes
	for(int i=0;i<n;i++)
		isPalin[i][i] = 1;

	int right=0,left = 0;
	for(int j=1;j<n;j++)
	{
		// right is j
		for(int i=0;i<j;i++)
		{
			// i is left
			int innerWord = (isPalin[i+1][j-1]) || (j-i<=2);
// 			if inner word is palindrome and end chars are same then update
			if(s[i] == s[j] && innerWord)
			{
				isPalin[i][j] = 1;
				if(j-i > right-left)
				{
					right = j;
					left = i;
				}
			}
		}
	}

	cout << s.substr(left,right+1) << endl;


}