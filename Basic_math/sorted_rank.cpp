#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll mod = 1000003;
int main()
{
	ll fact[10001] = {0};
	// memset(fact,0,10001);
	fact[0] = 1;
	fact[1] = 1;
	for(int i=2;i<=1001;i++)
		fact[i] = (fact[i-1]%mod * i%mod)%mod;

	string s;
	cin>>s;
	string temp = s;
	string temp2 = s;
	int n = s.length();
	sort(temp.begin(),temp.end());
	sort(temp2.begin(),temp2.end());

	cout<<temp<<endl;
	int c = 1;
	while(next_permutation(temp.begin(),temp.end()))
	{
		c++;
		cout<<temp<<endl;
		if(temp == s)
		{
			cout<<c<<endl;
			break;
		}
	}

	ll sum = 0;
	int m = n-1;
	int flag[n]={0};
	for(int i=0;i<n;i++)
	{
		int pos;
		int c = 0;
		for(int j=0;j<n;j++)
		{
			if(temp2[j]==s[i])
			{
				flag[j]=1;
				break;
			}
			if(flag[j]==0)
				c++;
			
		}
		pos = c;
		if(pos == 0)
		{
			sum = (sum + (1%mod*fact[m]%mod)%mod)%mod;
			break;
		}
		sum = (sum + (pos%mod*fact[m]%mod)%mod)%mod;
		m--;
	}
	cout<<sum<<endl;
}