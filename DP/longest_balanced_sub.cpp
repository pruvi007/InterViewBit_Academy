/*
	Find the length of longest balanced Parenthesis
	idea; use a stack
*/
// solution by @pruvi007
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	stack<int> stk;
	stk.push(-1);
	int max = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(' || s[i]=='<' || s[i]=='[' || s[i]=='{')
			stk.push(i);
		else
		{
			int x = stk.top();
			stk.pop();
		
			if(!stk.empty())
			{
				int d = abs(i-stk.top());
				if(d>max)
					max = d;
			}
			// this is the new base
			else stk.push(i);
			
		}
	}
	cout << max << endl;
}