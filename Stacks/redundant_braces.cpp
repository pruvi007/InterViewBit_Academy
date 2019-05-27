/*
	check whether the given exp has redundant braces or not.
*/
// solution @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a;
	cin>>a;

	stack<char> s;
	int n = a.length();
	for(int i=0;i<n;i++)
	{
		if(a[i]=='(')
		{
			s.push(a[i]);
		}
		else if(a[i]==')')
		{

		}
	}
}