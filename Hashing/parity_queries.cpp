// long question. Read at interview Bit
// solution by @pruvi007

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int q;
	cin>>q;
	map<int,int> mp;
	while(q--)
	{
		char x;
		string n;
		cin>>x>>n;
		if(x=='+')
		{
			string bin="";
			for(int i=0;i<n.length();i++)
			{
				int d = n[i]-'0';
				if(d%2==0)
					bin+='0';
				else bin+='1';
			}
			int num=0;
			int m = 1;
			for(int i=bin.length()-1;i>=0;i--)
			{
				if(bin[i]=='1')
					num += m;
				m *=2;
			}
			mp[num]++;
		}
		else if(x=='-')
		{
			string bin="";
			for(int i=0;i<n.length();i++)
			{
				int d = n[i]-'0';
				if(d%2==0)
					bin+='0';
				else bin+='1';
			}
			int num=0;
			int m = 1;
			for(int i=bin.length()-1;i>=0;i--)
			{
				if(bin[i]=='1')
					num += m;
				m *=2;
			}
			mp[num]--;
		}
		else if(x=='?')
		{
			int num=0;
			int m = 1;
			for(int i=n.length()-1;i>=0;i--)
			{
				if(n[i]=='1')
					num += m;
				m *=2;
			}
			cout<<mp[num]<<endl;
		}
	}
}