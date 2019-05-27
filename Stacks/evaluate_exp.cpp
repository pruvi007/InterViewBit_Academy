/*
	evaluate expression arithmetic 
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	vector<string> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string x;
		cin>>x;

		s.push_back(x);
	}

	stack<int> stk;
	if(s[0]!="+" && s[0]!="-" && s[0]!="*" && s[0]!="/")
	{
		int l = s[0].length();
		int sum = 0;
		int minus = 0;
		if(s[0][0]=='-')
		    minus = 1;
		if(minus)
		{
		    for(int i=1;i<l;i++)
			    sum = sum*10 + s[0][i]-'0';
		}
		else
		{
		    for(int i=0;i<l;i++)
			    sum = sum*10 + s[0][i]-'0';
		}
		
		if(minus)
		    stk.push(-sum);
		else stk.push(sum);
	}
	for(int i=1;i<n;i++)
	{
		if(s[i]!="+" && s[i]!="-" && s[i]!="*" && s[i]!="/")
		{
			int l = s[i].length();
			int sum = 0;
			int minus = 0;
			if(s[i][0]=='-')
			    minus = 1;
			if(minus)
			{
			    for(int j=1;j<l;j++)
				    sum = sum*10 + s[i][j]-'0';
			}
			else
			{
			    for(int j=0;j<l;j++)
				    sum = sum*10 + s[i][j]-'0';
			}
			
			if(minus)
			    stk.push(-sum);
			else stk.push(sum);
		}
		else
		{
			int a = stk.top();
			stk.pop();
			int b = stk.top();
			stk.pop();
			int sum = 0;
			if(s[i]=="+")
				sum = b+a;
			else if(s[i]=="-")
				sum = b-a;
			else if(s[i]=="*")
				sum = b*a;
			else if(s[i]=="/")
				sum = b/a;
			stk.push(sum);
		}
	}

	cout<<stk.top()<<endl;

	

}
