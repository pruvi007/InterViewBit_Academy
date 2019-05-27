/*
	reverse a given stack.
	Appraoch1-> use two aux stacks. pop() from input to aux1 then pop() from aux1 to aux2. then pop() from aux2 to input().
	I will do the above approach using recusrion. Using push_bottom() function
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

void push_bottom(stack<int> &s,int x)
{
	if(s.empty())
		s.push(x);
	else
	{
		int y = s.top();
		s.pop();
		push_bottom(s,x);
		s.push(y);
	}
}
void reverse(stack<int> &s)
{
	if(s.empty())
		return;
	else
	{
		int y = s.top();
		s.pop();
		reverse(s);
		push_bottom(s,y);
	}
}
int main()
{
	int n;
	cin>>n;
	stack<int> s;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		s.push(x);
	}
	reverse(s);

	// here the output must be the same as input.(reverse order)
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
}