#include<bits/stdc++.h>
using namespace std;


int c;
set<string> s;
int isPerfect(int n)
{
	int ans = -1;
	
	for(int i=1;i<=sqrt(n);i++)
	{
		if(i*i == n)
		{
			ans = 1;
			break;
		}
	}
	if(ans == 1)
		return 1;
	return 0;
}
void squareful(int a[],int n,int level)
{
	if(level == n)
	{
		string st = "";
		for(int i=0;i<n;i++)
		{
			st += to_string(a[i])+'|';
		}

		if(s.find(st)==s.end())
		{
			// cout<<st<<endl;
			int is_square =0;
			for(int i=1;i<n;i++)
			{
				if(isPerfect(a[i]+a[i-1])==0)
				{
					is_square = 1;
					break;
				}
			}
			if(is_square==0)
				c++;
			s.insert(st);
		}
		
	}
	for(int i=level;i<n;i++)
	{
		// swap1;
		int t = a[level];
		a[level] = a[i];
		a[i] = t;

		squareful(a,n,level+1);

		// swap back to make original array for next branch
		t = a[level];
		a[level] = a[i];
		a[i] = t;
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	c=0;
	s.erase(s.begin(),s.end());
	squareful(a,n,0);
	cout<<c<<endl;
}