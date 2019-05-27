/*
	sort the input using two stacks
*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	stack<int> ip,temp;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		ip.push(x);
	}

	while(!ip.empty())
	{
		int x = ip.top();
		ip.pop();
		while(!temp.empty() && x<temp.top())
		{
			int y = temp.top();
			ip.push(y);
			temp.pop();
		}
		temp.push(x);
	}
	vector<int> v,ans;
	while(!temp.empty())
	{
		v.push_back(temp.top());
		temp.pop();
	}
	for(int i=v.size()-1;i>=0;i--)
		ans.push_back(v[i]);
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
