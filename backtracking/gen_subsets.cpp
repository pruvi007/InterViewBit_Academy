#include<bits/stdc++.h>
using namespace std;

// genrate subsets recursively
void subsets(int a[],int n,int level)
{
	static vector<int> temp;
	if(level == n)
	{
		if(temp.size()>0)
		{
			for(int i=0;i<temp.size();i++)
				cout<<temp[i]<<" ";
			cout<<endl;
		}

		// for returning to other branches
		return;

	}

	// called the recursion with taking the element
	temp.push_back(a[level]);
	subsets(a,n,level+1);

	// called the recursion without taking the element
	temp.pop_back();
	subsets(a,n,level+1);

	
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		int level=0;
		
		subsets(a,n,level);
	}
}