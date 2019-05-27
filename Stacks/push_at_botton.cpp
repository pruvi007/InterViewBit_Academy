/*
	given a stack and an element x. push x to the bottom of stack.
	Approach1-> use an aux stack. empty the input stack and push it to the input stack and pop back all.
	Approach2-> do the above by recursion.
	i will be doing the recusrsion approach.
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

// each call will have three forks. one is pop(), then call push_bottom, then push again.
void push_bottom(stack<int> &s,int x)
{
	if(s.empty())
	{
		s.push(x);
	}
	else
	{
		int y = s.top();
		s.pop();
		push_bottom(s,x);
		s.push(y);
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
	int x;
	cin>>x;
	push_bottom(s,x);

	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();

	}
	cout<<endl;

}