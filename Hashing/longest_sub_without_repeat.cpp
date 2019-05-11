#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int len = s.length();
	int l = 0,r=0;
	int f[260] = {0};
	f[s[0]%260]++;
	int ans = -1;
	int xl,xr;
	while(l<=r && r<len)
	{
		int flag = 0;
		for(int i=0;i<260;i++)
		{
			if(f[i]>1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			f[s[l]%260]--;
			l++;
		}
		else
		{
			if((r-l+1)>ans)
			{
				ans = r-l+1;
				xl = l;
				xr = r;
			}
			r++;
			f[s[r]%260]++;
		}
	} 
	cout<<ans<<endl;
	for(int i=xl;i<=xr;i++)
		cout<<s[i];
	cout<<endl;
}