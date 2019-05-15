// return vector of indices which are anagrams
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<string> s;
	for(int i=0;i<n;i++)
	{
		string x;
		cin>>x;
		s.push_back(x);
	}
	map<string,vector<int> > mp;
	for(int i=0;i<n;i++)
	{
		string x = s[i];
		sort(x.begin(),x.end());
		mp[x].push_back(i+1);
	}

	map<string,vector<int> >::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		vector<int> temp = it->second;
		cout<<(it->first)<<" : ";
		for(int j=0;j<temp.size();j++)
			cout<<temp[j]<<" ";
		cout<<endl;
	}
}