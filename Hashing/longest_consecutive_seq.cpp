/* given an array find the longest consecutive sequence from the array.. just extract numbers which forms lpngest consecutive seq.*/
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	map<int,int> mp;
	for(int i=0;i<n;i++)
	{
		if(mp.find(a[i])==mp.end())
		{
			mp[a[i]]++;
		}
		
	}
	map<int,int>::iterator it,it2;
	// for(it=mp.begin();it!=mp.end();it++)
	// 	cout<<(it->first)<<" "<<(it->second)<<endl;
	int max = 0;
	it2=mp.begin();
	int c = 1;
	it = mp.begin();
	advance(it,1);
	for(;it!=mp.end();it++)
	{
		if(abs(it->first - it2->first) == 1)
		{
			cout<<it2->first<<" "<<it->first<<endl;
			c++;
			advance(it2,1);
		}
		else
		{
			if(c>max)
				max = c;
			c=1;
			advance(it2,1);
		}

	}
	if(c>max)
		max = c;
	cout<<max<<endl;

}