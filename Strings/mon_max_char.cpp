#include<bits/stdc++.h>
using namespace std;
int bin_search_f(vector<int> v,int k)
{
	int l=0;
	int r=v.size()-1;
	int ans=-1;
	while(l<=r)
	{
		// cout<<ans<<endl;
		int mid=(l+r)/2;
		if(v[mid]>=k)
		{
			ans=mid;
			r=mid-1;
		}
		else 
		{
			l=mid+1;
		}
	}
	// cout<<"ans "<<ans<<endl;
	return ans;

}
int bin_search_l(vector<int> v,int k)
{
	int l=0;
	int r=v.size()-1;
	int ans=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(v[mid]<=k)
		{
			ans=mid;
			l=mid+1;
		}
		else 
		{
			r=mid-1;
		}
	}
	// cout<<"ans "<<ans<<endl;
	return ans;

}
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int t;
	cin>>t;
	for(int i=0;i<n;i++)
	{
		if(s[i]>=65 and s[i]<=90)
		{
			s[i]=(char)((int)s[i]+32);
		}
	}
	map<char,vector<int> > v;
	for(int i=0;i<n;i++)
	{
		v[s[i]].push_back(i);
	}
	// for(auto it=v.begin();it!=v.end();it++)
	// {
	// 	// cout<<it->first<<" ";
	// 	for(int i=0;i<it->second.size();i++)
	// 	{
	// 		cout<<it->second[i]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	vector<char> pre;
	vector<char> post;
	int m=INT_MIN;
	char c;
	for(int i=0;i<n;i++)
	{
		if((int)s[i]>m)
		{
			m=(int)s[i];
			c=s[i];
		}
		pre.push_back(c);
	}
	m=INT_MIN;
	for(int i=n-1;i>=0;i--)
	{

		if((int)s[i]>m)
		{
			m=(int)s[i];
			c=s[i];
		}
		post.push_back(c);
	}
	reverse(post.begin(),post.end());
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<pre[i];
	// }
	// cout<<endl;
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<post[i];
	// }
	// cout<<endl;

	while(t--)
	{
		int x,y;
		cin>>x>>y;
		int c=0;
		int m=INT_MIN;
		char k=min(pre[y],post[x]);
		// cout<<"k "<<k<<endl;
		auto it=v.find(k);
		int l=bin_search_f(it->second,x);
		int r=bin_search_l(it->second,y);
		// cout<<"l "<<l<<" r "<<r<<endl;
		int ans=0;
		if(l!=-1 and r!=-1)
		{
			ans=r-l+1;
		}
		cout<<ans<<endl;

	}
}